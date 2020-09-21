/*
 * spmat.c
 *
 *  Created on: 14 במאי 2020
 *      Author: HP
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "spmat.h"

int M = 0;

typedef struct Array{
		double *values;
		int *colind, *rowptr;

	} array;



typedef struct element{
			double value;
			int colind;
			struct element *next;
		}element;


void add_row_arr (struct _spmat *A, const int *row, int i, int j) {
	static int cnt = 0;
	int place, inner;
	array *x;

	inner = 0;
	x = (array*)A->private;
	if (i == 0){
		*(x->rowptr) = 0;
	}
	for (place = 0; place < j; place++) {
			*((x->values)+cnt) = 1;
			*((x->colind)+cnt) = *(row+place);
			cnt++;
			inner++;

	}
	*((x->rowptr) + (i+1)) = (*((x->rowptr) + i)) + inner;
}

void free_arr(struct _spmat *A){
	array *ar;

	ar =  (array*) A->private;
	free(ar->colind);
	free(ar->values);
	free(ar->rowptr);
	free (A->private);
}

void mult_arr(const struct _spmat *A, const double *v, double *result) {
	int num, *rowStart, *rowEnd, run, NZ;
	array *x;
	double *row, sum;

	x = (array*)(A->private);
	NZ = 0;
	rowStart = (x->rowptr);
	for (row = result; row < result+(A->n); row++) {
		sum = 0;
		rowEnd = rowStart + 1;
		run = *(rowEnd) - *(rowStart);
		for (num = 0; num < run; num++) {
			sum += *((x->values) + NZ) * *(v + *((x->colind) + NZ));
			NZ++;
		}
		*(row) = sum;
		rowStart = rowEnd;
	}

}

spmat* spmat_allocate_array(int n, int nnz) {
	spmat *p;
	array *arr;

	arr = malloc(sizeof(array));
	arr->values = calloc(nnz, sizeof(double));
	arr->colind = calloc(nnz, sizeof(int));
	arr->rowptr = calloc(n+1, sizeof(int));
	*((arr->rowptr)+n) = nnz;
	p = malloc(sizeof(spmat));

	p->add_row = &add_row_arr;
	p->free = &free_arr;
	p->mult = &mult_arr;
	p->private = arr;
	p->n = n;

	return p;
}

void spmat_print(spmat *A, int i){
	array* arr;
	int j, tmp;
	arr = (array*) A->private;
	printf("values are \n");
	for (j=0; j<i; j++){
		tmp = *((arr->values) + j);
		printf("%d \n", tmp);
	}
	printf("colinds are \n");
	for (j=0; j<i; j++){
			tmp = *((arr->colind) + j);
			printf("%d \n", tmp);
	}
	printf("rowptrs are \n");
		for (j=0; j<(i+1); j++){
				tmp = *((arr->rowptr) + j);
				printf("%d \n", tmp);
		}
}

int spmat_get_value(spmat *A, int i, int j){
	array* arr;
	int range, start, finish,*run;;


	arr = (array*) A->private;
	start = *(arr->rowptr + i);
	finish = *(arr->rowptr + i + 1);
	range = finish - start;
	for (run = arr->colind; run<arr->colind+range; run++){
		if (*(start + run) == j){
			return 1;
		}
		if (*(start + run) > j){
			return 0;
		}
	}
	return 0;
}





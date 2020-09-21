/*
 * inputRead.c
 *
 *  Created on: 15 Aug 2020
 *      Author: HP PC
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "spmat.h"

spmat* inputRead(FILE *in,int n, int *vec, int *M){
	spmat *res;
	int tmpArr[1], m, nnz, rank, vertex;
	int *row;

	fread(tmpArr, sizeof(int), 1, in);
	*M = 0;
	m = n;
	nnz = 0;
	while((fread(tmpArr, sizeof(int), 1, in)) != 0){		/* calculates how many non zeros are in A */
		nnz++;
	}
	nnz = nnz-m;
	res = (spmat_allocate_array(m, nnz));			/* allocates an spmat according to m and nnz */
	rewind(in);
	fread(tmpArr, sizeof(int), 1, in);				/* returns to the beginning of input, before rank of v0 */
	for (vertex=0; vertex<m; vertex++){
		fread(tmpArr, sizeof(int), 1, in);
		rank = tmpArr[0];
		*(vec + vertex) = rank;						/* filling rank vector */
		*M += rank;									/* calculates M */
		row = calloc(rank, sizeof(int));
		fread(row, sizeof(int), rank, in);
		res->add_row(res, row, vertex, rank);		/* adding the neighbors of vertex i to spmat */
		free(row);
	}

	return res;
}

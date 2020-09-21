/*
 * matrixOps.c
 *
 *  Created on: 19 Aug 2020
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

double dotProduct(int sizeG, int *v1, double *v2){
	double res, *num1;
	int *num;

	res = 0;
	for (num = v1, num1 = v2; num<v1+sizeG; num++,num1++){
		res += *(num) * *(num1);
	}
	return res;
}

double dotProduct2(int sizeG, double *v1, double *v2){
	double res, *num, *num1;

	res = 0;
	for (num = v1, num1 = v2; num<v1+sizeG; num++,num1++){
			res += *(num) * *(num1);
		}

	return res;
}


void multRank(int *tmpVec, int sizeG, double *u, double *res){
	int  *num1;
	double tmp, one, *num;

	one = 1.0;

	tmp = dotProduct(sizeG, tmpVec, u);
	for(num = res, num1 = tmpVec; num<res+sizeG; num++,num1++){			/* function to compute D*v */
		*(num) = *(num1) * (one/M) * tmp;
	}

	return;
}

void normalizeVec(int sizeG, double *res, double *vec){
	double *num;

	for (num = vec; num < vec+sizeG; num++) {
					*res += *(num)**(num);
				}
				*res = sqrt(*res);						/* function for vector normalisation */

				for (num = vec; num < vec+sizeG; num++) {
					*(num) = *(num)/(*res);
				}
}


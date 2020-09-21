/*
 * matVecMult.c
 *
 *  Created on: 14 Sep 2020
 *      Author: HP PC
 */

#include "spmat.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "multDiag.h"
#include "mix.h"
#include "matrixOps.h"

void mult(spmat *A, double *vec, double *f, int sizeG, int *g, int *smallDegVec, double *C, int n, double *res,
		double *Au, double *fu, double *Cu, double *Du,double *vecExpanded, double *shortVec){
	double *num;
	int *num1;

	for(num = vecExpanded; num<vecExpanded+n; num++){
		*(num) = 0;		/* creating an expanded vector to multiply spmat A with */
	}
	for(num = vec, num1 = g; num<vec+sizeG; num++, num1++){
		*(vecExpanded + *(num1)) = *(num);
	}
	A->mult(A, vecExpanded, Au);
	for (num = shortVec, num1 = g; num < shortVec+sizeG; num++, num1++) {
		*(num) = *(Au + *(num1));	/* updating the result of A*v in a short vector minus the indices irrelevant to g */
	}
	multDiag(f, vec, sizeG, fu);			/* calculating f*v with matrix delta*f, which is a diagonal matrix */
	multRank(smallDegVec, sizeG, vec,Du);	/* calculating D*v */
	multDiag(C, vec, sizeG, Cu);			/* calculating C*v with matrix CI, which is a diagonal matrix */
	mix(shortVec, fu, Du, Cu, sizeG, res);	/* calculating Av - Dv - fv + Cv and storing result in res */
}

void multModMax(spmat *A, double *vec, int sizeG, double *zero1, double *zero2, int *g, int *smallDegVec, int n, double *res,
		double *Au, double *Du,double *vecExpanded, double *shortVec){
	double *num;
	int *num1;

	for(num = vecExpanded; num<vecExpanded+n; num++){
		*(num) = 0;
	}
	for(num = vec, num1 = g; num<vec+sizeG; num++,num1++){
		*(vecExpanded + *(num1)) = *(num);		/* slightly modified version of the func above for modMax */
	}
	A->mult(A, vecExpanded, Au);
	for (num = shortVec, num1 = g; num < shortVec+sizeG; num++, num1++) {
		*(num) = *(Au + *(num1));
	}
	multRank(smallDegVec, sizeG, vec,Du);
	mix(shortVec, Du, zero1, zero2, sizeG, res);
}

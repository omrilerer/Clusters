/*
 * matVecMult.h
 *
 *  Created on: 14 Sep 2020
 *      Author: HP PC
 */

#ifndef MATVECMULT_H_
#define MATVECMULT_H_

/* matrix vector multiplication functions that compute B^[g] * v */

double* mult(spmat *A, double *vec, double *f, int sizeG, int *g, int *smallDegVec, double *C, int n, double *res,
		double *Au, double *fu, double *Cu, double *Du,double *vecExpanded, double *shortVec);

void multModMax(spmat *A, double *vec, int sizeG, double *zero1, double *zero2, int *g, int *smallDegVec, int n, double *res,
		double *Au, double *Du,double *vecExpanded, double *shortVec);

#endif /* MATVECMULT_H_ */

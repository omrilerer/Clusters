/*
 * divideG.h
 *
 *  Created on: 18 баев 2020
 *      Author: HP
 */

#ifndef DIVIDEG_H_
#define DIVIDEG_H_

/* the main function that divides g into 2 if possible */

int divideG(int *g, int *g1, int *g2, spmat *A, int *degVec, int sizeG, int n, int first, int *smallDegVec, double *f, double *C, double *u, int *s,
		double *Av, double *fv, double *Cv, double *Dv, double *sDub, double *shortVec, double *zero1, double *zero2, double *BgagS,
		double *vExpanded, double *improve, int *unmoved, int *indices, double *score, double *uCurr, double *uNext, double *diffVec, double *uNextUnnormalized);

#endif /* DIVIDEG_H_ */

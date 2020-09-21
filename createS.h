/*
 * createS.h
 *
 *  Created on: 23 Aug 2020
 *      Author: HP PC
 */

#ifndef CREATES_H_
#define CREATES_H_

/* creates s according to the leading vector u after power iteration */

int createS (spmat *A, double *f, double *u, int *s, int sizeG, int *g, int *smallDegVec, double *C, int n, double *As, double *sDub, double *shortVec,
		double *fs, double *Ds, double *Cs, double *BgagS, double *sExpanded);

#endif /* CREATES_H_ */

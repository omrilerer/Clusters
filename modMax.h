/*
 * modMax.h
 *
 *  Created on: 2 Sep 2020
 *      Author: HP PC
 */

#ifndef MODMAX_H_
#define MODMAX_H_

/* performs modularity maximisation to further improve divisions */

int modMax(int *s, spmat *A, int sizeG, int *g, int *smallDegVec, int n, double *As, double *sDub, double *shortVec, double *Ds, double *zero1, double *zero2
		,double *improve, int *unmoved, int *indices, double *score, double *sDubExpanded, double *x);

#endif /* MODMAX_H_ */

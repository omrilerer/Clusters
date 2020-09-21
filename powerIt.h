/*
 * powerIt.h
 *
 *  Created on: 19 баев 2020
 *      Author: HP
 */

#ifndef POWERIT_H_
#define POWERIT_H_

/* does power iteration to find leading eigenvector */

double* powerIt(spmat *A, double *f, int sizeG, int *g, int *smallDegVec, double *eigen, double *C, int n, double *Au, double *shortVec, double *uCurr, double *uNext,
		double *fu, double *Cu, double *Du, double *diffVec, double *uCurrExpanded, double *uNextUnnormalized);

#endif /* POWERIT_H_ */

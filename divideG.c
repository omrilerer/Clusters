
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "spmat.h"
#include "shiftMat.h"
#include "computeF.h"
#include "powerIt.h"
#include "createS.h"
#include "createG1G2.h"
#include "modMax.h"

int divideG(int *g, int *g1, int *g2, spmat *A, int *degVec, int sizeG, int n, int first, int *smallDegVec, double *f, double *C, double *u, int *s,
		double *Av, double *fv, double *Cv, double *Dv, double *sDub, double *shortVec, double *zero1, double *zero2, double *BgagS,
		double *vExpanded, double *improve, int *unmoved, int *indices, double *score, double *uCurr, double *uNext, double *diffVec, double *uNextUnnormalized) {

	int num, numm, sizeg1, curG;
	double c, eigen, fCur;
	static double cStatic;

	c = 0;
	for(num = 0; num<sizeG; num++){				/* calculating sub vector of the degrees vector relevant to current g */
		curG = *(g+num);
		*(smallDegVec+num) = *(degVec + curG);
	}
	for (num = 0; num < sizeG; num++) {			/* calculating f vector */
		fCur = computeF(A, degVec, g, sizeG, *(g+num));
		*(f + num) = fCur;
	}
	if (first){
		c = shiftMat(A, degVec, f, g, sizeG, C);	/* shifting the matrix in the first division and saving the shift number for further iterations */
		cStatic = c;
	}
	else{
		for (num = 0; num<sizeG; num++){
			*(C + num) = cStatic;
		}
	}
	u = powerIt(A, f, sizeG, g, smallDegVec, &eigen, C, n, Av, shortVec, uCurr, uNext, fv, Cv, Dv, diffVec, vExpanded, uNextUnnormalized); 	/* u is the result of power iteration */
	for (numm = 0; numm < sizeG; numm++) {
		*(s+numm) = 0;
	}
	sizeg1 = createS(A, f, u,s,sizeG, g, smallDegVec, C, n, Av,sDub, shortVec, fv, Dv, Cv, BgagS, vExpanded);    /* creating s and returning sizeg1 accordingly */
	sizeg1 = modMax(s, A, sizeG, g, smallDegVec, n, Av, sDub, shortVec, Dv, zero1, zero2, improve, unmoved, indices, score, vExpanded, uNext);			/* modularity maximization */

	createG1G2(g,g1,g2,sizeG,s);								/* creating g1,g2 according to final s */



	return sizeg1;
}

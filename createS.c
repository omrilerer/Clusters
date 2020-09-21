/*
 * createS.c
 *
 *  Created on: 23 Aug 2020
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
#include "matVecMult.h"


int createS (spmat *A, double *f, double *u, int *s, int sizeG, int *g, int *smallDegVec, double *C, int n, double *As, double *sDub, double *shortVec,
		double *fs, double *Ds, double *Cs, double *BgagS, double *sExpanded){
	int run, sizeg1,  num;
	double Q;


	sizeg1 = 0;
	for (run = 0; run<sizeG; run++){			/* creates s according to the signs of vector u's values */
		if (*(u + run) > 0){
			*(s + run) = 1;
			sizeg1++;
		}
		else{
			*(s + run) = -1;

		}
	}

	for(num = 0; num<sizeG; num++){
			*(sDub+num) = (double) *(s+num);
		}

	mult(A, sDub, f, sizeG, g, smallDegVec, C, n, BgagS, As, fs, Cs, Ds,sExpanded,shortVec); /* calculating s^t * B^[g] * s and returns -1 if it's negative */
	Q = dotProduct(sizeG, s, BgagS);


	if (Q<0.0001){
		return -1;
	}
	else{
		return sizeg1;
	}

}

/*
 * multDiag.c
 *
 *  Created on: 19 баев 2020
 *      Author: HP
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


void multDiag(double *f, double *u, int sizeG, double *res) {
	double uCur, fCur;
	int num;


	for (num = 0; num < sizeG; num++) {		/* func for multiplication of diagonal matrices and vectors */
		uCur = *(u + num);
		fCur = *(f + num);
		*(res + num) = uCur * fCur;
	}
	return;
}

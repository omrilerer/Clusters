/*
 * createG1G2.c
 *
 *  Created on: 24 Aug 2020
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


void createG1G2(int *g, int *g1, int *g2, int sizeG, int *s){
	int run, i1, i2, gCurr;

	i1=0;
	i2=0;
	for (run = 0; run<sizeG; run++){
		gCurr = *(g+run);
		if (*(s+run) == 1){
			*(g1 + i1) = gCurr;			/* creates the 2 groups g is divided to and returns the size of g1 */
			i1++;
		}
		else{
			*(g2 + i2) = gCurr;
			i2++;
		}
	}
}

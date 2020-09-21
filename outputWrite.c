/*
 * outputWrite.c
 *
 *  Created on: 23 Aug 2020
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


void write (int **o, int *oSizes, int sizeO, FILE *out){
	int run, size, tmp[1], tmp2[1];


	*tmp = sizeO;
	fwrite(tmp, sizeof(int), 1, out);

	for (run = 0; run<sizeO; run++){
		size = *(oSizes + run);
		*tmp2 = size;
		fwrite(tmp2, sizeof(int), 1, out);
		fwrite(*(o + run), sizeof(int), size, out);

	}




	return;
}

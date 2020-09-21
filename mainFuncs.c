#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int checkNumOfArgs(int numOfArgs){
	if (numOfArgs != 3){
		return 0;
	}
	return 1;
}

void pInit(int **p, int n){
	int num;

	for (num = 0; num < n; num++) {
		*(*p + num) = num;
	}
}

void updateOP(int sizeg1, int sizeg2, int sizeG, int *oSize, int *pFirst, int *pLast, int *oSizes, int *pSizes,int **o, int **p,int  *g, int *g1, int *g2){
	int run = 0;

	if ((sizeg1 == 0) || (sizeg2 == 0) || (sizeg1 == -1)){
		*(o + *oSize) = calloc(sizeG,sizeof(int));
		for (run = 0; run < sizeG; run++) {
				*(*(o + *oSize)+run) = *(g+run);
		}
		*(oSizes + *oSize) = sizeG;
		*(oSize) = *(oSize) + 1;
		*(pFirst) = *(pFirst)+1;
	}
	else if (sizeg1 == 1) {
		*(o + *oSize) = calloc(sizeg1,sizeof(int));
		for (run = 0; run < sizeg1; run++) {
			*(*(o + *oSize)+run) = *(g1+run);
		}
		*(oSizes + *oSize) = sizeg1;
		*(oSize) = *(oSize) + 1;
		if (sizeg2 != 1) {
			free(*(p + *pFirst));
			*(p + *pFirst) = calloc(sizeg2,sizeof(int));
			for (run = 0; run < sizeg2; run++) {
				*(*(p + *pFirst)+run) = *(g2+run);
			}
			pSizes[*pFirst] = sizeg2;
		}
		else {
			*(o + *oSize) = calloc(sizeg2,sizeof(int));
			for (run = 0; run < sizeg2; run++) {
				*(*(o + *oSize)+run) = *(g2+run);
			}
			*(oSizes + *oSize) = sizeg2;
			*(oSize) = *(oSize) + 1;
			*(pFirst) = *(pFirst)+1;
		}
	}
		else if (sizeg2 == 1) {
			*(o + *oSize) = calloc(sizeg2,sizeof(int));
			for (run = 0; run < sizeg2; run++) {
				*(*(o + *oSize)+run) = *(g2+run);
			}
			*(oSizes + *oSize) = sizeg2;
			*(oSize) = *(oSize) + 1;
			free(*(p + *pFirst));
			*(p + *pFirst) = calloc(sizeg1,sizeof(int));
			for (run = 0; run < sizeg1; run++) {
				*(*(p + *pFirst)+run) = *(g1+run);
			}
			sizeG = sizeg1;
			pSizes[*pFirst] = sizeg1;
		}
		else {
			free(*(p + *pFirst));
			*(p + *pFirst) = calloc(sizeg1,sizeof(int));
			for (run = 0; run < sizeg1; run++) {
				*(*(p + *pFirst)+run) = *(g1+run);
			}
			*(pLast) = *(pLast) + 1;
			*(p + *pLast) = calloc(sizeg2,sizeof(int));
			for (run = 0; run < sizeg2; run++) {
				*(*(p + *pLast)+run) = *(g2+run);
			}
			pSizes[*pFirst] = sizeg1;
			pSizes[*pLast] = sizeg2;
		}
}

/*
 * computeF.c
 *
 *  Created on: 19 баев 2020
 *      Author: HP
 */

#include "spmat.h"

double computeF(spmat *A, int *degVec, int *g, int sizeG, int row){
	int run,gCurr, curRank;
	double res, ki, rankMult, Bij;

	res = 0;

	ki = (double) *(degVec + row);
	for (run = 0; run < sizeG; run++) {
		gCurr = *(g + run);
		curRank = *(degVec + gCurr);
		rankMult = ki * curRank;
		Bij = rankMult/M;
		if (spmat_get_value(A, row, gCurr)) {
			res += 1;
			res -= Bij;
		}
		else {
			res -=  Bij;
		}

	}
	if ((res<0.0001) && (res>-0.0001)){
		return 0;
	}
	return res;
}

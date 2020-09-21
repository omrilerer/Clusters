
/*
 * shiftMat.c
 *
 *  Created on: 19 Aug 2020
 *      Author: HP PC
 */

#include "spmat.h"
#include <math.h>

	double shiftMat(spmat *A, int *degVec, double *f, int *g, int sizeG, double *C){
		int row, col, num, ki, curCol, curRow, curRank;
		double tmp, Dij, maxSum, rankMult, bGag;

		maxSum = 0;
		for (col = 0; col < sizeG; col++) {
			tmp = 0;
			curCol = *(g + col);
			ki = *(degVec + curCol);
			for (row = 0; row < sizeG; row++) {
				curRow = *(g + row);
				bGag = spmat_get_value(A, curRow, curCol);
				if (curCol == curRow) {
					bGag -= *(f + curRow);
				}
				curRank = *(degVec + curRow);
				rankMult = ki*curRank;
				Dij = rankMult / M;
				bGag -= Dij;
				tmp += fabs(bGag);			/* calculating maximal column */
			}
			if ((tmp < 0.00001) && (tmp > -0.00001)) {
				tmp = 0;
			}
			if (tmp > maxSum) {
				maxSum = tmp;
			}
		}
		for (num = 0; num < sizeG; num++) {
			*(C + num) = maxSum;			/* creating a sizeG sized vector that will represent C*I matrix */
		}
		return maxSum;
	}

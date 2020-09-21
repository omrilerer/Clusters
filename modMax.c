#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "matrixOps.h"
#include "spmat.h"
#include "multDiag.h"
#include "mix.h"
#include "arrayOps.h"
#include "modMaxFuncs.h"

int modMax(int *s, spmat *A, int sizeG, int *g, int *smallDegVec, int n, double *As, double *sDub, double *shortVec, double *Ds, double *zero1, double *zero2
		,double *improve, int *unmoved, int *indices, double *score, double *sDubExpanded, double *x){
	int *num,*run,i,sizeG1 ,Aij, *num3, num5,indexOfMaxScore, j, maxImproveIndex;
	double curScore, *num2, nextScore,sTmp,sMax, deltaQ, *num1, epsilon, sDubCur;
	double maxScore,maxImprove, sDubMax, Dij, *num4,m, ki, kj, curImprove;

	epsilon = 0.0001;
	for(num = s, num2 = sDub; num<s+sizeG; num++,num2++){
		sTmp = (double) *(num);
		*(num2) = sTmp;
	}
	for (num2 = zero2, num1 = zero1; num2<zero2+sizeG; num2++, num1++){
		*(num1) = 0;
		*(num2) = 0;				/* creating zero vectors that represent f = C = 0 */
	}
	m = (double) M;
	for (num2 = sDubExpanded; num2<sDubExpanded+n; num2++){
		*(num2) = 0;
	}
do {

	for(run=unmoved; run<unmoved+sizeG; run++){
		*(run) = 1;				/* if unmoved[i] == 1 g[i] is unmoved */
	}
	for (num = g, num1 = sDub; num<g+sizeG; num++, num1++){
		*(sDubExpanded + *(num)) = *(num1);
	}
	A->mult(A, sDubExpanded, As);
	for (num2 = shortVec, num = g; num2<shortVec+sizeG; num++,num2++){	/* calculating As - Ds */
		*(num2) = *(As + *(num));
	}
	multRank(smallDegVec, sizeG, sDub, Ds);
	mix(shortVec, Ds, zero1,zero2, sizeG,x);
	scoreInit(sizeG, sDub, x, smallDegVec, m, score);		/* Initialising scores for all vertices */
	for(i=0; i<sizeG; i++){
		findMaxOfScore(score, &indexOfMaxScore, &maxScore,unmoved, sizeG);	/* finding the vertex which when moved will give max improve */
		sMax = *(sDub + indexOfMaxScore);
		*(sDub + indexOfMaxScore) = sMax *(-1);		/* move the vertex */
		*(indices + i) = indexOfMaxScore;
		if (i ==0){
			*(improve +i) = *(score+indexOfMaxScore);
		}
		else{
			curImprove = *(improve + i-1) + *(score+indexOfMaxScore);	/* updating improve array */
			*(improve +i) = curImprove;
		}
		*(unmoved+indexOfMaxScore) = 0;
			for(num5 = 0,num4 = score, num1 = sDub, num = smallDegVec,num3 = g; num1<sDub+sizeG; num1++,num++,num4++,num5++,num3++){
				sDubCur = *(num1);
				sDubMax = *(sDub+indexOfMaxScore);
				ki = (double) *(num);
				kj = (double) *(smallDegVec + indexOfMaxScore);
				Dij = (ki * kj)/m;
				Aij = spmat_get_value(A, *(num3), *(g+indexOfMaxScore));
				curScore = *(num4);
				if(num5 == indexOfMaxScore){
					*(num4) = curScore*(-1);		/* update score array according to the changed s */
				}
				else{
					nextScore = curScore - 4 * sDubCur * sDubMax * (Aij - Dij);
					*(num4) = nextScore;
				}
		}
	}
		findMaxOfImprove(improve, &maxImproveIndex, &maxImprove, sizeG);
		for (run = indices+sizeG-1; run>indices+maxImproveIndex; run--){
			j = *(run);
			sTmp = *(sDub+j);			/* moving vertices that lowered the modularity back to their previous group */
			*(sDub+j) = *(sDub+j)*(-1);
		}
		if(maxImproveIndex == sizeG-1){
			deltaQ = 0;
		}
		else{
			deltaQ = *(improve+maxImproveIndex);
		}
}
while (deltaQ > epsilon);
sizeG1 = 0;
for(num1 = sDub, num = s; num1<sDub+sizeG; num1++,num++){
	sDubCur = *(num1);
	if (sDubCur == 1){
		sizeG1++;
	}
	*(num) = (int) sDubCur;
}

return sizeG1;


}

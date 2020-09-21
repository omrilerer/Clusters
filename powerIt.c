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

double* powerIt(spmat *A, double *f, int sizeG, int *g, int *smallDegVec, double *eigen, double *C, int n, double *Au, double *shortVec, double *uCurr, double *uNext,
		double *fu, double *Cu, double *Du, double *diffVec, double *uCurrExpanded, double *uNextUnnormalized) {
	double *rnd, filler, mgntd, tmp, epsilon;
	double eigenDot1, eigenDot2, *num, *num1, *num2;
	int done, cnt;

	epsilon = 0.001;
	cnt = 0;
	done = 0;
	srand(time(0));
	for (rnd = uCurr; rnd < uCurr+sizeG; rnd++) {
		filler = rand();
		*(rnd) = filler;		/* initialising the vector we will use with random numbers */
	}
	mgntd = 0;
	normalizeVec(sizeG, &mgntd, uCurr);	/* normalising the vector */
	while (done == 0) {
		done = 1;
		cnt++;
		mult(A, uCurr, f, sizeG, g, smallDegVec, C, n, uNext, Au, fu, Cu, Du,uCurrExpanded,shortVec); /*uNext = B^[g]*uCurr */
		mgntd = 0;
		normalizeVec(sizeG, &mgntd, uNext);
		for (num = uNext, num1 = uCurr, num2 = diffVec; num1 < uCurr+sizeG; num++, num1++, num2++) {
			tmp = (fabs(*(num) - *(num1)));
			*(num2) = tmp;				/* checking the difference between bk and bk+1 */
			if (tmp > epsilon) {
				done = 0;
			}
		}
		for (num1 = uCurr, num = uNext; num1 < uCurr+sizeG; num++, num1++) {
			*(num1) = *(num);
		}
		if(cnt > n*n){
			printf("Infinite loop detected in power iteration \n");
			exit(2);
		}
	}
	for (num = uNext, num1 = uNextUnnormalized; num < uNext + sizeG; num++, num1++) {
		*(num1) = (*(num))*mgntd;
	}
	mult(A, uNextUnnormalized, f, sizeG, g, smallDegVec, C, n, uNext, Au, fu, Cu, Du,uCurrExpanded,shortVec);
	eigenDot1 = dotProduct2(sizeG, uNextUnnormalized, uNext);
	eigenDot2 = dotProduct2(sizeG, uNextUnnormalized, uNextUnnormalized);		/* calculating leading eigenvalue */
	if (eigenDot2 > -0.0001 && eigenDot2 < 0.0001){
		printf("division by 0 detected ");
		exit(4);
	}
	*eigen = eigenDot1/eigenDot2;
	return uNext;
}

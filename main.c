#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "spmat.h"
#include "inputRead.h"
#include "createG.h"
#include "divideG.h"
#include "outputWrite.h"
#include "modMax.h"
#include "mainFuncs.h"

int main(int argc, char* argv[]) {
	extern int M;
	spmat *A;
	int n,*rowVec, **p, **o, sizeG, *oSizes, tmpArr[1],*s, *smallDegVec, fr,firstDivision,pFirst, pLast, oSize, sizeOfP, *indices, *unmoved, *g, *g1, *g2, sizeg1, sizeg2, *pSizes;
	double *f, *C, *u, *Av, *shortVec, *sDub, *fv, *Cv, *Dv, *diffVec, *zero1, *zero2, *vExpanded, *bGagS, *score, *improve, *uCurr, *uNext, *uNextUnnormalized;
	FILE *input, *output;

	if (checkNumOfArgs(argc) != 1){
		printf("invalid number of arguments \n");
		exit(4);
	}
	pFirst = 0;
	pLast = 0;
	oSize = 0;
	sizeOfP = pLast - pFirst + 1;
	firstDivision = 1;
	input = fopen(argv[1], "r");                       /* remember to make sure input is not null */
	if (input == NULL){
		printf("File not found \n");
		exit(4);
	}
	fread(tmpArr, sizeof(int), 1, input);
	n = tmpArr[0];
	rewind(input);
	rowVec = calloc(n, sizeof(int));

	smallDegVec = calloc(n,sizeof(int));
	f = calloc(n,sizeof(double));
	C = calloc(n,sizeof(double));
	u = calloc(n,sizeof(double));
	s = calloc(n,sizeof(int));
	Av = calloc(n,sizeof(double));
	fv = calloc(n,sizeof(double));
	Cv = calloc(n,sizeof(double));
	Dv = calloc(n,sizeof(double));
	sDub = calloc(n,sizeof(double));
	shortVec = calloc(n,sizeof(double));
	zero1 = calloc(n,sizeof(double));
	zero2 = calloc(n,sizeof(double));
	bGagS = calloc(n,sizeof(double));
	vExpanded = calloc(n,sizeof(double));
	improve = calloc(n,sizeof(double));
	unmoved = calloc(n,sizeof(int));
	indices = calloc(n,sizeof(int));
	score = calloc(n,sizeof(double));
	uCurr = calloc(n,sizeof(double));
	uNext = calloc(n,sizeof(double));
	diffVec = calloc(n,sizeof(double));
	uNextUnnormalized = calloc(n,sizeof(double));

	A = inputRead(input,n, rowVec, &M);                  /* Updating rowVec while building spmat A, updating n inside in */
	if (M == 0) {
		printf("no edges in graph \n");
		exit(4);
	}
	p = calloc(n, sizeof(int*));
	pSizes = calloc(n, sizeof(int));
	*p = calloc(n, sizeof(int));
	pInit(p, n);
	pSizes[0] = n;
	o = calloc(n, sizeof(int*));
	oSizes = calloc(n, sizeof(int));
	while (sizeOfP != 0) {
		sizeG = pSizes[pFirst];
		g = createG(p, pFirst);                          /* Copies a group in p to g */
		g1 = calloc(sizeG,sizeof(int));
		g2 = calloc(sizeG,sizeof(int));
		sizeg1 = divideG(g, g1, g2, A, rowVec, sizeG, n, firstDivision,
				smallDegVec, f, C, u, s, Av, fv, Cv, Dv, sDub, shortVec,
				zero1, zero2, bGagS, vExpanded, improve, indices, unmoved, score, uCurr, uNext,
				diffVec, uNextUnnormalized);                      /* Receives 3 dynamic allocations, and divides g to 2 */
		firstDivision = 0;
		sizeg2 = sizeG - sizeg1;
		updateOP(sizeg1, sizeg2, sizeG, &oSize, &pFirst, &pLast, oSizes, pSizes, o, p, g, g1, g2);   /* updating O and P */
			free(g1);
			free(g2);
			sizeOfP = pLast - pFirst + 1;
		}
		output = fopen(argv[2], "w");
		write(o, oSizes, oSize, output);
		fclose(input);
		fclose(output);

		for (fr = 0; fr <= pLast; fr++) {
			free(*(p + fr));
		}
		for (fr = 0; fr < oSize; fr++) {
			free(*(o + fr));
		}

		free(smallDegVec);
		free(f);
		free(C);
		free(u);
		free(s);
		free(Av);
		free(fv);
		free(Cv);
		free(Dv);
		free(sDub);
		free(shortVec);
		free(zero1);
		free(zero2);
		free(bGagS);
		free(vExpanded);
		free(improve);
		free(indices);
		free(unmoved);
		free(score);
		free(uCurr);
		free(uNext);
		free(diffVec);
		free(uNextUnnormalized);
		free(rowVec);
		free(p);
		free(pSizes);
		free(o);
		free(oSizes);

		A->free(A);
		free(A);
		return 0;
	}

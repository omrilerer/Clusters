

#ifndef MAINFUNCS_H_
#define MAINFUNCS_H_

/* functions used by main function */

int checkNumOfArgs(int numOfArgs);	/* checks that the arguments are valid */

void pInit(int **p, int n); /* initialises P with a trivial division */

void updateOP(int sizeg1, int sizeg2, int sizeG, int *oSize, int *pFirst, int *pLast, int *oSizes, int *pSizes,int **o, int **p,int *g, int *g1, int *g2); /* updates O and P according to the division of g */

#endif /* MAINFUNCS_H_ */

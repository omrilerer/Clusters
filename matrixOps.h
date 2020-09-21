#ifndef MATRIXOPS_H_
#define MATRIXOPS_H_

/* functions that manipulate vectors and matrices */

void multRank(int *tmpVec, int sizeG, double *u, double *res);

double dotProduct(int sizeG, int *v1, double *v2);

double dotProduct2(int sizeG, double *v1, double *v2);

void normalizeVec(int sizeG, double *res, double *vec);


#endif /* MATRIXOPS_H_ */

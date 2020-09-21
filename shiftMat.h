/*
 * shiftMat.h
 *
 *  Created on: 19 Aug 2020
 *      Author: HP PC
 */

#ifndef SHIFTMAT_H_
#define SHIFTMAT_H_

/* computes the maximal column of matrix B^[g] */

double shiftMat(spmat *A, int *vec, double *f, int *g, int sizeG, double *c);


#endif /* SHIFTMAT_H_ */

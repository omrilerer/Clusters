/*
 * arrayOps.h
 *
 *  Created on: 13 Sep 2020
 *      Author: HP PC
 */

#ifndef ARRAYOPS_H_
#define ARRAYOPS_H_

/* finds maximum of different kinds of arrays */

void findMaxOfInts(int *arr, int *indexOfMax, int *max, int *unmoved, int sizeG);

void findMaxOfScore(double *arr, int *indexOfMax, double *max, int *unmoved, int sizeG);

void findMaxOfImprove(double *arr, int *indexOfMax, double *max, int sizeG);

#endif /* ARRAYOPS_H_ */

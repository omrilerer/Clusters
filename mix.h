/*
 * mix.h
 *
 *  Created on: 19 баев 2020
 *      Author: HP
 */

#ifndef MIX_H_
#define MIX_H_

/* a function that computes (A - D - f + CI) * v */

void mix(double *Au, double *Du, double *fu, double *cu, int sizeG, double *res);

#endif /* MIX_H_ */

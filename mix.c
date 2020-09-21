

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SPBufferset.h"
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>



void mix(double *Au, double *Du, double *fu, double *cu, int sizeG, double *res) { /* computes Au - Du - fu + Cu */
	double AuCur, DuCur, fuCur, cuCur, *num1,*num2,*num3,*num4,*num5;

	for (num1 = Au, num2 = Du, num3 = fu, num4 = cu, num5 = res; num1 < Au+sizeG; num1++,num2++,num3++,num4++,num5++) {
		AuCur = *(num1);
		DuCur = *(num2);
		fuCur = *(num3);
		cuCur = *(num4);
		*(num5) = AuCur - DuCur - fuCur + cuCur;
	}


	return;
}

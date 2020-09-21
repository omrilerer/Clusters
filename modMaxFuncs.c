void scoreInit(int sizeG, double *sDub, double *x, int *smallDegVec, double m, double *score){
	int *num, ki;
	double si, tmp,xi, *num1, *num2, *num3;

	for(num = smallDegVec, num1 = x, num2 = sDub, num3 = score; num<smallDegVec+sizeG; num++, num1++,num2++,num3++){
		si = *(num2);
		xi = *(num1);
		ki = (double) *(num);
		tmp = (ki * ki)/m;
		*(num3) = -2*(xi*si + tmp);
	}
}

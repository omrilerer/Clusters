void findMaxOfInts(int *arr, int *indexOfMax, int *max, int *unmoved, int sizeG){
	int first, maxInd,j, maximum;

	maxInd = 0;
	maximum = 0;
	first = 1;
	for(j=0; j<sizeG; j++){
		if (*(unmoved + j) == 1){
			if (first){
				first = 0;
				maximum = *(arr + j);			/* 3 funcs aimed to find max of different arrays */
				maxInd = j;
			}
			else{
				if (maximum<*(arr + j)){
					maximum = *(arr + j);
					maxInd = j;
				}
			}
		}
	}
	*indexOfMax = maxInd;
	*max = maximum;
}

void findMaxOfScore(double *arr, int *indexOfMax, double *max, int *unmoved, int sizeG){
	int first, maxInd,j;
	double maximum;

	maxInd = 0;
	maximum = 0;
	first = 1;
	for(j=0; j<sizeG; j++){
		if (*(unmoved + j) == 1){
			if (first){
				first = 0;
				maximum = *(arr + j);
				maxInd = j;
			}
			else{
				if (maximum<*(arr + j)){
					maximum = *(arr + j);
					maxInd = j;
				}
			}
		}

	}
		*indexOfMax = maxInd;
		*max = maximum;
}

void findMaxOfImprove(double *arr, int *indexOfMax, double *max, int sizeG){
	int first, maxInd,j;
	double maximum;

	maxInd = 0;
	maximum = 0;
	first = 1;
	for(j=0; j<sizeG; j++){
		if (first){
			first = 0;
			maximum = *(arr + j);
			maxInd = j;
		}
		else{
			if (maximum<*(arr + j)){
				maximum = *(arr + j);
				maxInd = j;
			}
		}
	}
	*indexOfMax = maxInd;
	*max = maximum;
}




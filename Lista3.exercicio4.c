#include<stdio.h>
int divs(int n, int *pmax, int *min){
	int contMin, contMax, var=0;
	if(n <= 1){
		return 1;
	}
	contMax=n-1;
	for (contMin = 2; contMin*contMin <= n; contMin++) {
		if (n%contMin == 0){   // d divide n
       		*min = contMin;
       		for(contMax=2; contMax<n;contMax++){
       			if(n%contMax==0){
       				var=contMax;
				   }
			   }
			*pmax=var;
       		return 1;
    	}
	}
	return 0;
}
int main(){
	int num, max,min, fun;
	
	scanf("%d", &num);
	
	fun = divs(num,&max, &min);
	
	printf("Fun: %d\nMax: %d\nMin: %d",fun, max, min);
	
	return 0;
}

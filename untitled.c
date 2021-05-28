#include <stdio.h>

int main(void){
	int i,j;
	int L=3;
	for (i=0; i<L; i++){
		for (j=0; j<L; j++){
			printf("[%d %d] [%d %d] [%d %d] [%d %d] [%d %d] \n",i,j, i-1,j, i+1,j, i,j-1,i, j+1);
			printf("[%d %d] [%d %d] [%d %d] [%d %d] [%d %d] \n",i,j, i,(j-1+L)%L,i, (j+1)%L,(i-1 + L)%L,j, (i+1)%L,j);
		}				
	}


	return 0;
}
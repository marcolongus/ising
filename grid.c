#include "ising.h"
#include "params.h"
#include "wtime.h"

#include <stdio.h>
#include <limits.h> // UINT_MAX
#include <math.h> // expf()
#include <stdlib.h> // rand()
#include <time.h> // time()

#define SEED (time(NULL)) // random seed

static void init_grid(int grid[L][S]);


int main(void){


	int red[L][S]={{0}},
		black[L][S]={{0}};
	init_grid(red); init_grid(black);


	for (int i=0; i<L ;i++){
		for (int j=0; j<S; j++){
			printf(" %2i ", red[i][j]);
		}
		printf("\n");
	}

	printf("\n");

    srand(SEED);

    float temp = 100;
    float calcExp[3];
    calcExp[0] = 1;
    calcExp[1] = expf(-4/ temp);
    calcExp[2] = expf(-8/ temp);

	update(calcExp, black, red);

	for (int i=0; i<L ;i++){
		for (int j=0; j<S; j++){
			printf(" %2i ", red[i][j]);
		}
		printf("\n");
	}


	return 0;
}


static void init_grid(int grid[L][S])
{
    for (unsigned int i = 0; i < L; ++i) {
        for (unsigned int j = 0; j < S; ++j) {
            grid[i][j] = 1;
        }
    }
}
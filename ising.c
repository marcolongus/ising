#include "ising.h"
#include <math.h>
#include <stdlib.h>



void update(float  calcExp[3], int red[L][S], int black[L][S])
{    
    //black back rule
    for (unsigned int i = 0; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            
            int spin_old = black[i][j];
            int spin_new = (-1) * spin_old;

            int spin_neigh_n = red[(i+1)%L][j];
            int spin_neigh_e = red[i][j];
            int spin_neigh_w = red[i][(j + S - 1) % S];
            int spin_neigh_s = red[(i-1)%L][j];


            int delta_E = 2 * spin_old * (spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            if ( delta_E <= 0 || rand() / (float)RAND_MAX <= calcExp[abs(delta_E)/4]) {
                black[i][j] = spin_new;
            }
        }
    }

    //black foward rule
    for (unsigned int i = 1; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            
            //printf("%d %d \n",i,j);

            int spin_old = black[i][j];
            int spin_new = (-1) * spin_old;

            int spin_neigh_n = red[(i+1)%L][j];
            //printf("(%d,%d) ",(i+1)%L,j);
            int spin_neigh_e = red[i][(j+ S +1) % S];
            //printf("(%d,%d) ",i,(j + S + 1) % S);
            int spin_neigh_w = red[i][j];
            //printf("(%d,%d) ",i,j);
            int spin_neigh_s = red[(i-1)%L][j];
            //printf("(%d,%d) ",(i-1)%L,j);


            int delta_E = 2 * spin_old * (spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            if ( delta_E <= 0 || rand() / (float)RAND_MAX <= calcExp[abs(delta_E)/4]) {
                black[i][j] = spin_new;
            }
            //printf("\n");
        }
    }

    //red foward rule
    for (unsigned int i = 0; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            
            int spin_old = black[i][j];
            int spin_new = (-1) * spin_old;

            int spin_neigh_n = black[(i+1)%L][j];
            int spin_neigh_e = black[i][(j + S + 1) % S];
            int spin_neigh_w = black[i][j];
            int spin_neigh_s = black[(i-1)%L][j];


            int delta_E = 2 * spin_old * (spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            if ( delta_E <= 0 || rand() / (float)RAND_MAX <= calcExp[abs(delta_E)/4]) {
                black[i][j] = spin_new;
            }
        }
    }
    //red back rule
    for (unsigned int i = 1; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            
            int spin_old = red[i][j];
            int spin_new = (-1) * spin_old;

            int spin_neigh_n = black[(i+1)%L][j];
            int spin_neigh_e = black[i][j];
            int spin_neigh_w = black[i][(j + S - 1) % S];
            int spin_neigh_s = black[(i-1)%L][j];


            int delta_E = 2 * spin_old * (spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            if ( delta_E <= 0 || rand() / (float)RAND_MAX <= calcExp[abs(delta_E)/4]) {
                red[i][j] = spin_new;
            }
        }
    }

}


double calculate(int red[L][S],int black[L][S], int* M_max)
{
    int E = 0;

    //black back rule
    for (unsigned int i = 0; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            int spin_neigh_n = red[(i+1)%L][j];
            int spin_neigh_e = red[i][j];
            int spin_neigh_w = red[i][(j + S - 1) % S];
            int spin_neigh_s = red[(i-1)%L][j];
             
             E+= black[i][j]*(spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            *M_max += black[i][j];
        }
    }
    //black foward rule
    for (unsigned int i = 1; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            
            int spin_neigh_n = red[(i+1)%L][j];
            int spin_neigh_e = red[i][(j + S + 1) % S];
            int spin_neigh_w = red[i][j];
            int spin_neigh_s = red[(i-1)%L][j];

             E+= black[i][j]*(spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            *M_max += black[i][j];
        }
    }
    //red foward rule
    for (unsigned int i = 0; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            
            int spin_neigh_n = black[(i+1)%L][j];
            int spin_neigh_e = black[i][(j + S + 1) % S];
            int spin_neigh_w = black[i][j];
            int spin_neigh_s = black[(i-1)%L][j];

             E+= red[i][j]*(spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            *M_max += red[i][j];
        }
    }
    //red back rule
    for (unsigned int i = 1; i < L; i+=2) {
        for (unsigned int j = 0; j < S; ++j) {
            
            int spin_neigh_n = black[(i+1)%L][j];
            int spin_neigh_e = black[i][j];
            int spin_neigh_w = black[i][(j + S - 1) % S];
            int spin_neigh_s = black[(i-1)%L][j];

             E+= red[i][j]*(spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            *M_max += red[i][j];

        }
    }


    return -((double)E / 2.0);
}



    
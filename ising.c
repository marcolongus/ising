#include "ising.h"
#include <math.h>
#include <stdlib.h>

void update(const float temp, int grid[L][L])
{
    float calcExp[3];
    calcExp[0]=1;
    calcExp[1]=expf(-4/ temp);
    calcExp[2]=expf(-8/ temp);
    
    
    for (unsigned int i = 0; i < L; ++i) {
        for (unsigned int j = 0; j < L; ++j) {
            
            int spin_old = grid[i][j];
            int spin_new = (-1) * spin_old;

            int spin_neigh_n = grid[(i + L - 1) % L][j];
            int spin_neigh_e = grid[i][(j + 1) % L];
            int spin_neigh_w = grid[i][(j + L - 1) % L];
            int spin_neigh_s = grid[(i + 1) % L][j];


            int delta_E = 2 * spin_old * (spin_neigh_n +  spin_neigh_e +  spin_neigh_w + spin_neigh_s);
            if ( delta_E <= 0 || rand() / (float)RAND_MAX <= calcExp[abs(delta_E)/4]) {
                grid[i][j] = spin_new;
            }
        }
    }
}


double calculate(int grid[L][L], int* M_max)
{
    int E = 0;
    for (unsigned int i = 0; i < L; ++i) {
        for (unsigned int j = 0; j < L; ++j) {

            E += grid[i][j]*(grid[(i + 1) % L][j]+  grid[i][(j + 1) % L]+  grid[i][(j + L - 1) % L] + grid[(i + L - 1) % L][j]);

            *M_max += grid[i][j];
        }
    }
    return -((double)E / 2.0);
}


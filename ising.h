#include "params.h"

static idx(size_t x, size_t y);
void update_rb();
void update_b();
void update(const float temp, int red[L][S], int black[L][S]);
double calculate(int red[L][S],int black[L][S], int* M_max);

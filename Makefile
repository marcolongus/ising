CC        = gcc
CFLAGS    = -std=c11 -Wall -Wextra  -O3 -march=native -ftree-vectorize -fopt-info-vec -fopt-info-vec-missed 
LDFLAGS   = -lm


# Files
TARGETS=tiny_ising grid

# Rules
all: $(TARGETS)

tiny_ising: tiny_ising.o ising.o wtime.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

grid: grid.o ising.o wtime.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o

.PHONY: clean all


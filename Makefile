CC        = gcc
CFLAGS    = -std=c11 -Wall -Wextra -march=native 
LDFLAGS   = -lm

# Files
TARGETS=for_openmp

# Rules
all: $(TARGETS)

for_openmp: for_openmp.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


clean:
	rm -f $(TARGETS) *.o

.PHONY: clean all
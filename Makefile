CC        = gcc
CFLAGS    = -std=c11 -Wall -Wextra -march=native 
LDFLAGS   = -lm

# Files
TARGETS=tiny_ising_rb

# Rules
all: $(TARGETS)

tiny_ising_rb: tiny_ising_rb.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


clean:
	rm -f $(TARGETS) *.o

.PHONY: clean all
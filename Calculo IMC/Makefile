GCC = g++
GFLAGS = -std=c++11
PROGS = IMC_modulo ejecutable

all: $(PROGS)

IMC_modulo:
	$(GCC) $(GFLAGS) -c $@.cpp
	$(GCC) $(GFLAGS) -c IMC_principal.cpp
	$(GCC) $(GFLAGS) -o ejecutable $@.o IMC_principal.o
	
clean:
	$(RM) *.o $(PROGS)
	
	

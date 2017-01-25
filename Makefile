# Compilation begins.
FONTES=$(wildcard *.cpp)
OBJECTS1=$(FONTES:.cpp=.o)
OBJECTS2=$(FONTES:.cpp=.o_sse)
FLAGS1=-DLIKWID_PERFMON -llikwid -O3 -march=native -msse2 -msse3 -DHAVE_SSE2 -std=c++11
FLAGS2=-DLIKWID_PERFMON -llikwid -O3 -march=native -msse2 -msse3 -std=c++11 -D__USE_SIMD__=1

.PHONY: all clean

all: montecarlo montecarlo_simd

montecarlo: $(OBJECTS1)
	g++ -o $@ $^ -llikwid -L/usr/lib -L/home/soft/likwid/lib $(FLAGS1)

montecarlo_simd: $(OBJECTS2)
	g++ -o $@ $^ -llikwid -L/usr/lib -L/home/soft/likwid/lib $(FLAGS2)

%.o: %.cpp
	g++ -c $< -o $@ -Wall -I/home/soft/likwid/include $(FLAGS1)

%.o_sse: %.cpp
	g++ -c $< -o $@ -Wall -I/home/soft/likwid/include $(FLAGS2)

clean:
	rm *.o *.o_sse montecarlo montecarlo_simd 2> /dev/null || true

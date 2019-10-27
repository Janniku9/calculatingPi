CC = gcc

all: calculatePi calculatePiFast calculatePiFaster

calculatePi: calculatePi.c
	$(CC) -std=c99 -o calculatePi calculatePi.c -lgmp -lmpfr -pthread

calculatePiFast: calculatePi.c
	$(CC) -std=c99 -O3 -o calculatePiFast calculatePi.c -lgmp -lmpfr -pthread

calculatePiO3: calculatePi.c
	$(CC) -std=c99 -Ofast -o calculatePiO3 calculatePi.c -lgmp -lmpfr -pthread

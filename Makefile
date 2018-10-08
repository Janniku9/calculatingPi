CC = gcc

all: calculatePi calculatePiFast calculatePiFaster

calculatePi: calculatePi.c
	$(CC) -std=c99 -o calculatePi calculatePi.c -lgmp -lmpfr -pthread

calculatePiFast: calculatePi.c
	$(CC) -std=c99 -O3 -o calculatePiFast calculatePi.c -lgmp -lmpfr -pthread

calculatePiFaster: calculatePi.c
	$(CC) -std=c99 -Ofast -o calculatePiFaster calculatePi.c -lgmp -lmpfr -pthread

1billion: calculatePi-1Billion.c
	$(CC) -std=c99 -O3 -o calculatePi-1Billion calculatePi-1Billion.c -lgmp -lmpfr -pthread

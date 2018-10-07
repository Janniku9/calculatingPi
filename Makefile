CC = gcc

calculatePi: calculatePi.c
	$(CC) -o calculatePi calculatePi.c -lgmp -lmpfr -pthread

calculatePiFast: calculatePi.c
	$(CC) -O3 -o calculatePiFast calculatePi.c -lgmp -lmpfr -pthread

calculatePiFaster: calculatePi.c
	$(CC) -Ofast -o calculatePiFaster calculatePi.c -lgmp -lmpfr -pthread

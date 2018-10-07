CC = gcc

calculatePi: calculatePi.c
	$(CC) -o calculatePi calculatePi.c -lgmp -lmpfr

calculatePiFast: calculatePi.c
	$(CC) -o calculatePiFast calculatePi.c -O3 -lgmp -lmpfr

calculatePiFaste: calculatePi.c
	$(CC) -o calculatePiFaster calculatePi.c -Ofast -lgmp -lmpfr

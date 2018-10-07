CC = gcc

calculatePi: calculatePi.c
	$(CC) -o calculatePi calculatePi.c

calculatePiFast: calculatePi.c
	$(CC) -o calculatePiFast calculatePi.c -O3

calculatePiFaste: calculatePi.c
	$(CC) -o calculatePiFaster calculatePi.c -Ofast

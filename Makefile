CC = gcc

calculatePi: calculatePi.c
	$(CC) -std=c++11 -o calculatePi calculatePi.c -lgmp -lmpfr -pthread

calculatePiFast: calculatePi.c
	$(CC) -std=c++11 -O3 -o calculatePiFast calculatePi.c -lgmp -lmpfr -pthread

calculatePiFaster: calculatePi.c
	$(CC) -std=c++11 -Ofast -o calculatePiFaster calculatePi.c -lgmp -lmpfr -pthread

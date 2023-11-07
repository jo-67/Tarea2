#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // Incluye la biblioteca para definir NULL
#include <time.h>
#include <math.h>
#include "radixSort.c"
#include "quicksort.c"


// Función para crear un arreglo aleatorio de tamaño n con números en el rango [1, u]
unsigned long long* createRandomArray(int n, unsigned long long u) {
    unsigned long long* arreglo = (unsigned long long*)malloc(n * sizeof(unsigned long long));

    for (int i = 0; i < n; i++) {
        arreglo[i] = 1 + (unsigned long long) rand() % (u-1);
        //arreglo[i] = generarNumeroAleatorio(u);
    }

    return arreglo;
}

int experiment_k(int p) {
    printf("Ejecutando para 2^%d \n", p);

    // Semilla para la generación de números aleatorios
    srand((unsigned)time(NULL));

    int n = 100000000; // Tamaño del arreglo 100 millones
    //unsigned long long u = pow(2,p); // Rango [1, u]
    unsigned  __int128 u = 1;
    u <<= p;
    clock_t radix = 0;
    for (int i=1 ; i<30 ; i++) {
        unsigned long long* randomArray = createRandomArray(n, u);
        clock_t inicio = clock();
        radixSort(randomArray, n, i);
        clock_t fin = clock();
        radix = (fin -inicio);
        double tiempo_radix = (double)(radix) / CLOCKS_PER_SEC;
        printf("RadixSort k=%d tomó %.2lf segundos en ejecutarse.\n", i,tiempo_radix);

        free(randomArray);
    }

    printf("End\n");

    return 0;

}

int main() {
    //createRandomArray(100000000, u);
    for (int i = 1; i < 64; i++) {
        experiment_k(i);
        //arreglo[i] = generarNumeroAleatorio(u);
    }
    printf("End");
    return 0;
}






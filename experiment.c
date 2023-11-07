#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // Incluye la biblioteca para definir NULL
#include <time.h>
#include <math.h>
#include "radixSort.c"

unsigned long long generarNumeroAleatorio(unsigned long long u) {
    unsigned long long r = 0;
    if (u <= 0) {
        // Manejo de error: u debe ser mayor que 0
        printf("cero");
        return 0;
    }
    for (int i = 0; i < 64; i++) {
        r = (r << 1) | (unsigned long long)(rand() & 1);
    }
    return 1 + (r % u);
}

// Función para crear un arreglo aleatorio de tamaño n con números en el rango [1, u]
unsigned long long* createRandomArray(int n, unsigned long long u) {
    unsigned long long* arreglo = (unsigned long long*)malloc(n * sizeof(unsigned long long));

    for (int i = 0; i < n; i++) {
        arreglo[i] = 1 + (unsigned long long) rand() % (u-1);
        //arreglo[i] = generarNumeroAleatorio(u);
    }

    return arreglo;
}

int experiment_u(int p) {
    printf("Ejecutando para 2^%d \n", p);

    // Semilla para la generación de números aleatorios
    srand((unsigned)time(NULL));

    int n = 100000000; // Tamaño del arreglo 100 millones
    //unsigned long long u = pow(2,p); // Rango [1, u]
    unsigned  __int128 u = 1;
    u <<= p;

    // Llamada a la función para crear el arreglo
    unsigned long long* randomArray = createRandomArray(n, u);
    // Test radix sort
    clock_t inicio = clock();
    radixSort(randomArray, n, 15);
    clock_t fin = clock();

    //double tiempo_radix = (double)(fin - inicio) / CLOCKS_PER_SEC;
    double tiempo_radix = (double)(fin - inicio);
    printf("RadixSort tomó %.2lf segundos en ejecutarse.\n", tiempo_radix);

    //Test Quick sort
    clock_t inicio2 = clock();
    // quick 
    clock_t fin2 = clock();

    double tiempo_quick = (double)(fin2 - inicio2) / CLOCKS_PER_SEC;

    printf("QuickSort tomó %.2lf segundos en ejecutarse.\n", tiempo_quick);

    printf("End\n");

    // Liberar memoria
    free(randomArray);

    return 0;

}

int main() {
    //createRandomArray(100000000, u);
    for (int i = 1; i < 64; i++) {
        experiment_u(i);
        //arreglo[i] = generarNumeroAleatorio(u);
    }
    printf("End");
    return 0;
}






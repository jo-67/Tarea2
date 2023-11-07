#include <stdio.h>
#include <inttypes.h>

unsigned long long getMax(unsigned long long array[], unsigned long long size){
    unsigned long long max = array[0];
    for (unsigned long long i = 1; i < size; i++){
        if (array[i]>max){
            max = array[i];
        }
    }
    return max;
}

unsigned long long getBits(unsigned long long n, unsigned long long bits, int k){
    unsigned long long mask = ~(~0U << bits); //remplace el -1 por ~0U
    return (n >> (k)) & mask;
}

void radixSort(unsigned long long array[], unsigned long long size, unsigned long long bits){

    unsigned long long max = ~(~0U << bits); //si esto es demasiado cambiarlo por la cantidad de bits del maximo

    unsigned long long C[max+1]; 

    for (int k = 0; k < 64; k += bits){ // es 64 porque los numeros long long tienen 8 bytes y eso son 64 bits //puede ser que se puda obtimizar la cantidad de "vueltas que da" //probablemte se tiene que cambiar esto
       //reemplazar el 64 por la cantidad de bits del numero más grande asi se reduce la cantidad de ciclos

       //unsigned long long max = ~(~0U << bits);

       //unsigned long long C[max+1]; // puede ser que haya que sumar 1

       for(unsigned long long i = 0; i < max+1; i++){ //se inicialiiza C
            C[i] = 0;
        }

        for(unsigned long long i = 0; i < max+1; i++){ //se inicialiiza C
            C[i] = 0;
        }

        for(unsigned long long i = 0; i < size; i++){
            C[getBits(array[i],bits,k)]++;
        }

        for(unsigned long long i = 1; i < max+1; i++){
            C[i] += C[i-1];
        }

        //unsigned long long B[size];
        unsigned long long* B = (unsigned long long*)malloc(size * sizeof(unsigned long long));

        for (long long j = size-1; j >= 0; j--){
            unsigned long long n = C[getBits(array[j],bits,k)];
            B[n-1] = array[j];
            C[getBits(array[j],bits,k)]--;
        }

        for (unsigned long long i = 0; i < size; i++){
            array[i] = B[i];
        }
        free(B);
        
    }

}
/*
int main(){
    unsigned long long array[] = {5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235};
    unsigned long long size = sizeof(array)/sizeof(array[0]);
    radixSort(array,size,1);
    
    for (unsigned long long i = 0; i < size; i++){
        printf("%I64u ", array[i]);
    }

    printf("\n");
    return 0;
}
*/



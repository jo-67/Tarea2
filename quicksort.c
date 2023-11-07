#include <stdio.h>

void qs(unsigned long long lista[],unsigned long long limite_izq,unsigned long long limite_der)
{
    unsigned long long izq,der,temporal,pivote;

    izq=limite_izq;
    der = limite_der;
    pivote = rand() % sizeof(lista);

    do{
        while(lista[izq]<pivote && izq<limite_der)izq++;
        while(pivote<lista[der] && der > limite_izq)der--;
        if(izq <=der)
        {
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;

        }

    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}

}

void quicksort(unsigned long long lista[],unsigned long long n)
{
    qs(lista,0,n-1);
}

int main()
{

    unsigned long long lista[] ={5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235,5,1,3,10,29,12,2,2,2,3,4,5,6,3,87,2,3,434,12,19,946,178,3348,123,5234,1,1,1,94235};
    unsigned long long size = sizeof(lista)/sizeof(unsigned long long);

    printf("Lista Desordenada \n");

    for (unsigned long long i=0; i<size; i++) {
        printf("%llu",lista[i]);
        if(i<size-1)
            printf(",");
    }

    printf("\n");
    quicksort(lista,size);

    printf("Lista Ordenada \n");
    for (unsigned long long i=0; i<size; i++) {
        printf("%llu ",lista[i]);
        if(i<size-1)
            printf(",");
    }

    return 0;
}

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#define false 0
#define true 1
#define DATO_INVALIDO -1

int array_mostrar(int* pArray, int limiteArray);
int array_calcularMaximo(int* pArray, int limiteArray, int* pMaximo);
int array_init(int* pArray, int limiteArray, int valor);
int array_minimoDesde(int* pArray, int limiteArray, int desde, int* pMinimo);
void array_swap(int* elementoA, int*elementoB);
void array_ordenarArray(int* pArray, int limiteArray, int orden);
void array_imprimirIntArray(int* pArray, int limiteArray);


#endif // ARRAY_H_INCLUDED

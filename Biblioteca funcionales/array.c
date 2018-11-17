#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int array_mostrar(int* pArray, int limiteArray)
{
    int i;
    for(i=0;i<limiteArray;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);
    }
    return 0;
}

int array_calcularMaximo(int* pArray, int limiteArray, int* pMaximo)
{

    int retorno=-1;
    int i;
    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limiteArray > 0)
    {

        for(i=0;i<limiteArray;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}
int array_init(int* pArray, int limiteArray, int valor)
{
    int retorno=-1;
    int i;

    if(pArray != NULL && limiteArray > 0)
    {
        for(i=0;i<limiteArray;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}
int array_minimoDesde(int* pArray, int limiteArray, int desde, int* pMinimo)
{
    int retorno=-1;
    int i;
    int auxiliarValorMinimo;
    int auxiliarIndiceMinimo;

    if(pArray != NULL && limiteArray > 0 && limiteArray >= desde && pMinimo != NULL)
    {
        for(i=desde;i<limiteArray;i++)
        {
           if(i==desde || pArray[i]< auxiliarValorMinimo)
           {
                auxiliarValorMinimo=pArray[i];
                auxiliarIndiceMinimo=i;
           }
           else if(pArray[i]< auxiliarValorMinimo)
           {
                auxiliarValorMinimo=pArray[i];
                auxiliarIndiceMinimo=i;
           }

        }
        *pMinimo=auxiliarIndiceMinimo;
        retorno = 0;
    }
    return retorno;
}
void array_swap(int* elementoA, int*elementoB)
{
    int auxiliar;
    auxiliar= *elementoA;
    *elementoA= *elementoB;
    *elementoB=auxiliar;

}
void array_ordenarArray(int* pArray, int limiteArray, int orden)
{
    int i;
    int auxiliar;
    int continuar = 1;

    while(continuar)
    {
        continuar = 0;
        for (i = 1; i < limiteArray; i++)
        {
            if (pArray[i] < pArray[i - 1] && orden==0)
            {
                array_swap(&pArray[i], &pArray[i-1]);
//                auxiliar = pArray[i];
//                pArray[i] = pArray[i - 1];
//                pArray[i - 1] = auxiliar;
                continuar = 1;
            }
            else if (pArray[i] > pArray[i - 1] && orden==1)
            {
                array_swap(&pArray[i], &pArray[i-1]);
//                auxiliar = pArray[i];
//                pArray[i] = pArray[i - 1];
//                pArray[i - 1] = auxiliar;
                continuar = 1;
            }
        }
    }
}
void array_imprimirIntArray(int* pArray, int limiteArray)
{
	int i;
	for(i = 0; i < limiteArray; i++)
	{
	    printf("\n%d",pArray[i]);
	}
}
void array_ordenarArrayInsercion(int* pArray, int limiteArray)
{
	int i;
	int j;
	int auxiliar;

	for(i = 1; i < limiteArray; i++)
	{
		auxiliar = pArray[i];
		j = i;
		while(j > 0 && auxiliar > pArray[j - 1]) //Cambiar simbolo entre auxilar - pArray para cambiar orden
		{
			pArray[j] = pArray[j - 1];
			j--;
		}
		pArray[j] = auxiliar;
	}
}

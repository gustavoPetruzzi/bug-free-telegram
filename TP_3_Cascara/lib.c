#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#define CHAR 1
#define INT 2
#define FLOAT 3

// FALTA INICIALIZAR ARRAY STRING
int initArray(void* pArray, int length, int tipo)
{
    int i;
    int retorno = -1;

    if(pArray != NULL && length>0 )
    {
        retorno = 0;
        for(i=0;i < length;i++)
        {
            switch(tipo)
            {
                case 1:
                    (*(char*)pArray) = 'a';
                    pArray = pArray + sizeof(char);
                    break;
                case 2:
                    (*(int*)pArray) = -1;
                    pArray = pArray + sizeof(int);
                    break;
                case 3:
                    (*(float*)pArray) = -1;
                    pArray = pArray + sizeof(float);
                    break;
            }
        }
    }
    return retorno;
}

char mostrarMenu( char* textomenu, char min, char max )
{
    char opcion;
    if()
    opcion =getChar(&opcion, textomenu, "ERROR: ", )
    return opcion;
}

int mostrarArray(void* pArray, int largo, int tipo)
{
    int i,retorno=-1;
    if(pArray != NULL && largo > 0)
    {
        retorno = 0;
        for(i=0;i < largo;i++)
        {
            switch (tipo)
            {
                case INT:
                    printf("DIR: %p - VALOR:%i\n",pArray,*(int*)pArray);
                    pArray = pArray + sizeof(int);
                    break;

                case FLOAT:
                    printf("DIR: %p - VALOR:%f\n",pArray,*(float*)pArray);
                    pArray = pArray + sizeof(float);
                    break;

                case CHAR:
                    printf("DIR: %p - VALOR:%c\n",pArray,*(char*)pArray);
                    pArray = pArray + sizeof(char);
                    break;
                break;

            }
        }
    }
}

int buscarLibre(int * pArray, int length)
{
    int i;
    int indice = -1;
    if(pArray != NULL && length> 0)
    {
        for(i = 0; i<length; i++)
        {
            if(*pArray != -1)
            {
                indice = i;
                break;
            }
            pArray++;
        }
    }
    return indice;
}

int agregarPersonaArray(int * pArray, int length)
{

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int initArrayEstructuras(EMovie* pMovie, int length)
{
    int i;
    int retorno = -1;
    if(pMovie != NULL && length> 0)
    {
        retorno = 0;
        for(i=0; i<length; i++)
        {
            (pMovie+i)->isEmpty = 1;
        }
    }
    return retorno;
}

int buscarLibre(EMovie* pMovie, int length)
{
    int i;
    int indice = -1;

    if(pMovie != NULL && length> 0)
    {
        for(i = 0; i<length; i++)
        {
            if( (pMovie+i)->isEmpty == 1 )
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int buscarPorNombre(EMovie* pMovie, int length)
{
    int i;
    int indice = -1;
    char auxTitulo[20];
    int auxInt;
    if(pMovie != NULL && length> 0)
    {
        do
        {
            auxInt = getStringSpace(auxTitulo, "Ingrese el titulo de la pelicula: ", "Error: Maximo 50 caracteres", 0, 21);
        }while(auxInt!=0);

        for(i = 0; i<length; i++)
        {
            if(strcmp((pMovie+i)->titulo, auxTitulo) == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int pedirDatos(EMovie* pMovie, int length, char* titulo, char* genero, int* duracion, char* descripcion, int* puntaje, char* linkImagen)
{
    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLinkImagen[50];
    int auxInt;
    int retorno = -1;
    int i;

    if( pMovie != NULL && length> 0 && titulo != NULL && genero != NULL && duracion != NULL && descripcion != NULL && puntaje != NULL && linkImagen != NULL)
    {
        retorno = 0;

        do
        {
            auxInt = getStringSpace(auxTitulo, "Ingrese el titulo de la pelicula: ", "Error: Maximo 50 caracteres", 0, 21);
            for(i=0;i<length; i++)
                if(strcmp((pMovie+i)->titulo, auxTitulo) == 0)
                {
                    auxInt = -1;
                    printf("Ya existe una pelicula con ese titulo!");
                    break;
                }
        }while(auxInt!=0);
        strcpy(titulo, auxTitulo);

        do
        {
            auxInt = getStringSpace(auxGenero, "Ingrese el genero: ", "Error: Maximo 20 caracteres", 0, 21);
        }while(auxInt!=0);
        strcpy(genero, auxGenero);

        do
        {
            auxInt = getStringSpace(auxDescripcion, "Ingrese la descripcion: ", "Error: Maximo 20 caracteres", 0, 21);
        }while(auxInt!=0);
        strcpy(descripcion, auxDescripcion);

        do
        {
            auxInt = getStringSpace(auxLinkImagen, "Ingrese el link de la imagen: ", "Error: Maximo 50 caracteres", 0, 51);
        }while(auxInt!=0);
        strcpy(linkImagen, auxLinkImagen);

        do
        {
            auxInt = getInt(&auxDuracion, "Ingrese la duracion de la pelicula de la imagen: ", "Error: duracion minima 60 minutos", 59, 961);
            // VALIDO HASTA 961 MINUTOS PORQUE LA PELICULA MAS LARGA HASTA EL MOMENTO ES DE 15HS
        }while(auxInt!=0);
        *duracion = auxDuracion;

        do
        {
            auxInt = getInt(&auxPuntaje, "Ingrese el link de la imagen: ", "Error: Maximo 50 caracteres", 0, 10);
        }while(auxInt!=0);
        *puntaje = auxPuntaje;
    }
    return retorno;
}
int agregarPelicula(EMovie *pMovie, int length)
{
    int retorno;
    int indice;

    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int auxInt;
    if(pMovie != NULL && length > 0)
    {
        retorno = 0;
        indice = buscarLibre(pMovie, length);
        if(indice !=-1)
        {
            auxInt = pedirDatos(pMovie, length, titulo, genero, &duracion, descripcion, &puntaje, linkImagen);
            if(auxInt == 0)
            {

                strcpy((pMovie-indice)->titulo, titulo);
                strcpy((pMovie+indice)->genero, genero);
                (pMovie+indice)->duracion = duracion;
                (pMovie+indice)->puntaje = puntaje;
                strcpy((pMovie+indice)->descripcion, descripcion);
                strcpy((pMovie+indice)->linkImagen, linkImagen);
                (pMovie+indice)->isEmpty = 0;
            }
        }
    }
    return retorno;
}

int borrarPelicula(EMovie* pmovie)



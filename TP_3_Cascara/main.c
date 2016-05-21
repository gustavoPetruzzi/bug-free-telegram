#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY 50
int main()
{
    char seguir='s';
    int opcion=0;
    int auxInt;
    int i;
    EMovie peliculas[QTY];

    auxInt = cargarArchivo(peliculas, QTY);

    if(auxInt == 0)
    {
        while(seguir=='s')
        {
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Salir\n");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    auxInt = agregarPelicula(peliculas, QTY);
                    if(auxInt == 0)
                    {
                        printf("Pelicula cargada");
                    }
                    else
                    {
                        printf("No se ha podido cargar la pelicula");
                    }
                    for(i=0;i<QTY;i++)
                    {

                        if((peliculas+i)->isEmpty == 0)
                        {

                            printf("Titulo: %s\n", (peliculas+i)->titulo);
                        }
                    }
                    break;
                case 2:
                    auxInt = borrarPelicula(peliculas, QTY);
                    if(auxInt !=0)
                    {
                        printf("Error");
                    }
                    break;
                case 3:
                    auxInt = modificarPelicula(peliculas, QTY);
                    if(auxInt !=0)
                    {
                        printf("Error");
                    }
                   break;
                case 4:
                    break;
                case 5:
                    auxInt = guardarEnArchivo(peliculas, QTY);
                    if(auxInt == 0)
                    {
                        printf("Archivo guardado");
                    }
                    seguir = 'n';
                    break;
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY 50
int main()
{
    char seguir='s';
    int opcion=0;
    int auxInt;
    EMovie peliculas[50];
    int i;
    auxInt = initArrayEstructuras(peliculas, QTY);

    if(auxInt == 0)
    {
        while(seguir=='s')
        {
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Generar pagina web\n");
            printf("4- Salir\n");

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
                    break;
                case 3:
                   break;
                case 4:
                    seguir = 'n';
                    break;
            }
        }
    }

    return 0;
}

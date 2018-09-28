#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "publicidad.h"
#define Pantallas 4
#define Publicidades 4
#define TIPO_LED 0
#define TIPO_LCD 1
#define OCUPADO 0
#define LIBRE 1

//1º inicializar Lista
//2º Buscar Lugar Libre
//3º Gernerar Id

int main()
{

    int menu;
    int index;
    int auxiliarId;
    char cuit[75];

    Pantalla arrayPantallas[Pantallas];
    Publicidad arrayPublicidades[Publicidades];

    pantalla_inicializar(arrayPantallas,Pantallas);
    publicidad_inicializar(arrayPublicidades,Publicidades);

    pantalla_altaForzada(arrayPantallas,Pantallas,"Video/Audio",0,"Av 123");
    pantalla_altaForzada(arrayPantallas,Pantallas,"AudioVideo",1,"Av 20");

    publicidad_altaForzada(arrayPublicidades,Publicidades,"2045789",2,"AudioVideo");

    do{

        getValidInt("\n\n1.Alta Pantalla\n2.Modificar\n3.Baja Pantalla\n4.Alta Publicidad\n5.Mostrar\n6.Salir\n","\nNo valida\n",&menu,1,10,1);
        switch(menu)
        {

            case 1:

                index = pantalla_buscarLugarLibre(arrayPantallas,Pantallas);
                if(index >= 0){

                    pantalla_alta(arrayPantallas,Pantallas,index);

                    break;
                }

            case 2:


                getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,Pantallas,2);
                pantalla_modificacion(arrayPantallas,Pantallas,auxiliarId);
                break;

            case 3:

                getValidInt("ID: ","\nID No valido\n",&auxiliarId,0,Pantallas,2);
                pantalla_baja(arrayPantallas,Pantallas,auxiliarId);
                break;

            case 4:

                pantalla_mostrar(arrayPantallas,Pantallas);
                getValidInt("\nCuit: ","\nCuit No valido\n",&auxiliarId,0,Pantallas,2);
                publicidad_alta(arrayPublicidades,arrayPantallas,Publicidades,auxiliarId);
                break;
            case 5:

                getStringNumeros("Ingrese Cuit: ",cuit);



            case 10:

                pantalla_mostrar(arrayPantallas,Pantallas);
                printf("\n");
                publicidad_mostrar(arrayPublicidades,Publicidades);
                break;
        }
    }while(menu != 10);


    return 0;
}

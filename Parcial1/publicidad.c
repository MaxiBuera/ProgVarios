#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "publicidad.h"
#define OCUPADO 0
#define LIBRE 1
#define TIPO_LED 0
#define TIPO_LCD 1

static int proximoId();

int publicidad_inicializar(Publicidad* arrayPublicidades, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayPublicidades != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayPublicidades[i].id = -1;
            strcpy(arrayPublicidades[i].nombreVideo,"");
            strcpy(arrayPublicidades[i].cuit,"");
            arrayPublicidades[i].cantidadDias = -1;
            arrayPublicidades[i].isEmpty = LIBRE;

        }
    }
    return retorno;
}

int publicidad_alta(Publicidad* arrayPublicidades,Pantalla* arrayPantalla , int limite, int index){

    int indice;
    int retorno = -1;
    char cuit[20];
    int cantidadDias;
    char nombreVideo[75];

    indice = pantalla_buscarPorId(arrayPantalla,limite,index);
    if(indice >= 0)
    {

        if(arrayPublicidades != NULL && limite > 0){

            if(getStringNumeros("Ingrese cuit: ",cuit)){

                if(!getValidInt("Ingrese cantidad de dias que dura la publicacion: ","Opcion no valida",&cantidadDias,1,1000,2)){

                    if(getStringLetras("Ingrese nombre Video: ",nombreVideo)){

                        strcpy(arrayPublicidades[index].cuit,cuit);
                        strcpy(arrayPublicidades[index].nombreVideo,nombreVideo);
                        arrayPublicidades[index].cantidadDias = cantidadDias;
                        //arrayPantalla[index].isEmpty = OCUPADO;
                        //arrayPantalla[index].id = generarId();
                        retorno = 0;
                    }
                }
            }
        }
    }

    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

int publicidad_mostrar(Publicidad* arrayPublicidades,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPublicidades != NULL)
    {
        retorno = 0;
        printf("\nCuitCant Dias\tNombre Video\tID");
        for(i=0;i<limite;i++)
        {
        	if(!arrayPublicidades[i].isEmpty)
            {

           		printf("\n%s - %d - %s - %d",arrayPublicidades[i].cuit,arrayPublicidades[i].cantidadDias,arrayPublicidades[i].nombreVideo,arrayPublicidades[i].id);
        	}
        }
    }
    return retorno;
}

int publicidad_altaForzada(Publicidad* arrayPublicidades,int limite,char* cuit,int cantidadDias, char* nombreVideo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayPublicidades != NULL)
    {
        i = publicidad_buscarLugarLibre(arrayPublicidades,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayPublicidades[i].cuit,cuit);
            arrayPublicidades[i].cantidadDias = cantidadDias;
            strcpy(arrayPublicidades[i].nombreVideo,nombreVideo);
            //------------------------------
            //------------------------------
            arrayPublicidades[i].id = proximoId();
            arrayPublicidades[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int publicidad_buscarLugarLibre(Publicidad* arrayPublicidades,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPublicidades != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayPublicidades[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_buscarPorCuit(Publicidad* arrayPublicidades,int limite, char* cuit){

    int retorno = -1;
    int i;

    for(i=0;i<limite;i++){

        if(strcmp(arrayPublicidades[i].cuit,cuit) == 0){

            retorno = 0;
        }
    }

    return retorno;
}

int publicidad_modificarPublicacion(Publicidad* arrayPublicidades,int limite, char* cuit){

    int retorno = -1;

    if(arrayPublicidades != NULL && limite > 0){

        if(publicidad_buscarPorCuit(arrayPublicidades,limite,cuit) == 0){



        }
    }

    return retorno;
}



int publicidad_mostrarPantallasPorCuit(Publicidad* arrayPublicidades, Pantalla* P,int limite, char* cuit){

    int i;

    for(i=0;i<limite;i++){

        arrayPublicidades[i].

    }

return 0;
}

static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

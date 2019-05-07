#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "autores.h"
#define OCUPADO 0
#define LIBRE 1

static int proximoId();

void autor_normalizarCadena(char cadena[]){

    int j,i;
    i = strlen(cadena);

    for(j=0;j<i;j++){

        if(j==0){

            cadena[j] = toupper(cadena[j]);
        }
        else{

            cadena[j] = tolower(cadena[j]);
        }
    }
}

int autor_inicializar(eAutor* arrayAutores, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayAutores != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayAutores[i].idAutores = -1;
            strcpy(arrayAutores[i].apellido,"");
            strcpy(arrayAutores[i].nombre,"");
            arrayAutores[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int autor_alta(eAutor* arrayAutores, int limite, int index){

    int retorno = -1;
    char apellidoAux[51];
    char nombreAux[51];
    int id;

    if(limite > 0 && arrayAutores != NULL){

        retorno = -2;
        id = proximoId();

        if(getStringLetras("Ingrese nombre: ",apellidoAux)){

            if(getStringLetras("Ingrese apellido: ",nombreAux)){

                autor_normalizarCadena(apellidoAux);
                strcpy(arrayAutores[index].apellido,apellidoAux);

                autor_normalizarCadena(nombreAux);
                strcpy(arrayAutores[index].nombre,nombreAux);

                arrayAutores[index].isEmpty = OCUPADO;
                arrayAutores[index].idAutores = id;
                retorno = 0;

            }
        }
    }

    return retorno;

}

int autor_buscarLugarLibre(eAutor* arrayAutores,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayAutores != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayAutores[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int autor_altaForzada(eAutor* arrayAutores,int limite,char* apellido,char* nombre)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayAutores != NULL)
    {
        i = autor_buscarLugarLibre(arrayAutores,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayAutores[i].apellido,apellido);
            strcpy(arrayAutores[i].nombre,nombre);
            //------------------------------
            //------------------------------
            arrayAutores[i].idAutores = proximoId();
            arrayAutores[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}


int autor_buscarPorId(eAutor* arrayAutores,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayAutores != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayAutores[i].isEmpty == OCUPADO && arrayAutores[i].idAutores == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int autor_menuModificacion(){

    int opc;
    int retorno = -1;

    //printf("\nModificar:\n\t\t1)Apellido\n\t\t2)Nombre");
    if(!getValidInt("\nModificar:\n\t\t1)Apellido\n\t\t2)Nombre","\nError",&opc,1,2,2)){

        return opc;
    }

    return retorno;
}

int empleado_modificacion(eAutor* arrayAutores, int limite,int index){

    int indice;
    int retorno = -1;
    char apellidoAux[31];
    char nombreAux[31];
    int opc;

    indice = autor_buscarPorId(arrayAutores,limite,index);
    if(indice >= 0)
    {
        retorno = 0;

        opc = autor_menuModificacion();

        if(opc == 1){

            if(getStringLetras("Ingrese apellido: ",apellidoAux)){

            strcpy(arrayAutores[index].apellido,apellidoAux);
            arrayAutores[index].isEmpty = OCUPADO;
            }
        }

        if(opc == 2){

            if(getStringLetras("Ingrese nombre: ",nombreAux)){

                strcpy(arrayAutores[index].nombre,nombreAux);
                arrayAutores[index].isEmpty = OCUPADO;
            }
        }
    }
    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

int autor_baja(eAutor* arrayAutores, int limite,int index){

    int retorno = -1;
    int indice;
    indice = autor_buscarPorId(arrayAutores,limite,index);
    if(indice >= 0)
    {
        retorno = 0;
        arrayAutores[indice].isEmpty = LIBRE;
    }
    else{

        printf("\nCodigo de Autor no encontrado");
    }
    return retorno;
}
/*Listar: Hacer un único listado de todos los autores ordenados por Apellido y Nombre, mostrando también
su Código.*/
int autor_listado(eAutor* arrayAutores,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayAutores != NULL)
    {
        retorno = 0;
        printf("\n\tNombre\t\tApellido\tCodigo");
        for(i=0;i<limite;i++)
        {
        	if(!arrayAutores[i].isEmpty)
            {

           		printf("\n\t%s\t\t%s\t\t%d",arrayAutores[i].apellido,arrayAutores[i].nombre,arrayAutores[i].idAutores);
           		//printf("\n\t%s\t\t%s\t%d",arrayEmpleados[i].name,arrayPantalla[i].lastname,arrayEmpleados[i].id,arrayEmpleados[i].sector,arrayEmpleados[i].salary);
        	}
        }
    }
    return retorno;
}

int autor_ordenarXapellido(eAutor* arrayAutores,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eAutor auxiliar;

    if(limite > 0 && arrayAutores != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arrayAutores[i].isEmpty == OCUPADO && arrayAutores[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(arrayAutores[i].apellido,arrayAutores[i+1].apellido) > 0 && !orden) || (strcmp(arrayAutores[i].apellido,arrayAutores[i+1].apellido) < 0 && orden))
                        {
                            auxiliar = arrayAutores[i];
                            arrayAutores[i] = arrayAutores[i+1];
                            arrayAutores[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

int autor_ordenarXnombre(eAutor* arrayAutores,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eAutor auxiliar;

    if(limite > 0 && arrayAutores != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arrayAutores[i].isEmpty == OCUPADO && arrayAutores[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(arrayAutores[i].nombre,arrayAutores[i+1].nombre) > 0 && !orden) || (strcmp(arrayAutores[i].nombre,arrayAutores[i+1].nombre) < 0 && orden))
                        {
                            auxiliar = arrayAutores[i];
                            arrayAutores[i] = arrayAutores[i+1];
                            arrayAutores[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

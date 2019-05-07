#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "autores.h"
#include "socios.h"
#include "libros.h"
#include "prestamos.h"
#define OCUPADO 0
#define LIBRE 1

static int proximoId();


int prestamo_inicializar(ePrestamo* arrayPrestamos, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayPrestamos != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayPrestamos[i].idPrestamos = -1;
            arrayPrestamos[i].idLibro = -1;
            arrayPrestamos[i].idSocio = -1;
            arrayPrestamos[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int verificarLibro(eLibro* arrayLibros, int limiteLibros, int idLibro){

    int i;
    int retorno = -1;

    for(i=0;i<limiteLibros;i++){

        if(idLibro == arrayLibros[i].idLibros){

            retorno = 0;
            return retorno;
        }
    }

    return retorno;
}

int verificarSocio(eSocio* arraySocios, int limiteSocios, int idSocio){

    int i;
    int retorno = -1;

    for(i=0;i<limiteSocios;i++){

        if(idSocio == arraySocios[i].idSocios){

            retorno = 0;
            return retorno;
        }
    }

    return retorno;
}

int prestamo_alta(ePrestamo* arrayPrestamos, int limite, int index, eLibro* arrayLibros, int limiteLibros, eSocio* arraySocios, int limiteSocios){

    int retorno = -1;
    int idLibroAux;
    int idSocioAux;

    int diaAux;
    int mesAux;
    int anioAux;

    int id;

    if(limite > 0 && arrayPrestamos != NULL){

        retorno = -2;
        id = proximoId();

        if(!getValidInt("Ingrese ID del Libro: ","\nError",&idLibroAux,0,limiteLibros,2) && (!verificarLibro(arrayLibros,limiteLibros,idLibroAux))){

            if(!getValidInt("Ingrese ID de Socio: ","\nError",&idSocioAux,0,limiteSocios,2) && (!verificarSocio(arraySocios,limiteSocios,idSocioAux))){

                printf("Ingrese Fecha de Asociado:\n");

                if(!getValidInt("\tDia: ","\nError",&diaAux,1,31,2)){

                    if(!getValidInt("\tMes: ","\nError",&mesAux,1,12,2)){

                        if(!getValidInt("\tAnio: ","\nError",&anioAux,1980,2019,2)){

                            arrayPrestamos[index].idLibro = idLibroAux;
                            arrayPrestamos[index].idSocio = idSocioAux;
                            arrayPrestamos[index].fechaPrestamo.dia = diaAux;

                            arrayPrestamos[index].isEmpty = OCUPADO;
                            arrayPrestamos[index].idPrestamos = id;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }

    if(retorno != 0)
        printf("\nError\n");

    return retorno;

}

int prestamo_buscarLugarLibre(ePrestamo* arrayPrestamos,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPrestamos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayPrestamos[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int prestamo_altaForzada(ePrestamo* arrayPrestamos,int limite,int idLibro, int idSocio,int dia, int mes, int anio)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayPrestamos != NULL)
    {
        i = prestamo_buscarLugarLibre(arrayPrestamos,limite);
        if(i >= 0)
        {
            retorno = 0;
            arrayPrestamos[i].idLibro = idLibro;
            arrayPrestamos[i].idSocio = idSocio;
            arrayPrestamos[i].fechaPrestamo.dia = dia;
            arrayPrestamos[i].fechaPrestamo.mes = mes;
            arrayPrestamos[i].fechaPrestamo.anio = anio;
            //------------------------------
            //------------------------------
            arrayPrestamos[i].idPrestamos = proximoId();
            arrayPrestamos[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int prestamo_buscarPorId(ePrestamo* arrayPrestamos,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPrestamos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayPrestamos[i].isEmpty == OCUPADO && arrayPrestamos[i].idPrestamos == id)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}
/*
int autor_menuModificacion(){

    int opc;
    int retorno = -1;

    //printf("\nModificar:\n\t\t1)Apellido\n\t\t2)Nombre");
    if(!getValidInt("\nModificar:\n\t\t1)Apellido\n\t\t2)Nombre\n","\nError",&opc,1,2,2)){

        return opc;
    }

    return retorno;
}

int empleado_modificacion(ePrestamo* arrayAutores, int limite,int index){

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

int autor_baja(ePrestamo* arrayAutores, int limite,int index){

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

int autor_listado(ePrestamo* arrayAutores,int limite){

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

int autor_ordenarXapellido(ePrestamo* arrayAutores,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    ePrestamo auxiliar;

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

int autor_ordenarXnombre(ePrestamo* arrayAutores,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    ePrestamo auxiliar;

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
}*/

static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}


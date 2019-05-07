#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "autores.h"
#include "socios.h"
#define OCUPADO 0
#define LIBRE 1

static int proximoId();

void socio_normalizarCadena(char cadena[]){

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


int socio_inicializar(eSocio* arraySocios, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arraySocios != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arraySocios[i].idSocios = -1;
            strcpy(arraySocios[i].apellido,"");
            strcpy(arraySocios[i].nombre,"");
            strcpy(arraySocios[i].sexo,"");
            strcpy(arraySocios[i].telefono,"");
            strcpy(arraySocios[i].email,"");
            arraySocios[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}


int socio_alta(eSocio* arraySocios, int limite, int index){

    int retorno = -1;
    char apellidoAux[51];
    char nombreAux[51];
    char sexoAux[1];
    char telefonoAux[16];
    char emailAux[31];

    int diaAux;
    int mesAux;
    int anioAux;

    int id;

    if(limite > 0 && arraySocios != NULL){

        retorno = -2;
        id = proximoId();

        if(getStringLetras("Ingrese apellido: ",apellidoAux)){

            if(getStringLetras("Ingrese nombre: ",nombreAux)){

                fflush(stdin);
                if(!getValidString("Ingrese sexo [F - M]: ","\nError\n","\nError[F - M]\n",sexoAux,2,2) && (sexoAux[0] == 'm' || sexoAux[0] == 'f')){

                    if(getStringNumeros("Ingrese telefono: ",telefonoAux)){

                       if(getStringAllCharacters("Ingrese email: ",emailAux)){

                            printf("\nIngrese Fecha de Asociado:\n");

                            if(!getValidInt("\tDia: ","\nError",&diaAux,1,31,2)){

                                if(!getValidInt("\tMes: ","\nError",&mesAux,1,12,2)){

                                    if(!getValidInt("\tAnio: ","\nError",&anioAux,1980,2019,2)){

                                        socio_normalizarCadena(apellidoAux);
                                        strcpy(arraySocios[index].apellido,apellidoAux);

                                        socio_normalizarCadena(nombreAux);
                                        strcpy(arraySocios[index].nombre,nombreAux);

                                        strcpy(arraySocios[index].sexo,sexoAux);
                                        strcpy(arraySocios[index].telefono,telefonoAux);
                                        strcpy(arraySocios[index].email,emailAux);
                                        arraySocios[index].fecha.dia = diaAux;
                                        arraySocios[index].fecha.mes = mesAux;
                                        arraySocios[index].fecha.anio = anioAux;

                                        arraySocios[index].isEmpty = OCUPADO;
                                        arraySocios[index].idSocios = id;
                                        retorno = 0;
                                    }
                                }
                            }

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

int socio_buscarLugarLibre(eSocio* arraySocios,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arraySocios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arraySocios[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int socio_altaForzada(eSocio* arraySocios,int limite,char* apellido,char* nombre, char* sexo, char* telefono, char* email, int dia,int mes,int anio)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arraySocios != NULL)
    {
        i = socio_buscarLugarLibre(arraySocios,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arraySocios[i].apellido,apellido);
            strcpy(arraySocios[i].nombre,nombre);
            strcpy(arraySocios[i].sexo,sexo);
            strcpy(arraySocios[i].telefono,telefono);
            strcpy(arraySocios[i].email,email);
            arraySocios[i].fecha.dia = dia;
            arraySocios[i].fecha.mes = mes;
            arraySocios[i].fecha.anio = anio;
            //------------------------------
            //------------------------------
            arraySocios[i].idSocios = proximoId();
            arraySocios[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}


int socio_buscarPorId(eSocio* arraySocios,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arraySocios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arraySocios[i].isEmpty == OCUPADO && arraySocios[i].idSocios == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int socio_menuModificacion(){

    int opc;
    int retorno = -1;

    //printf("\nModificar:\n\t\t1)Apellido\n\t\t2)Nombre");
    if(!getValidInt("\nModificar:\n\t\t1)Apellido\n\t\t2)Nombre\n\t\t3)Sexo\n\t\t4)Telefono\n\t\t5)Email\n","\nError",&opc,1,5,2)){

        return opc;
    }

    return retorno;
}


int socio_modificacion(eSocio* arraySocios, int limite,int index){

    int indice;
    int retorno = -1;
    char apellidoAux[31];
    char nombreAux[31];
    char sexoAux[1];
    char telefonoAux[16];
    char emailAux[31];

    int opc;

    indice = socio_buscarPorId(arraySocios,limite,index);
    if(indice >= 0)
    {
        retorno = 0;

        opc = socio_menuModificacion();

        if(opc == 1){

            if(getStringLetras("Ingrese apellido: ",apellidoAux)){

                strcpy(arraySocios[index].apellido,apellidoAux);
            }
        }

        if(opc == 2){

            if(getStringLetras("Ingrese nombre: ",nombreAux)){

                strcpy(arraySocios[index].nombre,nombreAux);
            }
        }

        if(opc == 3){

            if(!getValidString("Ingrese sexo [F - M]: ","\nError\n","\nError\n",sexoAux,1,2)  && (sexoAux[0] == 'm' || sexoAux[0] == 'f')){

                strcpy(arraySocios[index].sexo,sexoAux);
            }
        }

        if(opc == 4){

            if(getStringLetras("Ingrese telefono: ",telefonoAux)){

                strcpy(arraySocios[index].telefono,telefonoAux);
            }
        }

        if(opc == 5){

            if(getStringLetras("Ingrese email: ",emailAux)){

                strcpy(arraySocios[index].email,emailAux);
            }
        }

    }
    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

int socio_baja(eSocio* arraySocios, int limite,int index){

    int retorno = -1;
    int indice;
    indice = socio_buscarPorId(arraySocios,limite,index);
    if(indice >= 0)
    {
        retorno = 0;
        arraySocios[indice].isEmpty = LIBRE;
    }

    else{

        printf("\nCodigo de Socio no encontrado");
    }
    return retorno;
}

int socio_listado(eSocio* arraySocios,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arraySocios != NULL)
    {
        retorno = 0;
        printf("\n\tNombre Socio\tApellido Socio\tCodigo\tSexo\t\tTelefono");
        for(i=0;i<limite;i++)
        {
        	if(!arraySocios[i].isEmpty)
            {
                printf("\n%s",arraySocios[i].sexo);
           		printf("\n\t%s\t\t%s\t\t%d\t%s\t%s\n\tEmail: %s",arraySocios[i].apellido,arraySocios[i].nombre,arraySocios[i].idSocios,arraySocios[i].sexo,arraySocios[i].telefono,arraySocios[i].email);
           		printf("\n\tFecha de Asociado: %d-%d-%d\n",arraySocios[i].fecha.dia,arraySocios[i].fecha.mes,arraySocios[i].fecha.anio);
           	}
        }
    }
    return retorno;
}


int socio_ordenarXapellido(eSocio* arraySocios,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eSocio auxiliar;

    if(limite > 0 && arraySocios != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arraySocios[i].isEmpty == OCUPADO && arraySocios[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(arraySocios[i].apellido,arraySocios[i+1].apellido) > 0 && !orden) || (strcmp(arraySocios[i].apellido,arraySocios[i+1].apellido) < 0 && orden))
                        {
                            auxiliar = arraySocios[i];
                            arraySocios[i] = arraySocios[i+1];
                            arraySocios[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}

int socio_ordenarXnombre(eSocio* arraySocios,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eSocio auxiliar;

    if(limite > 0 && arraySocios != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arraySocios[i].isEmpty == OCUPADO && arraySocios[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(arraySocios[i].nombre,arraySocios[i+1].nombre) > 0 && !orden) || (strcmp(arraySocios[i].nombre,arraySocios[i+1].nombre) < 0 && orden))
                        {
                            auxiliar = arraySocios[i];
                            arraySocios[i] = arraySocios[i+1];
                            arraySocios[i+1] = auxiliar;
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

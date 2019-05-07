#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "autores.h"
#include "libros.h"

#define OCUPADO 0
#define LIBRE 1

static int proximoId();

void libro_normalizarCadena(char cadena[]){

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

int libro_inicializar(eLibro* arrayLibros, int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayLibros != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayLibros[i].idLibros = -1;
            strcpy(arrayLibros[i].titulo,"");
            arrayLibros[i].idAutores = -1;
            arrayLibros[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int verificarAutor(eAutor* arrayAutores, int limiteAutores, int idAutor){

    int i;
    int retorno = -1;

    for(i=0;i<limiteAutores;i++){

        if(idAutor == arrayAutores[i].idAutores){

            retorno = 0;
            return retorno;
        }
    }

    return retorno;
}


int libro_alta(eLibro* arrayLibros, int limite, int index, eAutor* arrayAutores, int limiteAutores){

    int retorno = -1;
    char tituloAux[51];
    int id;
    int idAutor;

    if(limite > 0 && arrayLibros != NULL){

        retorno = -2;
        id = proximoId();

        if(getStringLetras("Ingrese titulo del libro: ",tituloAux)){

            if(!getValidInt("Ingrese ID de Autor: ","\nError",&idAutor,0,limiteAutores,2) && (!verificarAutor(arrayAutores,limiteAutores,idAutor))){

                libro_normalizarCadena(tituloAux);
                strcpy(arrayLibros[index].titulo,tituloAux);

                arrayLibros[index].isEmpty = OCUPADO;
                arrayLibros[index].idLibros = id;
                arrayLibros[index].idAutores = idAutor;
                retorno = 0;
            }

        }
    }

    return retorno;

}


int libro_buscarLugarLibre(eLibro* arrayLibros,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayLibros != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayLibros[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int libro_altaForzada(eLibro* arrayLibros,int limite,char* titulo,int idAutor)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayLibros != NULL)
    {
        i = libro_buscarLugarLibre(arrayLibros,limite);
        if(i >= 0)
        {
            retorno = 0;
            arrayLibros[i].idLibros = proximoId();
            strcpy(arrayLibros[i].titulo,titulo);
            arrayLibros[i].idAutores = idAutor;
            arrayLibros[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}


int libro_buscarPorId(eLibro* arrayLibros,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayLibros != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayLibros[i].isEmpty == OCUPADO && arrayLibros[i].idLibros == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int libro_menuModificacion(){

    int opc;
    int retorno = -1;

    //printf("\nModificar:\n\t\t1)Apellido\n\t\t2)Nombre");
    if(!getValidInt("\nModificar:\n\t\t1)Titulo\n\t\t2)ID de Libro\n","\nError",&opc,0,2,2)){

        return opc;
    }

    return retorno;
}


int libro_modificacion(eLibro* arrayLibros, int limite, eAutor* arrayAutores, int limiteAutores,int index){

    int indice;
    int retorno = -1;
    char tituloAux[51];
    int idAutorAux;
    int opc;

    indice = libro_buscarPorId(arrayLibros,limite,index);
    if(indice >= 0)
    {
        retorno = 0;

        opc = libro_menuModificacion();

        if(opc == 1){

            if(getStringLetras("Ingrese titulo: ",tituloAux)){

                libro_normalizarCadena(tituloAux);
                strcpy(arrayLibros[index].titulo,tituloAux);

            }
        }

        if(opc == 2){

            if(!getValidInt("Ingrese ID de Autor: ","\nError",&idAutorAux,0,limiteAutores,2) && (!verificarAutor(arrayAutores,limiteAutores,idAutorAux))){

             arrayLibros[index].idAutores = idAutorAux;
            }
        }
    }
    else{

        printf("\nID no encontrado");
    }
    return retorno;
}

int libro_baja(eLibro* arrayLibros, int limite,int index){

    int retorno = -1;
    int indice;
    indice = libro_buscarPorId(arrayLibros,limite,index);
    if(indice >= 0)
    {
        retorno = 0;
        arrayLibros[indice].isEmpty = LIBRE;
    }
    else{

        printf("\nCodigo de Libro no encontrado");
    }
    return retorno;
}

int libro_listado(eLibro* arrayLibros,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && arrayLibros != NULL)
    {
        retorno = 0;
        printf("\n\tTitulo\t\tCodigo del Libro\tCodigo de Autor");
        for(i=0;i<limite;i++)
        {
        	if(!arrayLibros[i].isEmpty)
            {

           		printf("\n\t%s\t\t%d\t\t%d",arrayLibros[i].titulo,arrayLibros[i].idLibros,arrayLibros[i].idAutores);
           		//printf("\n\t%s\t\t%s\t%d",arrayEmpleados[i].name,arrayPantalla[i].lastname,arrayEmpleados[i].id,arrayEmpleados[i].sector,arrayEmpleados[i].salary);
        	}
        }
    }
    return retorno;
}

int libro_ordenarXtitulo(eLibro* arrayLibros,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    eLibro auxiliar;

    if(limite > 0 && arrayLibros != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arrayLibros[i].isEmpty == OCUPADO && arrayLibros[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(arrayLibros[i].titulo,arrayLibros[i+1].titulo) > 0 && !orden) || (strcmp(arrayLibros[i].titulo,arrayLibros[i+1].titulo) < 0 && orden))
                        {
                            auxiliar = arrayLibros[i];
                            arrayLibros[i] = arrayLibros[i+1];
                            arrayLibros[i+1] = auxiliar;
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

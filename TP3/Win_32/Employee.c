#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Employee.h"



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* auxEmployee = employee_new();

    if(     !employee_setId(auxEmployee, idStr)
       &&   !employee_setNombre(auxEmployee, nombreStr)
       &&   !employee_setHorasTrabajadas(auxEmployee, horasTrabajadasStr))
    {
         return auxEmployee;
    }
    employee_delete(auxEmployee);
    return NULL;
}

Employee* employee_new()
{
    return malloc(sizeof(Employee));
}

void employee_delete(Employee* this)
{
    free(this);
}

int  employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {

            if(id > maximoId)
                maximoId = id;
            this->id = id;
        }
        else
        {
            maximoId++;
            this->id = maximoId;
        }

    }

    return retorno;

}

char  employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {

        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

char movie_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {

        strcpy(nombre,this->nombre);
         retorno = 0;
    }
    return retorno;
}

int  movie_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int movie_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {

        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;

}

int  movie_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {

        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int movie_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {

        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;

}

void mostrarPeliculas(Employee* this[],int cantidad)
{
    int i;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];

    for(i=0 ; i<cantidad;i++)
    {
        if(this[i] != NULL){

            movie_getTitulo(this[i],titulo);
            movie_getGenero(this[i],genero);
            movie_getDuracion(this[i],&duracion);
            movie_getDescripcion(this[i],descripcion);
            movie_getPuntaje(this[i],&puntaje);
            movie_getLinkImagen(this[i],linkImagen);

            printf("%s - %s - %d - %s - %d - %s - %d\n",titulo,genero,duracion,descripcion,puntaje,linkImagen,i);
        }
    }
}

/**
 *  Agrega un empleado al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar el empleado o no
 */
void altaEmpleado(Employee* this[],int* cantidad){

    char nombre[500];
    int horasTrabajadas;
    int sueldo;

    if((*cantidad) > 0 && this != NULL)
    {
        if(!getValidString("Titulo: ","Error\n","Overflow", nombre,50,2))
        {
            if(!getValidInt("Horas Trabajadas: ","Error",&duracion,0,500,2))
            {
                if(!getValidInt("Sueldo: ","Error",&duracion,0,500,2))
                {
                    if(!getValidAlfaNumerico("Descripcion: ","Error\n","Overflow", descripcion,50,2))
                    {
                        if(!getValidInt("Puntaje: ","Error\n",&puntaje,0,100,2))
                        {
                            if(!getValidStringAllCharacters("Link de Imagen: ","Error\n","Overflow", linkImagen,50,2))
                            {
                                this[*cantidad] = movie_newParametros(titulo,genero,duracion,descripcion,puntaje,linkImagen);
                                (*cantidad)++;
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 *  Borra una movie del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la movie o no
 */
void eliminarPelicula(Employee* this[],int *cantidad,char *pelicula){

    int i,j;
    int comp;

    if(this != NULL){

        for(i=0;i<*cantidad;i++){
            comp = strcmp(pelicula,this[i]->titulo);
            if(comp == 0){

                this[i]= NULL;
                for(j=i;j<*cantidad-1;j++){

                    this[j] = this[j+1];
                }
                break;
            }
            else if(i==*cantidad-1){
                printf("Pelicula no encontrada\n");
            }
        }
    }
}

int generarPagina(Employee* this[], int cantidad, int pelicula,char* path)
{
    int retorno = -1;

    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];

    FILE* pFile;
    pFile = fopen(path,"a");
    if(pFile != NULL && this != NULL)
    {

        movie_getTitulo(this[pelicula],titulo);
        movie_getGenero(this[pelicula],genero);
        movie_getDuracion(this[pelicula],&duracion);
        movie_getDescripcion(this[pelicula],descripcion);
        movie_getPuntaje(this[pelicula],&puntaje);
        movie_getLinkImagen(this[pelicula],linkImagen);

        html_primerInstancia(path,pFile);
        fprintf(pFile,"%s",linkImagen);
        html_segundaInstancia(path,pFile);
        fprintf(pFile,"%s",titulo);
        html_terceraInstancia(path,pFile);
        fprintf(pFile,"%s",genero);
        html_cuartaInstancia(path,pFile);
        fprintf(pFile,"%d",puntaje);
        html_quintaInstancia(path,pFile);
        fprintf(pFile,"%d",duracion);
        html_sextaInstancia(path,pFile);
        fprintf(pFile,"%s",descripcion);
        html_septimaInstancia(path,pFile);
    }
    fclose(pFile);

    return retorno;
}

int movie_buscarPelicula(Employee* this[], int cantidad, char* pelicula){

    int retorno = -1;
    int i;

    for(i=0;i<cantidad;i++){

        if(strcmp(this[i]->titulo,pelicula)==0){

            retorno = 0;
        }
    }

    return retorno;
}

int movie_buscarIndexPelicula(Employee* this[], int cantidad, char* pelicula){

    int retorno = -1;
    int i;

    for(i=0;i<cantidad;i++){

        if(strcmp(this[i]->titulo,pelicula)==0){

            retorno = i;
            return retorno;
        }
    }

    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

static int isValidNombre(char* nombre);


Employee* employee_new()
{

    return malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr)
{
    Employee* this;
    this = employee_new();
    int id;
    char nombre[128];
    int horasTrabajadas;

    //Si ya valide

    id=atoi(idStr);
    strcpy(nombre,nombreStr);
    horasTrabajadas = atoi(horasTrabajadasStr);

    empleados_setId(this,id);
    empleados_setNombre(this,nombre);
    empleados_setHorasTrabajadas(this,horasTrabajadas);

    return this;
}

void empleados_delete(Employee* this)
{
    free(this);
}

int empleados_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int empleados_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}

int empleados_setId(Employee* this, int id)
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

int empleados_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int empleados_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}

int empleados_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        retorno = 0;
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}

int empleados_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->sueldo = sueldo;
    }
    return retorno;
}

int empleados_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        retorno = 0;
        *sueldo = this->sueldo;
    }
    return retorno;
}


static int isValidNombre(char* nombre)
{
    return 1;
}



#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];

    Employee* auxEmployee;


    int auxInt;

    //int id2;

    //int horasTrabajadas;

    pFile = NULL;
    pFile = fopen("data.csv","r");
    char nombre2[256];
    if(pFile != NULL && pArrayListEmployee != NULL){

        while(!feof(pFile)){ // == 0

            fscanf(pFile,"%[^,],%[^,],%[^,\n]\n",id,nombre,horasTrabajadas);
            //printf("\n%s - %s - %s\n",nombre,horasTrabajadas);
            auxEmployee = employee_newParametros(id,nombre,horasTrabajadas);
            ll_add(pArrayListEmployee,auxEmployee);
         /* uxEmpleados = empleados_new();
            empleados_setNombre(auxEmpleados,nombre);
            empleados_setHorasTrabajadas(auxEmpleados,horasTrabajadas2);
            al_add(listaEmpleados,auxEmpleados);
            auxInt = al_len(listaEmpleados);*/
        }
        //printf("%d\n",auxInt);

    }
    fclose(pFile);
    return 1; // OK
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}


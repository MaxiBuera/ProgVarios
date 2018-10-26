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
    FILE* pFile = fopen("data.txt","r");
    //2,sarasa,pepe,27
    char buffer1[128];

    //fscanf(pFile,"%d,%[^,],%[^;];%d\n",%a,buf1,buf2,buf3,buf4

    scanf("%d",&var);
    do{
        if(fscanf(pFile,"%d,%[^,],%[^;];%d\n",%a,buf1,buf2,buf3,buf4)==4)
        {

            Employee* e = newEmployeeConPar(buf1,buf2,buf3);
            ll_add(pArrayListEmployee,e);
        }
        break;

    }while(!feof(pFile));


    return 1;
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

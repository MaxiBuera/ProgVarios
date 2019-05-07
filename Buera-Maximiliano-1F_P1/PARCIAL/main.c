#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"
#define OCUPADO 0
#define LIBRE 1
#define AUTORES 5
#define LIBROS 10
#define SOCIOS 5
#define PRESTAMOS 5

//AUTORES LIBROS

int main()
{

    int menu;
    int index;
    int auxiliarId;
    int flagMenu = 0;

    eSocio arraySocios[SOCIOS];
    socio_inicializar(arraySocios,SOCIOS);

    eAutor arrayAutores[AUTORES];
    autor_inicializar(arrayAutores,AUTORES);

    eLibro arrayLibros[LIBROS];
    libro_inicializar(arrayLibros,LIBROS);

    ePrestamo arrayPrestamos[PRESTAMOS];
    prestamo_inicializar(arrayPrestamos,PRESTAMOS);


//Autor

    autor_altaForzada(arrayAutores,AUTORES,"Pablo","Gimenez");
    autor_altaForzada(arrayAutores,AUTORES,"Mariano","Alfonso");

    autor_ordenarXapellido(arrayAutores,AUTORES,0);
    autor_ordenarXnombre(arrayAutores,AUTORES,0);

    autor_listado(arrayAutores,AUTORES);

    printf("\n");
//Libros


    libro_altaForzada(arrayLibros,LIBROS,"HarryPotter",0);
    libro_altaForzada(arrayLibros,LIBROS,"ElPrincipito",1);

    libro_ordenarXtitulo(arrayLibros,LIBROS,0);

    libro_listado(arrayLibros,LIBROS);


    printf("\n");
//Socios

    socio_altaForzada(arraySocios,SOCIOS,"Alberto","Diaz","m","42458798","alberto@mail.com",4,5,1999);
    socio_altaForzada(arraySocios,SOCIOS,"Mariela","Perez","f","47328941","mariela@mail.com",1,12,2009);

    socio_ordenarXapellido(arraySocios,SOCIOS,0);
    socio_ordenarXnombre(arraySocios,SOCIOS,0);

    socio_listado(arraySocios,SOCIOS);

    printf("\n");
//Prestamos

    prestamo_altaForzada(arrayPrestamos,PRESTAMOS,0,0,2,5,2018);
    prestamo_altaForzada(arrayPrestamos,PRESTAMOS,1,1,10,9,2015);

    printf("\n");



    do{

        getValidInt("\n\n1.Alta Socio\n2.Modificar Socio\n3.Baja Socio\n4.Listas\n5.Prestamos\n6.Salir\n","\nNo valida\n",&menu,1,6,1);
        switch(menu)
        {

            case 1:

                index = socio_buscarLugarLibre(arraySocios,SOCIOS);
                if(index >= 0){

                    socio_alta(arraySocios,SOCIOS,index);
                    flagMenu = 1;
                    break;
                }

            case 2:

                if(flagMenu != 0){

                    getValidInt("ID de Socio: ","\nID de Socio No valido\n",&auxiliarId,0,SOCIOS,2);
                    socio_modificacion(arraySocios,SOCIOS,auxiliarId);
                    break;
                }
                else{

                    printf("\nDebe ingresar un Socio\n");
                    break;
                }

            case 3:

                if(flagMenu != 0){

                    getValidInt("ID de Socio: ","\nID de Socio No valido\n",&auxiliarId,0,SOCIOS,2);
                    socio_baja(arraySocios,SOCIOS,auxiliarId);
                    break;
                }

                else{

                    printf("\nDebe ingresar un Socio\n");
                    break;
                }

            case 4:

                if(flagMenu != 0){

                    socio_ordenarXapellido(arraySocios,SOCIOS,0);
                    socio_ordenarXnombre(arraySocios,SOCIOS,0);
                    socio_listado(arraySocios,SOCIOS);
                    break;
                }

                else{

                    printf("\nDebe ingresar un Socio\n");
                    break;
                }

            case 5:

                if(flagMenu != 0){

                    //prestamos(arrayPrestamos,SOCIOS);
                    break;
                }
                else{

                    printf("\nDebe ingresar un Socio\n");
                    break;
                }
        }

    }while(menu != 6);


    return 0;
}

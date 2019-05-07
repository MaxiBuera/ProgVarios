#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idPrestamo;
    int idLibro;
    int idSocio;
    eFecha fechaPrestamo;
    int isEmpty;
}ePrestamo;

#endif // PRESTAMOS_H_INCLUDED

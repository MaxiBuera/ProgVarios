#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFechaP;

typedef struct{
    int idPrestamos;
    int idLibro;
    int idSocio;
    eFechaP fechaPrestamo;
    int isEmpty;
}ePrestamo;

#endif // PRESTAMOS_H_INCLUDED

int prestamo_inicializar(ePrestamo* arrayPrestamo, int limite);
int prestamo_alta(ePrestamo* arrayPrestamos, int limite, int index, eLibro* arrayLibros, int limiteLibros, eSocio* arraySocios, int limiteSocios);
int prestamo_altaForzada(ePrestamo* arrayPrestamos,int limite,int idLibro, int idSocio,int dia, int mes, int anio);
int prestamo_modificacion(ePrestamo* arrayPrestamo, int limite, int index);
int prestamo_baja(ePrestamo* arrayPrestamo, int limite, int index);

int prestamo_buscarLugarLibre(ePrestamo* arrayPrestamo,int limite);
int prestamo_buscarPorId(ePrestamo* arrayPrestamo,int limite, int id);

int prestamo_listado(ePrestamo* arrayPrestamo,int limite);

int prestamo_ordenarXapellido(ePrestamo* arrayPrestamo,int limite, int orden);
int prestamo_ordenarXnombre(ePrestamo* arrayPrestamo,int limite, int orden);


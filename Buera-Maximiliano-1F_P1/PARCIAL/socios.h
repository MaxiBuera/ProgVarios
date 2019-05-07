#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idSocios;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char email[31];
    eFecha fecha;
    int isEmpty;
}eSocio;

#endif // SOCIOS_H_INCLUDED

int socio_inicializar(eSocio* arraySocios, int limite);
int socio_alta(eSocio* arraySocios, int limite, int index);
int socio_altaForzada(eSocio* arraySocios,int limite,char* apellido,char* nombre, char sexo, char* telefono, char* email, int dia,int mes,int anio);
int socio_modificacion(eSocio* arraySocios, int limite, int index);
int socio_baja(eSocio* arraySocios, int limite, int index);

int socio_buscarLugarLibre(eSocio* arraySocios,int limite);
int socio_buscarPorId(eSocio* arraySocios,int limite, int id);

int socio_listado(eSocio* arraySocios,int limite);

int socio_ordenarXapellido(eSocio* arraySocios,int limite, int orden);
int socio_ordenarXnombre(eSocio* arraySocios,int limite, int orden);


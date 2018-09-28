#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct{

    char cuit[20];
    int cantidadDias;
    char nombreVideo[70];
    int id;
    int isEmpty;

}Publicidad;

#endif // PUBLICIDAD_H_INCLUDED

int publicidad_inicializar(Publicidad* arrayPublicidades, int limite);
int publicidad_alta(Publicidad* arrayPublicidades,Pantalla* arrayPantallas, int limite, int index);
int publicidad_altaForzada(Publicidad* arrayPublicidades,int limite,char* cuit,int cantidadDias, char* nombreVideo);
int publicidad_mostrar(Publicidad* arrayPublicidades,int limite);
int publicidad_modificarPublicacion();
int publicidad_cancelarPublicacion();

int publicidad_buscarLugarLibre(Publicidad* arrayPublicidades,int limite);
int publicidad_modificarPublicacion(Publicidad* arrayPublicidades,int limite, char* cuit);

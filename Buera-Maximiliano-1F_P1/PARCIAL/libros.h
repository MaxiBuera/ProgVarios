#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct{
    int idLibros;
    char titulo[51];
    int idAutores;
    int isEmpty;
}eLibro;

#endif // LIBROS_H_INCLUDED

int libro_inicializar(eLibro* arrayLibros, int limite);
int libro_alta(eLibro* arrayLibros, int limite, int index);
int libro_altaForzada(eLibro* arrayLibros,int limite,char* apellido,char* nombre);
int libro_modificacion(eLibro* arrayLibros, int limite, int index);
int libro_baja(eLibro* arrayLibros, int limite, int index);

int libro_buscarLugarLibre(eLibro* arrayLibros,int limite);
int libro_buscarPorId(eLibro* arrayLibros,int limite, int id);

int libro_listado(eLibro* arrayLibros,int limite);

int libro_ordenarXapellido(eLibro* arrayLibros,int limite, int orden);
int libro_ordenarXnombre(eLibro* arrayLibros,int limite, int orden);

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
int libro_alta(eLibro* arrayLibros, int limite, int index, eAutor* arrayAutores, int limiteAutores);
int libro_altaForzada(eLibro* arrayLibros,int limite,char* titulo,int idAutor);
int libro_modificacion(eLibro* arrayLibros, int limite, eAutor* arrayAutores, int limiteAutores,int index);
int libro_baja(eLibro* arrayLibros, int limite, int index);

int libro_buscarLugarLibre(eLibro* arrayLibros,int limite);
int libro_buscarPorId(eLibro* arrayLibros,int limite, int id);

int libro_listado(eLibro* arrayLibros,int limite);

int libro_ordenarXtitulo(eLibro* arrayLibros,int limite, int orden);

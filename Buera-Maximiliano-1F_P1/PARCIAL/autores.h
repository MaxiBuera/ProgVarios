#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct{
    int idAutores;
    char apellido[31];
    char nombre[31];
    int isEmpty;
}eAutor;

#endif // AUTORES_H_INCLUDED

int autor_inicializar(eAutor* arrayAutores, int limite);
int autor_alta(eAutor* arrayAutores, int limite, int index);
int autor_altaForzada(eAutor* arrayAutores,int limite,char* apellido,char* nombre);
int autor_modificacion(eAutor* arrayAutores, int limite, int index);
int autor_baja(eAutor* arrayAutores, int limite, int index);

int autor_buscarLugarLibre(eAutor* arrayAutores,int limite);
int autor_buscarPorId(eAutor* arrayAutores,int limite, int id);

int autor_listado(eAutor* arrayAutores,int limite);

int autor_ordenarXapellido(eAutor* arrayAutores,int limite, int orden);
int autor_ordenarXnombre(eAutor* arrayAutores,int limite, int orden);

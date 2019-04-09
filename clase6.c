#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

  char saludo[10];

    strcpy(saludo,"hola");
    /*//puts("hola");
    fflush(stdin);
    //scanf("%s",saludo);
    fgets(saludo);
    printf("%s",saludo);
*/
    char buffer[64];
    int cantidad;

    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);

    cantidad = strlen(buffer);

    buffer[cantidad-1] = '\0';

    //printf("%s", buffer);

    /*strupr(saludo); //-> Mayusculas
    printf("%s",saludo);
    strlwr(saludo); //-> Minusculas
    printf("%s",saludo);*/

    strcat(saludo,buffer);
    printf("%s",saludo);

    return 0;
}


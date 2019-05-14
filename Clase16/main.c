#include <stdio.h>
#include <stdlib.h>

void primeraFuncion(int a[], int limite);
void segundaFuncion(int a[], int limite);
void terceraFuncion(int *p, int limite);
void cuartaFuncion(int *p, int limite);

int main()
{
    /*int n[3]={1,2,3};
    int *ptr;
    int i;
    ptr=n;*/

    /*
    for(i=0;i<3;i++){

        printf("%d",ptr[i]);
    }
    printf("\n");
    for(i=0;i<3;i++){

        printf("%d",*(n+i));

    }*/

    /*int a=1;
    int *punteroInt;
    int **punteroPuntero;
    punteroInt = &a;
    punteroPuntero = &punteroInt;

    printf("%d\n",a);
    printf("%d\n",*punteroInt);
    printf("%d",**punteroPuntero);*/

    int a[3]={1,2,3};
    int *p;
    p = a;

    //primeraFuncion(a,3);
    //segundaFuncion(a,3);
    //terceraFuncion(p,3);
    cuartaFuncion(p,3);

    return 0;
}

void primeraFuncion(int a[], int limite){

    int i;

    for(i=0;i<limite;i++){

        printf("%d\n",a[i]);
    }
}

void segundaFuncion(int a[], int limite){

    int i;

    for(i=0;i<limite;i++){

        printf("%d\n",*(a+i));
    }
}

void terceraFuncion(int *p, int limite){

    int i;

    for(i=0;i<limite;i++){

        printf("%d\n",p[i]);
    }
}

void cuartaFuncion(int *p, int limite){

    int i;

    for(i=0;i<limite;i++){

        printf("%d\n",*(p+i));
    }
}

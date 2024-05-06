#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CANT_NOMBRE 5
#define MAX_LARGO 100


int main()
{
int cant_nombres;
printf("Agregue la cantidad de nombres que quiere ingresar: ");
scanf("%d", &cant_nombres);
fflush(stdin);
  char **nombres;
  nombres = (char **)malloc(cant_nombres*sizeof(char*));
    for (int i = 0; i < cant_nombres; i++)
    {
    nombres[i]=(char *)malloc(MAX_LARGO*sizeof(char));   
        printf("Escriba su nombre: ");
        gets(nombres[i]);

    }

    for (int i = 0; i < cant_nombres; i++)
    {
        printf("El nombre numero %d es: ", i+1);
    
        puts(nombres[i]);

    }

    return 0;
}
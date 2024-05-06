#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CANT_NOMBRE 5
#define MAX_LARGO 100


int main()
{

  char **nombres;
  nombres = (char **)malloc(CANT_NOMBRE*sizeof(char*));
    for (int i = 0; i < 5; i++)
    {
    nombres[i]=(char *)malloc(MAX_LARGO*sizeof(char));   
        printf("Escriba su nombre: ");
        gets(nombres[i]);

    }

    for (int i = 0; i < 5; i++)
    {
        printf("El nombre numero %d es: ", i+1);
    
        puts(nombres[i]);

    }

    return 0;
}
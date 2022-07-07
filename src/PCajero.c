#include <stdio.h>
#include <windows.h>



	int Codigo[4]={03732532,25546313,02672326,02531423};		
	int Clave[4]={12233,14273,02546,12953};
	char *Nombre[4]={"Joel","Alexandra","Gianfranco","Luis"};

	int CodUni;
	int Pin;

	int i=0;
	int v=1;
	int posicion;

int getMenu(){
	int op;

	return op;
}


int main()
{
int opcion;

printf("POLICAJERO");
printf("\nBienvenido a tu cajero de confianza");
printf("\n1.Iniciar Sesion");
printf("\n2.Registrarse");
printf("\n");
scanf("%i", &opcion);

switch (opcion)
	{
	case 1: 
		printf("Ingrese su codigo Unico: ");
		scanf("%i",&CodUni);
			while (CodUni =! Codigo[i])
			{
				posicion=i;
			} i++;
		printf("Ingrese su clave: ");
		scanf("%i",&Pin);
			while ((Pin =! Clave[i]) &&  v<4)
			{
				printf("La contraseña ingresada es incorrecta.");
				printf("\nVuelva a ingresarla porfavor.");
				scanf("%i",Pin);
				v++ ;
			}
	break;

	case 2:
		printf("Disponible para la siguiente version :3 ");
	break;

	default:
		printf("El numero ingresado no es valido :c");
	break;
	}
}

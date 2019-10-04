#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include "Funciones.h"

#define TAM 1000

int main()
{
    int id = 1000;
    int flag = 0;
    employee empleado[TAM];
    char salir = 'n';

    initEmployees(empleado, TAM);

    do
    {
        for(int i=0; i < TAM; i++)
        {
            if(empleado[i].isEmpty == 0)
            {
                flag = 1;
                break;
            }
        }

        switch(menu())
        {
            case 1:
                if(addEmployees(empleado, TAM, id));
                {
                    id++;
                }
                break;

            case 2:
                if(flag == 1)
                {
                    modifyEmployee(empleado, TAM);
                }
                else
                {
                    printf("\nNo hay empleados cargados en el sistema\n\n");
                }
                break;


            case 3:
                if(flag == 1)
                {
                    removeEmployee(empleado, TAM);
                }
                else
                {
                    printf("\nNo hay empleados cargados en el sistema\n\n");
                }
                break;


            case 4:
                if(flag == 1)
                {
                    printReports(empleado, TAM);
                }
                else
                {
                    printf("\nNo hay empleados cargados en el sistema\n\n");
                }
                break;

            case 6:
                printEmployees(empleado, TAM);
                break;

            case 5:
                printf("\nDesea salir?(s/n): ");
                fflush(stdin);
//                salir = getche();
                while(salir != 's' && salir != 'n')
                {
                    printf("\nError. Ingrese s o n: ");
                    fflush(stdin);
//                    salir = getche();
                }
                printf("\n\n");
                break;
        }
        system("pause");

        flag = 0;
    }
    while(salir == 'n');

    return 0;
}

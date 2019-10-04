#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define TAM 1000

struct
    {
        int id;
        int sector;
        int isEmpty;
        float salary;
        char name[51];
        char lastName[51];

    }typedef employee;

int initEmployees(employee* list,int len);
int addEmployees(employee* list,int len, int id, char name[], char lastName[], float salary, int sector);

int main()
{
    int retorno;
    int opcion;
    int id;
    int sector;
    int isEmpty;
    float salary;
    char name[51];
    char lastName[51];
    employee empleados[TAM];

    retorno=initEmployees(empleados,TAM);

    printf("\n*****Menu de opciones*****\n\n");
    printf("1. Alta.\n");
    printf("2. Modificar.\n");
    printf("3. Baja.\n");
    printf("4. Informar el listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("%s%c%s","5. Informar el total y promedio de los salarios, y cu",160,"ntos empleados superan el salario promedio.\n");
    scanf("%i", &opcion);
    switch(opcion)
    {
    case 1:
            printf("Ingrese su ID: ");
            scanf("%i", &id);
            printf("Ingrese su sector: ");
            scanf("%i", &sector);
            printf("Ingrese su salario: ");
            scanf("%f.2", &salary);
            printf("Ingrese su nombre: ");
            gets(name);
            printf("Ingrese su apellido: ");
            scanf("%s", lastName);
            retorno=addEmployees(empleados, TAM, id, name, lastName, salary, sector);

        break;

    case 2:

        break;

    case 3:

        break;
    case 4:

        break;

    case 5:

        break;
    }
}

int initEmployees(employee* list,int len)
{
    for(int i=0;i<len;i++)
        {
            list[i].isEmpty=TRUE;
        }
    return 0;
}

int addEmployees(employee* list,int len, int id, char name[], char lastName[], float salary, int sector)
{
    for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
                {
                    list[i].id = id;
                    strcpy(list[i].name, name);
                    strcpy(list[i].lastName, lastName);
                    list[i].salary = salary;
                    list[i].sector = sector;
                    return 0;
                }
        }
}

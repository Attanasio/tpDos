#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"

/** \brief Se elige una opcion en el menu de empleados.
 *
 * \return Retorna el numero de la opcion elegida.
 *
 */

int menu()
{
    int opcion;

    system("cls");
    printf("***** MENU DE EMPLEADOS *****\n\n");
    printf("1-Alta empleado\n");
    printf("2-Modificar empleado\n");
    printf("3-Baja empleado\n");
    printf("4-Informes empleado\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


/** \brief Se elige una opcion en el menu de empleados.
 *
 * \return Retorna el numero de la opcion elegida.
 */

int menuReports()
{
    int opcion;

    system("cls");
    printf("***** MENU DE INFORMES *****\n\n");
    printf("1-Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("2-Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
    printf("3-Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


/** \brief Marca todas las posiciones del vector que estan vacias.
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 *
 */

void initEmployees(employee vec[], int len)
{
    for(int i=0; i < len; i++)
    {
        vec[i].isEmpty = 1;
    }
}


/** \brief Busca un vector vacio y devuelve su posicion.
 *
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 * \return Devuelve el valor de indice con la posicion del vector que se encontro vacio y si
 *         no se encontro ninguno vacio devuelve -1
 */

int findFree(employee vec[], int len)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}


/** \brief Busca un vector que tenga el mismo id que se le pasa y devuelve su posicion
 *
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 * \param id int  Valor del id del empleado
 * \return Retorna el valor de indice con la posicion del vector con igual id y si no encuentra
 *         ninguno con ese id devuelve -1
 */

int findEmployeeById(employee vec[], int len, int id)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}


/** \brief Se ingresa los datos que se van a cargan en el vector de estructura employee y se valida
 *         el sistema no este lleno
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 * \param id int  Valor del id del empleado
 * \return Devuelve 0 si no se dio de alta un empleado y un 1 si se dio de alta
 *
 */

int addEmployees(employee vec[], int len, int id)
{
    int ok = 0;
    int index;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    system("cls");

    printf("***** Alta empleado *****\n\n");

    index = findFree(vec, len);

    if(index == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(name);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lastName);

        printf("Ingrese salario: ");
        scanf("%f", &salary);

        printf("Ingrese sector: ");
        scanf("%d", &sector);

        vec[index] = newEmployee(id, name, lastName, salary, sector);

        printf("\nAlta empleado exitosa!\n\n");

        ok = 1;
    }

    return ok;
}


/** \brief Recibe todos los datos del empleado y los carga en el vector de estructa.
 *
 * \param id int  Valor del id del empleado
 * \param name char  Valor del nombre del empleado
 * \param lastName char  Valor del apellido del empleado
 * \param salary float  Valor del salario del empleado
 * \param sector int  Valor del sector del empleado
 * \return Devuelve el vector de estructura de empleados con sus datos cargados.
 *
 */

employee newEmployee(int id, char name[], char lastName[], float salary, int sector)
{
    employee em;

    em.id = id;
    strcpy(em.name, name);
    strcpy(em.lastName, lastName);
    em.salary = salary;
    em.sector = sector;
    em.isEmpty = 0;

    return em;
}


/** \brief Imprime el vector en la posicion que se le pasa
 *
 * \param em employee  Valor de una posicion del vector de eEmployee
 *
 */

void printEmployee(employee em)
{
    printf(" %d %10s  %12s    %8.2f     %2d\n", em.id, em.name, em.lastName, em.salary, em.sector);
}


/** \brief Imprime en columnas todos los vectores que estan cargados
 *
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 *
 */

void printEmployees(employee vec[], int len)
{
    int flag = 0 ;

    printf("  Id      Nombre      Apellido     Salario   Sector\n\n");

    for(int i=0; i < len; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            printEmployee(vec[i]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados que mostar\n\n");
    }

    printf("\n\n");

}


/** \brief Modifica los valores del vector que se solicita mediente el id del empleado
 *
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 * \return Retorna 0 si no se modifica y 1 si se realizo alguna modificacion
 *
 */

int modifyEmployee(employee vec[], int len)
{
    int ok = 0;
    int id;
    int index;
    int opcion;
    char salir = 'n';

    system("cls");

    printf("***** Modificar empleado *****\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployeeById(vec, len, id);

    if(index == -1)
    {
        printf("\nNo existe un empleado con ese id\n\n");
    }
    else
    {
        do
        {
            system("cls");

            printf("***** Modificar empleado *****\n\n");

            printf("  Id      Nombre      Apellido     Salario   Sector\n\n");
            printEmployee(vec[index]);

            printf("\n1- Modificar nombre\n");
            printf("2- Modificar apellido\n");
            printf("3- Modificar salario\n");
            printf("4- Modificar sector\n");
            printf("5- Salir\n\n");
            printf("Ingrese opcion: ");
            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    printf("\nIngrese nuevo nombre: ");
                    fflush(stdin);
                    gets(vec[index].name);
                    ok = 1;
                    break;

                case 2:
                    printf("\nIngrese nuevo apellido: ");
                    fflush(stdin);
                    gets(vec[index].lastName);
                    ok = 1;
                    break;

                case 3:
                    printf("\nIngrese nuevo salario: ");
                    scanf("%f", &vec[index].salary);
                    ok = 1;
                    break;

                case 4:
                    printf("\nIngrese nuevo sector: ");
                    scanf("%d", &vec[index].sector);
                    ok = 1;
                    break;

                case 5:
                    printf("\nDesea salir?(s/n): ");
                    fflush(stdin);
                    salir = getche();
                    printf("\n\n");

                    while(salir != 's' && salir != 'n')
                    {
                        printf("Error. Ingrese s o n: ");
                        fflush(stdin);
                        salir = getche();
                        printf("\n\n");
                    }
                    break;

                default:
                    printf("\nOpcion invalida\n\n");
                    system("pause");
            }
        }
        while(salir == 'n');
    }

    return ok;
}


/** \brief Le da una baja logica al vector que se le pasa mediente el id del empleado,
 *         poniendo la variable isEmpty en 1
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 * \return Retorna un 0 si no se concreto la baja y un 1 si se concreto la baja
 *
 */

int removeEmployee(employee vec[], int len)
{
    int ok = 0;
    int id;
    int index;
    char confirm;

    system("cls");

    printf("***** Baja empleado *****\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployeeById(vec, len, id);

    if(index == -1)
    {
        printf("No existe un empleado con ese id\n\n");
    }
    else
    {
        printf("\n  Id      Nombre      Apellido     Salario   Sector\n\n");
        printEmployee(vec[index]);

        printf("\nDesea darle de baja?(s/n): ");
        fflush(stdin);
        scanf("%c", &confirm);
        while(confirm != 's' && confirm != 'n')
        {
            printf("\nError. Ingrese s o n: ");
            fflush(stdin);
            scanf("%c", &confirm);
        }

        if(confirm == 's')
        {
            vec[index].isEmpty = 1;
            ok = 1;

            printf("\nBaja empleado exitosa!\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja de empleado\n\n");
        }
    }
    return ok;
}


/** \brief Muestra y ejecuta los informes
 *
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 *
 */

void printReports(employee vec[], int len)
{
    char salir = 'n';
    int order;

    do
    {
        switch(menuReports())
        {
            case 1:
                printf("\nPresione 1 para ordenar en forma ascendente y 0 en forma descendente: ");
                scanf("%d", &order);
                sortEmployees(vec, len, order);
                break;

            case 2:
                getSalary(vec, len);

                break;

            case 3:
                printf("\nDesea salir?(s/n): ");
                fflush(stdin);
                salir = getche();
                printf("\n\n");
                break;

            default:
                printf("\nOpcion invalida\n\n");
        }
    }
    while(salir == 'n');
}


/** \brief Ordena los vectores que se le pasan alfabeticamente por apellido y por sector
 *
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 * \param orden int  Valor del ordenamiento de los vectores
 *
 */

void sortEmployees(employee vec[], int len, int order)
{
    employee auxEmployee;

    system("cls");

    for(int i=0; i < len-1; i++)
    {
        for(int j=i+1; j < len; j++)
        {
            if(order)
            {
                if(strcmp(vec[i].lastName, vec[j].lastName) > 0)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                else if(strcmp(vec[i].lastName, vec[j].lastName) == 0 && vec[i].sector > vec[j].sector)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
            }
            else
            {
                if(strcmp(vec[i].lastName, vec[j].lastName) < 0)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
                else if(strcmp(vec[i].lastName, vec[j].lastName) == 0 && vec[i].sector < vec[j].sector)
                {
                    auxEmployee = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmployee;
                }
            }
        }
    }

    if(order)
    {
        printf(" Empleados ordenados en forma ascendente\n\n");

        printEmployees(vec, len);
    }
    else
    {
        printf(" Empleados ordenados en forma descendente\n\n");

        printEmployees(vec, len);
    }

    system("pause");
}


/** \brief Devuelve el total de los salarios y el promedio, y que empleados
 *         tienen un salario por encima del promedio
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 *
 */

void getSalary(employee vec[], int len)
{
    float acumulador = 0;
    float promedio;
    int contadorPromedio = 0;
    int contadorEmployees = 0;

    system("cls");

    for(int i=0; i < len; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            acumulador = acumulador + vec[i].salary;
            contadorPromedio++;
        }
    }
    promedio = acumulador / contadorPromedio;

    for(int i=0; i < len; i++)
    {
        if(vec[i].salary > promedio && vec[i].isEmpty == 0)
        {
            contadorEmployees++;
        }
    }
    printf("\nEl total de los salarios es: %.2f y el promedio es: %.2f\n\n", acumulador, promedio);
    printf("El numero de empleados que supera el promedio es: %d\n\n", contadorEmployees);
    system("pause");
}


/** \brief Se utiliza para probar el funcionamiento del programa, dandole
 *         los datos cargados de algunos empleados
 * \param vec[]  employee  Vector de estructura
 * \param len int  Longitud del vector
 * \param cantidad it  Cantidad de vectores que se utilizan en el programa
 * \return Retorna la cantidad de empleados que se cargaron en el sistema
 *
 */

int hardcodearEmpleados(employee vec[], int len, int cantidad)
{
    int cont = 0;

    employee suplentes[] =
    {
        { 1000, "Juan", "Perez", 6000, 4, 0},
        { 1001, "Alberto",  "Rodriguez", 2000, 8, 0},
        { 1002, "Ana",  "Diaz", 2050, 3, 0},
        { 1003, "Luis",  "Perez", 34500, 5, 0},
        { 1004, "Alicia",  "Sanchez", 1200, 10, 0},
        { 1005, "Diego",  "Rodriguez", 800, 7, 0},
        { 1006, "Sofia",  "Medina", 2500, 4, 0},
        { 1007, "Clara",  "Perez", 20000, 6, 0},
        { 1008, "Mauro",  "Perez", 3000, 4, 0},
        { 1009, "Lucas",  "Sabatini", 2000, 4, 0},
        { 1010, "Agustin",  "Perez", 45500, 4, 0},
    };

    if( cantidad <= 10 && len >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

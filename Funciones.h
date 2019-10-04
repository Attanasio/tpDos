//#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} employee;

//#endif // FUNCIONES_H_INCLUDED

int menu();
int menuReports();
void initEmployees(employee vec[], int len);
int findFree(employee vec[], int len);
int findEmployeeById(employee vec[], int len, int id);
int addEmployees(employee vec[], int len, int id);
employee newEmployee(int id, char name[], char lastName[], float salary, int sector);
int removeEmployee(employee vec[], int len);
int modifyEmployee(employee vec[], int len);
void printEmployee(employee em);
void printEmployees(employee vec[], int len);
void printReports(employee vec[], int len);
void sortEmployees(employee vec[], int len, int orden);
void getSalary(employee vec[], int len);
int hardcodearEmpleados(employee vec[], int len, int cantidad);

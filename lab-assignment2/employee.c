/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;
/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    // Add your code here
     employee_t* thisEmployee;
    for (int i = 0; i<n; i++) {
        thisEmployee = &s[i];
        printf("Enter the employeeID, Name, Designation and Department of Employee %d:\n",i+1);
        scanf("%d %s %s %s", &(thisEmployee->empId),  thisEmployee->Name, thisEmployee->Designation, thisEmployee->Dept);

    }
}
/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    // Add your code here
    employee_t* thisEmployee;
    for (int i = 0; i<n; i++) {
        thisEmployee = &s[i];
        printf("The details of the Employee %d:\n"
                " empId: %d\n Name: %s\n Designation: %s\n Dept: %s\n",
                i+1 ,thisEmployee->empId,  thisEmployee->Name, thisEmployee->Designation, thisEmployee->Dept);

    }
}

/*----------Main Program--------*/
int main()

{
    // Main Function to print the employee details
    int n;
    
    printf("Enter the number of employees: ");
    scanf("%d",&n);

    // emp is a pointer to a list of the pointers for each employee
    employee_t *emp = (employee_t *)malloc(n * sizeof(employee_t));

    
    readData(n, emp);
    display(n, emp);


    free(emp);


     

}


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int empID;
    char name[30];
    char dept[25];
    unsigned int salary;
    unsigned int age;
} employee;

void readData(char filename[])
{
    FILE *fp;
    employee e;

    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Error in opening file\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%u", &e.empID);

    printf("Enter Name: ");
    scanf("%s", e.name);

    printf("Enter Department: ");
    scanf("%s", e.dept);

    printf("Enter Salary: ");
    scanf("%u", &e.salary);

    printf("Enter Age: ");
    scanf("%u", &e.age);

    fprintf(fp, "%u %s %s %u %u\n",
            e.empID, e.name, e.dept, e.salary, e.age);

    fclose(fp);
}

void display(char filename[])
{
    FILE *fp;
    employee e;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error in opening file\n");
        return;
    }

    while (fscanf(fp, "%u %29s %24s %u %u",
                  &e.empID, e.name, e.dept,
                  &e.salary, &e.age) == 5)
    {
        printf("ID        : %u\n", e.empID);
        printf("Name      : %s\n", e.name);
        printf("Department: %s\n", e.dept);
        printf("Salary    : %u\n", e.salary);
        printf("Age       : %u\n\n", e.age);
    }

    fclose(fp);
}

void search(char filename[], unsigned int sid)
{
    FILE *fp;
    employee e;
    int found = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error in opening file\n");
        return;
    }

    while (fscanf(fp, "%u %29s %24s %u %u",
                  &e.empID, e.name, e.dept,
                  &e.salary, &e.age) == 5)
    {
        if (e.empID == sid)
        {
            printf("ID        : %u\n", e.empID);
            printf("Name      : %s\n", e.name);
            printf("Department: %s\n", e.dept);
            printf("Salary    : %u\n", e.salary);
            printf("Age       : %u\n", e.age);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee ID not found\n");

    fclose(fp);
}

int main()
{
    int choice;
    unsigned int sid;
    char filename[] = "employee.txt";

    do
    {
        printf("\n1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            readData(filename);
            break;
        case 2:
            display(filename);
            break;
        case 3:
            printf("Enter Employee ID: ");
            scanf("%u", &sid);
            search(filename, sid);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int empId, salary, age;
    char name[30], dept[25];
} Emp;

void readData(char filename[]) {
    FILE *fptr;
    Emp e;

    printf("Enter EmpId Salary Age Name Dept\n");
    scanf("%u %u %u %s %s", &e.empId, &e.salary, &e.age, e.name, e.dept);

    fptr = fopen(filename, "ab");
    if (fptr == NULL) exit(0);

    fwrite(&e, sizeof(Emp), 1, fptr);
    fclose(fptr);
}

void display(char filename[]) {
    FILE *fptr;
    Emp e;

    fptr = fopen(filename, "rb");
    if (fptr == NULL) exit(0);

    while (fread(&e, sizeof(Emp), 1, fptr) == 1) {
        printf("Name: %s\n", e.name);
        printf("Dept: %s\n", e.dept);
        printf("EmpId: %u\n", e.empId);
        printf("Salary: %u\n", e.salary);
        printf("Age: %u\n\n", e.age);
    }

    fclose(fptr);
}

void searchById(char filename[], unsigned int id) {
    FILE *fptr;
    Emp e;
    int found = 0;

    fptr = fopen(filename, "rb");
    if (fptr == NULL) return;

    while (fread(&e, sizeof(Emp), 1, fptr) == 1) {
        if (e.empId == id) {
            printf("Name: %s\n", e.name);
            printf("Dept: %s\n", e.dept);
            printf("EmpId: %u\n", e.empId);
            printf("Salary: %u\n", e.salary);
            printf("Age: %u\n", e.age);
            found = 1;
            break;
        }
    }

    if (!found) printf("Not found\n");

    fclose(fptr);
}

int main() {
    int choice;
    unsigned int id;
    char filename[] = "n.txt";

    while (1) {
        printf("1. Add\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readData(filename);
                break;
            case 2:
                display(filename);
                break;
            case 3:
                printf("Enter EmpId: ");
                scanf("%u", &id);
                searchById(filename, id);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}

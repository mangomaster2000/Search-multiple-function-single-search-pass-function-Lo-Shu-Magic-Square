#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // Defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

    // Defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    return 0;
}

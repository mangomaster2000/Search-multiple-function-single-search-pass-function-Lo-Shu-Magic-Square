#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // Defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *targetPhoneNumber);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double targetSalary);

    // Defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    // Search by # no match
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "999-999-999");
    if (matchPtr != NULL)
        printf("Employee ID 999-999-999 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 999-999-999 is NOT found in the record\n");
    // Search by # match
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1001L); // Notice the 'L' to indicate a long
    if (matchPtr != NULL)
        printf("Employee ID 1001 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1001 is NOT found in the record\n");
    // Search by salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 5.5);
    if (matchPtr != NULL)
        printf("Employee with salary 5.5 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 5.5 is NOT found in the record\n");
    // Search by salary not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.8);
    if (matchPtr != NULL)
        printf("Employee with salary 7.8 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 7.8 is NOT found in the record\n");
    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1011 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    return 0;
}
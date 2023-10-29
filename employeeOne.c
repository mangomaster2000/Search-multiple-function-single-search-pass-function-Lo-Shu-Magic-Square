#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, double targetNumber) {
    const PtrToConstEmployee endPtr = ptr + tableSize;
    
    for (; ptr < endPtr; ptr++) {
        if (ptr->number == targetNumber) {
            return (PtrToEmployee)ptr;
        }
    }
    
    return NULL;
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName) {
    const PtrToConstEmployee endPtr = ptr + tableSize;
    
    for (; ptr < endPtr; ptr++) {
        if (strcmp(ptr->name, targetName) == 0) {
            return (PtrToEmployee)ptr;
        }
    }
    
    return NULL; 
}
PtrToConstEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char *targetPhoneNumber){
    const PtrToConstEmployee endPtr=ptr+tableSize;
    for(;ptr<endPtr;ptr++){
        if(strcmp(ptr->phone, targetPhoneNumber)==0){
            return (PtrToEmployee)ptr;
        }
    }
    return NULL;
}
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary) {
    const PtrToConstEmployee endPtr = ptr + tableSize;
    
    for (; ptr < endPtr; ptr++) {
        if (ptr->salary == targetSalary) {
            return (PtrToEmployee)ptr;
        }
    }
    
    return NULL;
}
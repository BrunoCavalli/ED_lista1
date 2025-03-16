#include "PatientArray.h"

#include <iostream>
#include <string>

namespace PatientArray {


PatientArray* initializePatientArray() {
    PatientArray* pa = new PatientArray;

    pa->patients = new Patient[4];
    pa->size = 0;
    pa->capacity = 4;
    return pa;
}

void printPatients(PatientArray* pa) {
    std::cout << "capacity: " << pa->capacity << std::endl;
    std::cout << "Current Size :" << pa->size << std::endl;
    std::cout << "\n Patients: \n" << pa->patients << std::endl;

    for (int i = 0; i < pa->size; i++) {
        std::cout << "* " << pa->patients[i].arrival_time
        << " | " << pa->patients[i].severity
        << " | " << pa->patients[i].name << std::endl;
    }
    std::cout << std::endl;
}

void insertPatient(PatientArray *pa, Patient p) {
    if (pa->size == pa->capacity) {
        pa->capacity *= 2;
        Patient* newPatients = new Patient[pa->capacity];

        for (int i = 0; i < pa->size; i++) {
            newPatients[i] = pa->patients[i];
        }

        delete[] pa->patients;
        pa->patients = newPatients;
    }
    pa->patients[pa->size] = p;
    pa->size++;
}    

}


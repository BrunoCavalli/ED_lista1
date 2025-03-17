#include "PatientArray.h"

#include <iostream>
#include <string>
#include <cstring>

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


    int findNextPatient(PatientArray *pa) {
        if (pa->size == 0) return -1;
    
        int mostSevere = 0;
        for (int i = 1; i < pa->size; i++) {
            if (pa->patients[i].severity > pa->patients[mostSevere].severity ||
               (pa->patients[i].severity == pa->patients[mostSevere].severity &&
                strcmp(pa->patients[i].arrival_time, pa->patients[mostSevere].arrival_time) < 0)) {
                mostSevere = i;
            }
        }
    
        return mostSevere;
    }
    

    


// Implemente uma função para remover um paciente em uma posição qualquer, garantindo que os elementos restantes fiquem contíguos no array. 
// Se a quantidade de pacientes cair para menos de 1/4 da capacidade total, o array deve ser reduzido pela metade, mas nunca menor que 4.

void removePatient(PatientArray *pa, int index) {
    for (int i = index; i < pa->size -1; i++) {
        pa->patients[i] = pa->patients[i+1];
    }
    pa->size--;

    if (pa->size < pa->capacity/4 && pa->capacity > 4) {
        pa->capacity /= 2;
    }
}

Patient popNextPatient(PatientArray *pa) {
    int nextPatientIndex = findNextPatient(pa);
    Patient nextPatient = pa->patients[nextPatientIndex];
    removePatient(pa, nextPatientIndex);
    return nextPatient;
}

}


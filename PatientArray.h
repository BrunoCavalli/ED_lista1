#ifndef PATIENTARRAY_H
#define PATIENTARRAY_H

#include <iostream>
#include <string>

namespace PatientArray {

struct Patient {
    char name[50];
    int severity;         // Número positivo. Quanto maior, mais severo.
    char arrival_time[6]; // Formato "XXhYY"
};

struct PatientArray {
    Patient* patients;  // Ponteiro para o array de pacientes
    int size;           // Número de pacientes atualmente no array
    int capacity;       // Capacidade máxima do array
};

// Funções do TAD
PatientArray* initializePatientArray();
void printPatients(PatientArray *pa);
void insertPatient(PatientArray *pa, Patient p);
int findNextPatient(PatientArray *pa);
void removePatient(PatientArray *pa, int index);
Patient popNextPatient(PatientArray *pa);


}

#endif
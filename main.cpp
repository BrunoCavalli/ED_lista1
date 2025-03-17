#include "PatientArray.h"
#include <iostream>

int main() {
    // Initialize the patient array
    PatientArray::PatientArray* pa = PatientArray::initializePatientArray();

    // Create some patients
    PatientArray::Patient p1 = {"08:00", 1};
    PatientArray::Patient p2 = {"08:30", 3};
    PatientArray::Patient p3 = {"09:00", 4};
    PatientArray::Patient p4 = {"09:30", 2};

    // Insert patients into the array
    PatientArray::insertPatient(pa, p1);
    PatientArray::insertPatient(pa, p2);
    PatientArray::insertPatient(pa, p3);
    PatientArray::insertPatient(pa, p4);

    // Print the patients
    PatientArray::printPatients(pa);

    // Find the next patient
    int nextPatientIndex = PatientArray::findNextPatient(pa);
    std::cout << "Next patient index: " << nextPatientIndex << std::endl;
    std::cout << "Next patient: " << pa->patients[nextPatientIndex].name << std::endl;

    // Remove the next patient
    

    // Clean up
    delete[] pa->patients;
    delete pa;

    return 0;
}
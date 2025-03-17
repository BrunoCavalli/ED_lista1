#include "PatientArray.h"

// using namespace PatientArray;

int main() {
    PatientArray::PatientArray* pa = PatientArray::initializePatientArray();

    PatientArray::Patient p1 = {"Bruno", 5, "10h00"};
    PatientArray::Patient p2 = {"Roberto", 8, "09h30"};
    PatientArray::Patient p3 = {"Paulo Antonio", 3, "11h15"};
    PatientArray::Patient p4 = {"Dave", 8, "09h15"}; // chegou mais cedo mas é tratado depois?

    PatientArray::insertPatient(pa, p1);
    PatientArray::insertPatient(pa, p2);
    PatientArray::insertPatient(pa, p3);
    PatientArray::insertPatient(pa, p4);

    PatientArray::printPatients(pa);

    int next = PatientArray::findNextPatient(pa);
    std::cout << "Next patient index: " << next << " (" << pa->patients[next].name << ")\n";

    PatientArray::Patient treated = PatientArray::popNextPatient(pa);
    std::cout << "Treated patient: " << treated.name << "\n";

    printPatients(pa);

    std::cout << "Next patient index: " << next << " (" << pa->patients[next].name << ")\n";


    delete[] pa->patients;
    delete pa;

    return 0;
}

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int nA, nB;
    int *A, *B, **C; // แก้ไขให้ C เป็น double pointer สำหรับ dynamic allocation ของ array 2 มิติ
    
    cout << "Length of A: ";
    cin >> nA;
    
    A = new int[nA]; // แก้ไขการ allocate memory ให้ถูกต้อง
    cout << "Input Array A: ";
    for(int i = 0; i < nA; i++) cin >> A[i];
    
    cout << "Length of B: ";
    cin >> nB;
    
    B = new int[nB]; // แก้ไขการ allocate memory ให้ถูกต้อง
    cout << "Input Array B: ";
    for(int i = 0; i < nB; i++) cin >> B[i];
    
    C = new int*[nA]; // Allocate memory ให้ C เป็น array ของ pointer
    for(int i = 0; i < nA; i++) {
        C[i] = new int[nB]; // Allocate memory ให้แต่ละแถวของ C
    }
    
    for(int i = 0; i < nA; i++){
        for(int j = 0; j < nB; j++) {
            C[i][j] = A[i] * B[j]; // แก้ไขให้ใช้ตัวแปร C[i][j] แทนการใช้ C ตรง ๆ
        }
    }
    
    cout << "\n";
    cout << setw(6) << " "; 
    for(int i = 0; i < nB; i++){
        cout << setw(5) << B[i] << " ";
    }
    cout << "\n-----------------------------\n";
    
    for(int i = 0; i < nA; i++){
        cout << setw(5) << A[i] << " ";
        for(int j = 0; j < nB; j++) {
            cout << setw(5) << C[i][j] << " ";
        }
        cout << "\n";
    }
    
    // Deallocate memory
    for(int i = 0; i < nA; i++) {
        delete[] C[i];
    }
    delete[] C;
    delete[] A;
    delete[] B;
    
    return 0;
}
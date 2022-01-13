#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int size = 4;
    int A[size] = {1,2,3,0};
    for(int i = size; i > 0; i--){
        A[i] = A[i-1];
    }
    A[0] = 4;
    for(int i = 0; i<size; i++){
        cout << A[i] << ", ";
    }
}
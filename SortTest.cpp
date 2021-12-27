#include <iostream>

using namespace std;

void sortArrayAc(int*,int);
void printArray(int arr[],int);
void swap(int *a, int *b);

int main(){
    int data[10] = {10,9,8,7,6,5,3,4,1,2};
    int size = 10;
    cout << "Array before sorting" << endl;
    printArray(data,size);
    sortArrayAc(data,size);
    printArray(data,size);
}

void sortArrayAc(int *arr,int size){
    int i,j,min;
    for(i=0;i<size-1;i++){
        min = i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
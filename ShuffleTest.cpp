#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void shuffle(int *array, int size);

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
    shuffle(arr,5);
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
}

void shuffle(int *array, int size){
    int index,i,temp;
    srand(time(NULL));
    for(i=0;i<size;i++){
        index = rand()%5;
        cout << index;
        temp = array[index];
        array[index] = array[i];
        array[i] = temp;
    }
}
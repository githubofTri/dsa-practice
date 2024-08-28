#include<iostream> 
using namespace std;

void traversal(int arr[], int size){
    for(int i = 0;  i < size; i++){
        cout << arr[i] << endl;
    }
}

void insertion(int arr[], int index, int value, int size){
    for(int i = size - 1; i >= index - 1; i--){
        arr[i + 1] = arr[i];
    }
    arr[index - 1] = value;
}

void deleteArr(int arr[], int size, int index){
    for(int i = index; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
    arr[size - 1] = arr[size - 2] + 1;
}


int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion(arr, 3, 11, size);    
    deleteArr(arr, size, 2);
    traversal(arr, size);
    return 0;
}
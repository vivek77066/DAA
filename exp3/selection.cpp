#include <iostream>
using namespace std;
#include<chrono>
using namespace std::chrono;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

     
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    swap(&array[min_idx], &array[step]);
  }
}


int main() {
    int ele;
    cin>>ele;

  int data[ele];
  for(int i=0;i<ele;i++){
    data[i]=rand();
  }
  int size = sizeof(data) / sizeof(data[0]);
  auto start=high_resolution_clock::now();
  selectionSort(data, size);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, size);

   auto stop=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(stop-start);
    cout<<endl<<duration.count()<<"milliseconds"<<endl;
}
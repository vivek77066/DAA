// Binary Search in C++

#include <iostream>
using namespace std;
#include<chrono>
using namespace std::chrono;

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main(void) {
  int ele;
    cin>>ele;

    int array[ele];
    int i=0;
    while(i<=ele)
    {
        
       array[i]=i;
        i++;
        
    }
    int x;
    cout<<"enter element to search"<<endl;
    cin>>x;
  int n = sizeof(array) / sizeof(array[0]);
   auto start=high_resolution_clock::now();
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);

     auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<endl<<duration.count()<<"microseconds"<<endl;
}
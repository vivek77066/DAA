#include<iostream>
using namespace std;
#include<chrono>
using namespace std::chrono;
int main()
{
    int ele;
    cin>>ele;

    int arr[ele], n, i, pos;
    i=0;
    while(i<=ele)
    {
        
       arr[i]=i;
        i++;
        
    }
    pos = 0;
    cout<<" enter any value for search :";
    cin>>n;
    i=0;
    auto start=high_resolution_clock::now();
    while(i<=ele)
    {
        
        if(n==arr[i])
        {
            
            pos=i+1;
            break;
            
        }
        i++;
        
    }
    if(pos==0)
        cout<<" value not found"<<endl;
    else
        cout<<" Value found at position = "<<pos<<endl;
    
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<endl<<duration.count()<<"microseconds"<<endl;
}

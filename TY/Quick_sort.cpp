#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class quick_sort
{
  public:
    void quick(int* arr,int start,int end)
    { if(start>=end)
         return;
         
      int pi=pivot(arr,start,end);
      //cout<<"ankaj"<<pi;
      quick(arr,start,pi-1);
      quick(arr,pi+1,end);
      return;
    }
    
    int pivot(int* arr,int low,int high)
    { //cout<<low<<" "<<high;
      //int low=0,high=arr.size()-1;
      int pi=high;
    //   cout<<pi;
    //   high=high-1;
      while(low<high)
      { //cout<<low<<" "<<high<<endl;
        while(arr[low]<arr[pi] && low<high)low++;
        while(arr[high]>=arr[pi] && low<high)high--;
        swap(arr[low],arr[high]);
      }
    //  for(int i=0;i<6;i++)
    // {
    //  cout<<arr[i]<<",";
    // }
      swap(arr[high],arr[pi]);
    //   cout<<"--"<<high<<endl;
      return high;
    }
    
};


int main()
{
 int arr[]={2,5,8,1,6,4};
 quick_sort q;
//   cout<<arr.length();
  q.quick(arr,0,5);
  for(int i=0;i<6;i++)
  {
   cout<<arr[i]<<",";
  }
  return 0;
}
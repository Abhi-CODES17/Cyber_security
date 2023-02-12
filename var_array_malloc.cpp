#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n1,n2;
    cin>>n1>>n2;
    
    int size[n1];
    
    int** ptr;// = new int*[n1]();
    
    ptr = (int**)malloc( (n1) * sizeof(int*) );
    
    for(int i=0;i<n1;i++)
    {   
        int size;
        cin>>size;
        
        int* i_array;// = new int[size];
        
        i_array=(int *)malloc(size*sizeof(int));
        
        for(int j=0;j<size;j++)
        {
            cin>>i_array[j];
        }
        ptr[i] = i_array;
    }  
      
    int Ti[n2],Tj[n2];
     
    for(int i=0;i<n2;i++)
    {
       cin>>Ti[i]>>Tj[i]; 
       cout<<ptr[Ti[i]][Tj[i]]<<endl;
    }   
        
    return 0;
}

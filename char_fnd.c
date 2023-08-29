#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    char c[n+1];
    char k;
 fflush(stdin);
  fgets(c, n+1, stdin); 
    fflush(stdin);
    scanf("%c",&k);
    
    int f=0;

    for(int i=0;i<n;i++)
    { 
        if((k-'a') == ( c[i]-'a'))
          ++f;
     printf("%d",f);
    }
    
    printf("\n%d",f);
    return 0;
}

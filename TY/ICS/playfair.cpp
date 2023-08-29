// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main() {cout<<"Hello Git";
    
    string plaintext,plain;
    string keyword;
    char bogus='x';
    
    cout<<"Enter your keyword:\t";
    getline(cin,keyword);
    
    cout<<"Enter your plaintext:\t";
    getline(cin,plaintext);
    char prev='0';
    for(auto itr:plaintext){
      if(itr!=32){
             if((char)tolower(itr)==prev){
                 plain+=bogus;plain+=(char)tolower(itr);
             }
             else{
              plain+=(char)tolower(itr);
             }
         prev=(char)tolower(itr);
        } 
    }
    
    vector<int> occ(26,0);
    vector<vector<char>> matrix(5,vector<char>(5,'x'));  
    
    int i=0,j=0;
    for(auto itr:keyword)
    {   
        if(itr==32 || occ[tolower(itr)-97]==1 ) continue;
        else{ 
           if(tolower(itr)-97==8 || tolower(itr)-97==9) occ[8]=occ[9]=1;
           else occ[tolower(itr)-97]=1;        
         
         matrix[i][j]=(char)tolower(itr);j++;
         if(j==5){i++;j=0;}
        }
    }
    
    for(int k=0;k<26;k++)
    {
        if(occ[k]==1 ) continue;
        else{
         if(k==8 || k==9) occ[8]=occ[9]=1;     
         else occ[k]=1;        
         
         matrix[i][j]=(char)(k+97);j++;
         if(j==5){i++;j=0;}
        } 
    }
     
    cout<<"\nYour playfair matrix is:\n";
      for(auto itr:matrix){
        for(auto i:itr){
            if(i=='i'||i=='j') cout<<"i/j"<<" ";
            else cout<<i<<"   ";
        }cout<<endl;
    }
     // for(auto itr:occ){
    //     cout<<itr<<" ";
    // }
    
   // cout<<plaintext<<endl;
    ////--------------------------------------------------///
    cout<<"\n////---Encryption---////\n";
 
   string cypher;
   int k=0;
   int m1,n1;
   int m2,n2;
   if(plain.length()%2!=0) plain+=bogus;
   cout<<"\nplaintext in continuous form :\t";
    for(auto itr:plain){
        cout<<itr;
    }cout<<endl;
   
    for(int i=0;i<plain.length();i+=2){
        // cout<<plain[i]<<plain[i+1]<<endl;
      for(int j=0;j<matrix.size();j++){
        for(int k=0;k<matrix[j].size();k++){
           if(matrix[j][k]==plain[i]){m1=j;n1=k;}
           if(matrix[j][k]==plain[i+1]){m2=j;n2=k;}
        }
      }
      if(m1==m2){
        cypher+=matrix[m1][(n1+1)%matrix[0].size()];cypher+=matrix[m2][(n2+1)%matrix[0].size()];
      }
      else if(n1==n2){
        cypher+=matrix[(m1+1)%matrix.size()][n2];cypher+=matrix[(m2+1)%matrix.size()][n1];
      }
      else {cypher+=matrix[m1][n2];cypher+=matrix[m2][n1];}
    }
     cout<<"\ncyphertext is :"<<cypher<<endl;


        cout<<"\n////---Decryption---////\n";
    string decrypt;
    for(int i=0;i<cypher.length();i+=2){
        // cout<<plain[i]<<plain[i+1]<<endl;
      for(int j=0;j<matrix.size();j++){
        for(int k=0;k<matrix[j].size();k++){
           if(matrix[j][k]==cypher[i]){m1=j;n1=k;}
           if(matrix[j][k]==cypher[i+1]){m2=j;n2=k;}
        }
      }
      if(m1==m2){ if(n1==0)n1=n1+matrix[m1].size();if(n2==0)n2=n2+matrix[m2].size();
        decrypt+=matrix[m1][(n1-1)%matrix[0].size()];decrypt+=matrix[m2][(n2-1)%matrix[0].size()];
      }
      else if(n1==n2){if(m1==0)m1=m1+matrix.size();if(m2==0)m2=m2+matrix.size();
        decrypt+=matrix[(m1-1)%matrix.size()][n2];decrypt+=matrix[(m2-1)%matrix.size()][n1];
      }
      else {decrypt+=matrix[m1][n2];decrypt+=matrix[m2][n1];}
    }
    decrypt.erase(remove(decrypt.begin(), decrypt.end(), bogus), decrypt.end());
    cout<<"\nDecrypted plainword is:"<<decrypt<<"\n\n"<<endl; 
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> A;
	int x,i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		A.push_back(x);
	}

    int size=A.size(),flag=0;
    int max=A[size-1];
    vector<int> v,v2;
    if(A[size-1]+1>9) v.push_back(0);
    else v.push_back(A[size-1]+1);

    if(size==1) {cout<<A[size-1]+1;return 0;}
    
    for(i=size-2;i>=0;i--)
    {
       if(A[i+1]==9) 
       { 
           if(A[i]==9)
           {
               v.push_back(0);
               flag=1;
           }
           else v.push_back(A[i]+1); 
       }
       
       else v.push_back(A[i]);
    }
    
    int size2=v.size();
    if(v[size2-1]==0&&flag==1) v.push_back(1);
    
    int size3=v.size(),j;
    
    for(i=size3-1;i>=0;i--)
    {
        if(v[i]!=0) j=i;
    }
    
    for(i=j;i>=0;i--)
    {
        v2.push_back(v[i]);
    }
    
    for(i=0;i<v2.size();i++)
    {
    	cout<<v2[i]<<" ";
    }
   return 0;
}
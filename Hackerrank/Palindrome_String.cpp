#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
  string A;
  getline(cin,A);
  ll low=0,high=A.length()-1,flag=1;

	  while(low<high)
	  {
	  	while(low<high && !isalnum(A[low])) low++;
	  	while(low<high && !isalnum(A[high])) high--;

	  	if(abs(A[low]-A[high])!=32)
	  	{
	  		flag=0;
	  		break;
	  	} 
	  	low++;
	  	high--;
	  }
	cout<<flag
}


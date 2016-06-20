#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,i,j;
	cin>>t;

	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;

		long long int m=s1.length(),n=s2.length();
		long long int a[m+1][n+1];

		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0) a[i][j]=j;
				else if(j==0) a[i][j]=i;
				else if(s2[j-1]==s1[i-1]) a[i][j]=a[i-1][j-1];
				else a[i][j]=1+min(min(a[i-1][j-1],a[i][j-1]),a[i-1][j]);
			}
		}

		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<a[m][n]<<endl; 
	}
	return 0;
}

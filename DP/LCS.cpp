#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,i,j,ans;
	vector<char> v;
	cin>>t;
	while(t--)
	{
		char s1[100000],s2[100000];
		cin>>s1>>s2;

		long long int m=strlen(s1),n=strlen(s2);
		long long int a[m+1][n+1];

		//building the matrix
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0||j==0) a[i][j]=0;
				else if(s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1]+1;
				else a[i][j]=max(a[i-1][j],a[i][j-1]);
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

		cout<<a[m][n]<<endl; //LCS

		ans=a[m][n];
		i=m,j=n;

		//Finding the common subsquence
		while(ans!=0)
		{
			if(s1[i-1]==s2[j-1])
			{
				v.push_back(s1[i-1]);
				ans=a[i-1][j-1];
				i--;
				j--;
			}
			else
			{
				if(a[i][j-1]>=a[i-1][j])
				{
					j--;
				}
				else
				{
					i--;
				}
			}
		}


		long long int size=v.size();
		for(i=0;i<size;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
		
	}
};
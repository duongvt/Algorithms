#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t,m,n,i,j,k;
	cin>>t;

	while(t--)
	{
		cin>>m>>n;
		ll A[m][n],dp[m][n];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>A[i][j];
				dp[i][j]=0;
			}
		}

		ll i,j,flag1,flag2;
        if(A[0][0]==1) return 0;
    
	    for(i=0;i<m;i++)
	    {
	        if(A[i][0]==1)
	        {
	            dp[i][0]=0;
	            flag1=0;
	            j=i;
	            break;
	        }
	        else
	        {
	        	dp[i][0]=1;
	      		flag1=1;
	        } 
	    }
   	
	    if(n==1&&flag1==1) return 1;

	    if(flag1==0)
	    {
	      for(i=j+1;i<m;i++) dp[i][0]=0;
	    }
	    
	     for(i=0;i<n;i++)
	    {
	        if(A[0][i]==1)
	        {
	            dp[0][i]=0;
	            flag2=0;
	            k=i;
	            break;
	        }
	        else
	        {
	        	dp[0][i]=1;
	       		flag2=1;
	        }
	        
	    }
	    
	    if(m==1&&flag2==1) return 1;

	    if(flag2==0)
	    {
	    	for(i=k+1;i<n;i++) dp[0][i]=0;
	    }
	    

	    
	    for(i=1;i<m;i++)
	    {
	        for(j=1;j<n;j++)
	        {
	            if(A[i][j]==0)
	            {
	                dp[i][j]=dp[i-1][j]+dp[i][j-1];
	            }
	            else
	            {
	                dp[i][j]=0;
	            }
	        }
	    }


	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            cout<<dp[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    cout<<dp[m-1][n-1]<<endl;;
}
}

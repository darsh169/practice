#include<bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int n) 
{ 
    //declare 2d dp array for memoisation
    int **dp;
    dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=new int[W+1];
    }
    //put -1 in all blocks
    for(int i=0;i<n+1;i++)
    {
       for(int j=0;j<W+1;j++)
       {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
       }
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
    
   // Your code here
}

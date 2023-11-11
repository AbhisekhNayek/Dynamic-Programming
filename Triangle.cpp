#include <bits/stdc++.h> 
using namespace std;

int solve(int row,int j,int n,vector<vector<int>>&dp,vector<vector<int>>&tri)
{
	if(row==n-1)return tri[row][j];

	if(dp[row][j]!=-1)return dp[row][j];

	int taken=solve(row+1,j+1,n,dp,tri) + tri[row][j];
	int ntaken=solve(row+1,j,n,dp,tri) + tri[row][j];
	
	return dp[row][j]=min(taken,ntaken);
}

int minimumPathSum(vector<vector<int>>&tri, int n)
{
vector<vector<int>>dp(n,vector<int>(n,-1));
	return solve(0,0,n,dp,tri);
}

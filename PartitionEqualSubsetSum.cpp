#include<bits/stdc++.h>

bool sol(vector<int>& arr, int n, int target, int ind, vector<vector<int>>& dp) 
{

if(target==0) return 1;
  
if(ind==0) return (arr[0]==target);
  
if(dp[ind][target]!=-1) return dp[ind][target];
  
bool notPick = sol(arr, n, target, ind-1, dp);
bool pick = false;
if(target>=arr[ind]) 
{
   pick = sol(arr, n, target-arr[ind], ind-1, dp);
}
return dp[ind][target] = pick | notPick;
}


bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;

    for(int i=0;i<n;i++)
      {
        sum+=arr[i];
      }
  
    if(sum%2) return 0;
        int target = sum/2;
  
    return sol(arr, n, target, arr.size()-1);
}

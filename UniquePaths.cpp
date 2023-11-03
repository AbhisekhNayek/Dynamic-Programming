#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
    int dp[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        dp[m-1][i] =1;
    }
	
    for(int i=m-2;i>=0;i--){
        for(int j = n-1;j>=0;j--){
            dp[i][j] = dp[i+1][j];
            if(j<n-1){
            dp[i][j]+=dp[i][j+1];
            }
        }
    }
    return dp[0][0];
}

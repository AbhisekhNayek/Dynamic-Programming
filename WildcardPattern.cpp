#include<bits/stdc++.h>

bool helper(int i, int j, string &pattern, string &text, vector<vector<int>> &dp) {
   if(i < 0 && j < 0) return true;
   if(i < 0 && j >= 0) return false;

   if(j < 0 && i >= 0) {
      for(int k=0; k<=i; k++) {
         if(pattern[k] != '*') return false;
      }
      return true;
   }

   if(dp[i][j] != -1) return dp[i][j];

   if(pattern[i] == text[j] || pattern[i] == '?') {
      return dp[i][j] = helper(i - 1, j - 1, pattern, text, dp);
   }

   if(pattern[i] == '*') {
      return dp[i][j] = helper(i - 1, j, pattern, text, dp) | helper(i, j - 1, pattern, text, dp);
   }
   return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text) {
   int n = pattern.size();
   int m = text.size();

   vector<vector<int>> dp(n, vector<int> (m, -1));
   return helper(n - 1, m - 1, pattern, text, dp);
}

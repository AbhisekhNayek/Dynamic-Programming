int mod =1e9+7;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
  vector<int> prev(m,0);

  for(int i=0; i<n; i++){
      vector<int> curr(m,0);
      for(int j=0; j<m; j++){
          if(i==0 && j==0) curr[j] = 1;
          else if(mat[i][j] == -1) curr[j] = 0;
          else {
            int up = 0, left = 0;
            if (i > 0) up = prev[j];
            if (j > 0) left = curr[j - 1];
            curr[j] = (up + left) % mod;
          }
      }
      prev = curr;
  }
  return prev[m-1];
}

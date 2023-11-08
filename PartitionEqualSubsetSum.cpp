#include<bits/stdc++.h>

bool sol(vector<int>& arr, int n, int k, int ind) {

    vector<bool> prev(k+1, 0), curr(k+1, 0);

    prev[arr[0]] = true;
    prev[0] = curr[0] = true;

    for(int ind=1;ind<n;ind++) {

        for(int target=1;target<=k;target++) {

            bool notTake = prev[target];
            bool take = false;

            if(target>=arr[ind]) {
              
                take = prev[target-arr[ind]];

            }
            curr[target]=take | notTake;
        }
        prev = curr;
    }
    return prev[k];
}

 

bool canPartition(vector<int> &arr, int n)

{
    int sum = 0;

    for(int i=0;i<n;i++) {

        sum+=arr[i];

    }

    if(sum%2) return 0;

    int target = sum/2;

    return sol(arr, n, target, arr.size()-1);

}

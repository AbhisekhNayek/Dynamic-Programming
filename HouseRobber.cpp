#include <bits/stdc++.h> 
#include<vector>

long long int solve(vector<int> &nums){
    long long int prev2 = 0,prev1 = nums[0],include,exclude,temp; 
    for (int i = 1; i < nums.size(); i++) {
        include = prev2 + nums[i];
        exclude = prev1 ;
        temp = max(include,exclude);
        prev2 = prev1;
        prev1 = temp;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if( n==1)
        return valueInHouse[0];

    vector<int> first, second;
    for(int i=0;i<n;i++)
    {
        if(i !=n-1)
            first.push_back(valueInHouse[i]);
        if(i != 0)
            second.push_back(valueInHouse[i]);    
    }

    return max(solve(first), solve(second));
}

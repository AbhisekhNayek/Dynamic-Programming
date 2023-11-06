#include<bits/stdc++.h>
using namespace std;
int main()
{
        int a = 0;
        int n;

        cin>>n;
  
        int sum;
        int b = 1;

        if(n == 1){
            sum = 1;    
        }

        for(int i = 1;i<n;i++){
                sum = a+b;
                a = b;
                b = sum;
        }
        cout<<sum;
}

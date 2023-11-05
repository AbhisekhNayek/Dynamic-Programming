#include<bits/stdc++.h>
using namespace std;
int visited[10005]={0};
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        visited[elem]++;

    }

    int cost=0;
       for(int i=0;i<=10000;){
        if(visited[i] && i<=10000){
            cost++;
            for(int j=1;j<=4;j++){
                    i++;
            }
        }
        i++;
        }
    cout<<cost;
    
    return 0;
}

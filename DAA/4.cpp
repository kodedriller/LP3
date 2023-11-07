#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, w;
    cin>>n>>w;
    int profit[n], weigth[n], dp[n+1][w+1];

    for(int i=0;i<n;i++) cin>>profit[i];
    for(int i=0;i<n;i++) cin>>weigth[i];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0) dp[i][j]=0; //There's nothing to add to Knapsack
            else if(weigth[i-1]<=j) dp[i][j] = max(dp[i-1][j], profit[i-1]+dp[i-1][j-weigth[i-1]]);  //Choose previously maximum or value of current item + value of remaining weight
            else dp[i][j]=dp[i-1][j]; // Add previously added item to knapsack
        } 
    }

    cout<<dp[n][w];
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/
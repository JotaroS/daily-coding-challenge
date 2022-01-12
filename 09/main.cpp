#include<vector>
#include<iostream>

using namespace std;

int solve(int n, vector<int> arr){
  // dp[i] = maximum sum possible until i-th numbers
  vector<int> dp(n);
  for(int i=0;i < n; i++)dp[i]=0; // initialize with 0

  // boundary condition
  dp[0] = arr[0]; //if n=1 arr[0] is always the answer.
  dp[1] = max(arr[0], arr[1]);  //if n=2, you pick only one.

  for(int i=2; i < n; i++){
    // you want to decide whether you pick i-th number or not
    // you don't pick ith then dp[i] = dp[i-1], or, you pick current arr[i] and number two steps before then dp[i] = arr[i] = dp[i-2] (prevents adjacency)
    dp[i] = max(arr[i] + dp[i-2],dp[i-1]); 
  }
  return dp[n-1];
}


int main(void){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i < n; i++){
    cin>>arr[i];
  }
  cout<<solve(n,arr)<<endl;
  return 0;
}

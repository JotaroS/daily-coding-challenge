#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve_bonus(int n, vector<ll> arr){

    //ans = prod until ith element array * prod until n-i th element array from backwards.

    // use "prod until i-th element array";
    vector<ll> a = arr;
    for(int i=1; i<n; i++)a[i]*=a[i-1];

    // do the same from backwards.
    vector<ll> b = arr;
    reverse(b.begin(), b.end());
    for(int i=1; i<n; i++)b[i]*=b[i-1];
    reverse(b.begin(), b.end());
    
    // do it.
    for(int i=0; i < n; i++){   
        if(i==0)cout<<b[i+1]<< " ";
        else if(i==n-1)cout<<a[i-1]<< " ";
        else cout<<a[i-1] * b[i+1]<< " ";
    }
    cout<<endl;
    return;
}

void solve(int n, vector<ll> arr){
    ll prod = 1;
    for(int i=0; i < n; i++)prod *= arr[i];

    for(int i=0; i < n; i++)cout<< prod / arr[i] << " ";
    cout<<endl;
    return;
}

int main(void){
  int n; cin>>n;
  vector<ll> arr(n);
  for(int i=0; i < n; i++){
      cin>>arr[i];
  }
  solve(n, arr);
  solve_bonus(n, arr);
  return 0;
}

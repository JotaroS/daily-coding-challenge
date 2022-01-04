#include<bits/stdc++.h>

using namespace std;

// O(N^2)
void solve(int n, int k, vector<int> arr){
  for(int i=0; i < n;i++){
    for(int j=0; j < n; j++){
      if(i!=j){
        if(arr[i]+arr[j] == k){
          cout<<"true"<<endl;
          return;
        }
      }
    }
  }
  cout<<"false"<<endl;
  return;
}

//O(NlogN)
void solve_hash(int n, int k, vector<int> arr){
  map<int, bool> m;
  for(int i=0;i < n; i++){ //N
    m.insert(pair<int, bool>(arr[i], true)); //logN
    if(m[k-arr[i]]){
      cout<<"true"<<endl;
      return;
    }
  }
  cout<<"false"<<endl;
  return;
}

int main(void){
  vector<int> arr;
  int n, k;
  cin>>n>>k;
  for(int i=0; i < n; i++){
    int v; cin>>v;
    arr.push_back(v);
  }
  solve_hash(n,k,arr);
  return 0;
}

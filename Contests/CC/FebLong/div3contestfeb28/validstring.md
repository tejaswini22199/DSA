```
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  while(t--){
    int n,c;
    cin>>n>>c;
    string x;
    cin>>x;
    vector<int> pos_one;
    for(int i=0;i<n;i++){
      if(x[i]=='1')
      pos_one.push_back(i);
    }
    int exceed=0;
    int p=pos_one.size();
    for(int i=0;i<p-1;i++){
      if(pos_one[i+1]-pos_one[i]-1>c)
      exceed++;
    }
    
    if(n-pos_one[p-1]-1+pos_one[0]>c)
    exceed++;
    if(exceed>1)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
  }
}
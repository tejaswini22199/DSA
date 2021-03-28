```
#include <bits/stdc++.h>
using namespace std;
int fun(int a,int b){
  return a*b+(b-a);
}
int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    long long int m1;
    long long int x=arr[0]*arr[1]+(arr[1]-arr[0]);
    long long int y=arr[n-1]*arr[n-2]+(arr[n-1]-arr[n-2]);
    long long int z=arr[n-1]*arr[0]+(arr[n-1]-arr[0]);
   m1=max({x,y,z});
    cout<<m1<<endl;
  }
  return 0;
}
```
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  while(t--){
    int c,d;
    cin>>d>>c;
    int arr[3];
    int b[3];
    int sum1=0;
    int sum2=0;
    for(int i=0;i<3;i++){
       cin>>arr[i];
       sum1+=arr[i];
    }
    for(int i=0;i<3;i++)
    {
      cin>>b[i];
      sum2+=b[i];
    }
    int total_cost=0;
    total_cost+=((sum1>=150)?0:d);
    total_cost+=((sum2>=150)?0:d);
    total_cost+=c+sum1+sum2;
    //cout<<"total cost with coupon"<<total_cost<<endl;
    int total_cost_w=0;
    total_cost_w+=sum1+sum2+2*d;
    if(total_cost<total_cost_w)
    cout<<"YES"<<endl;
    else
     cout<<"NO"<<endl;
  }
  
}
> https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
```
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define N 3
using namespace std;
vector<int> cal_NetAmount(int graph[][N]){
    vector<int> result(N,0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            result[i]+=graph[j][i]-graph[i][j];
        }
    }
    return result;
}
int findMinCredit(vector<int> result){
    int min_index=0;
    for(int i=1;i<N;i++)
    {
        if(result[i]<result[min_index])
        {
            min_index=i;
        }
    }
    return min_index;
}
int findMaxCredit(vector<int> result){
    int max_index=0;
    for(int i=1;i<N;i++)
    {
        if(result[i]>result[max_index])
        {
            max_index=i;
        }
    }
    return max_index;
}
int min_of_C_and_D(int a,int b)
{
    return a<b?a:b;
}
void minCashFlow(int graph[][N],vector<int> & result){
   
    int x=findMinCredit(result);
    int y=findMaxCredit(result);
  
    if(x==0 && y==0)
    return;
    int a=min_of_C_and_D(-result[x],result[y]);
    result[y]-=a;
    result[x]+=a;
    cout<<x<<"pays to"<<y<<endl;
    minCashFlow(graph,result);
}
int main()
{
    int graph[N][N]={
        {0,1000,2000},
        {0,0,5000},
        {0,0,0},
    };
     vector<int> result=cal_NetAmount(graph);
    minCashFlow(graph,result);
    return 0;
}

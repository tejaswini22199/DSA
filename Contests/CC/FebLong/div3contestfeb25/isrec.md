>https://www.codechef.com/CCRC21C/problems/ISREC
```
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
string fun(){
    int n,m;
         cin>>n>>m;
         vector<string> matrix(n);
         for(int i=0;i<n;i++){
             cin>>matrix[i];
         }
         int min_row,max_row,min_col,max_col;
         min_row=n;
         min_col=m;
         max_row=-1;
         max_col=-1;
         int res=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++)
             {
                 if(matrix[i][j]=='1'){
                     res++;
                     min_row=min(min_row,i);
                     max_row=max(max_row,i);
                     min_col=min(min_col,j);
                     max_col=max(max_col,j);
                 }
             }
         }
         for(int i=min_row;i<=max_row;i++){
             for(int j=min_col;j<=max_col;j++){
                 if(matrix[i][j]=='0')
                 {
                    return "NO";
                     
                 }
             }
         }
         return "YES";
    }
   
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         cout<<fun()<<endl;
    }
   

    return 0;
}
```
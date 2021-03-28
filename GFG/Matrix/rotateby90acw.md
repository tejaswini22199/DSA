
>https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/?company[]=Amazon&company[]=Amazon&problemStatus=unsolved&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolveddifficulty[]1page1company[]Amazon#;

```
void transpose(vector<vector<int>> &matrix)
{
     int n=matrix.size();
     int m=matrix[0].size();
     for(int i=0;i<n;i++)
     {
         for(int j=i;j<m;j++)
         {
             swap(matrix[i][j],matrix[j][i]);
             
         }
     }
}
void rotateColumns(vector<vector<int>> &matrix)
{
     int n=matrix.size();
     int m=matrix[0].size();
    for(int i=0;i<m;i++)
    {
        int l=0;
        int h=n-1;
        while(l<h)
        {
            swap(matrix[l][i],matrix[h][i]);
            l++;
            h--;
        }
    }
}
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    transpose(matrix);
    rotateColumns(matrix);
    //for(int i=0)
    
}
```
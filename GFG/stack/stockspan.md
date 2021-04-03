>https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
```
class Solution{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> s;
       vector<int> NGLIndex;
       for(int i=0;i<n;i++)
       {
           
               while(!s.empty() && price[s.top()]<=price[i])
               {
                   s.pop();
               }
               if(!s.empty())
               {
                   NGLIndex.push_back(i-(s.top()));
               }
               else
               {
                   NGLIndex.push_back(i+1);
               }
           
            s.push(i);
       }
      
       return NGLIndex;
    }
};

```
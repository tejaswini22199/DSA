>https://www.geeksforgeeks.org/next-greater-element/

```
class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long > res;
        stack<long long> s;
        for(int i=n-1;i>=0;i--)
        {
            
            while(!s.empty() && s.top()<arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                res.push_back(s.top());
                s.push(arr[i]);
            }
            else
            {
                res.push_back(-1);
                s.push(arr[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

```
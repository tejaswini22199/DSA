>https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1/?company[]=Amazon&amp;company[]=Amazon&amp;difficulty[]=2&amp;page=1&amp;category[]=Stack&amp;query=company[]Amazondifficulty[]2page1company[]Amazoncategory[]Stack#
```
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Function to print maximum of minimum of every window size
    // arr[]: input array
    // N: size of array
    vector <int> maxOfMin(int arr[], int n) {
        // Your code here

// Used to find previous and next smaller
    stack<int> s; 

    // Arrays to store previous and next smaller
    int left[n+1];  
    int right[n+1]; 

    // Initialize elements of left[] and right[]
    for (int i=0; i<n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }

    // Fill elements of left[] using logic discussed on
    // https://www.cdn.geeksforgeeks.org/next-greater-element/
    for (int i=0; i<n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            left[i] = s.top();

        s.push(i);
    }

    // Empty the stack as stack is 
// going to be used for right[]
    while (!s.empty())
        s.pop();

    // Fill elements of right[] using same logic
    for (int i = n-1 ; i>=0 ; i-- )
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if(!s.empty())
            right[i] = s.top();

        s.push(i);
    }

    // Create and initialize answer array
    vector<int> ans(n);
    for (int i=0; i<n; i++)
        ans[i] = 0;

    // Fill answer array by comparing minimums of all
    // lengths computed using left[] and right[]
    for (int i=0; i<n; i++)
    {
        // length of the interval
        int len = right[i] - left[i] - 1;

        // arr[i] is a possible answer for this length 
        // 'len' interval, check if arr[i] is more than
        // max for 'len'
        if(len==0)
        continue;
        ans[len-1] = max(ans[len-1], arr[i]);
    }

    // Some entries in ans[] may not be filled yet. Fill 
    // them by taking values from right side of ans[]
    for (int i=n-2; i>=1; i--)
        ans[i] = max(ans[i], ans[i+1]);

    // Print the result
    // for (int i=1; i<=n; i++)
    //     cout << ans[i] << " ";
return ans;

        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
```
```
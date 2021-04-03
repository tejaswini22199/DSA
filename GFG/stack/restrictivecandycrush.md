>https://practice.geeksforgeeks.org/problems/8c8f95810b05b4cab665f2997d36991bd58308a2/1/?company[]=Amazon&company[]=Amazon&difficulty[]=1&page=1&category[]=Stack&query=company[]Amazondifficulty[]1page1company[]Amazoncategory[]Stack
```
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
      // Base Case
        // If k=1 then all characters 
        // can be removed at each
        // instance
        if (k == 1)
            return "";
        // initialize string
        string output = "";
      
        // create a stack using pair<> for storing each
        // character and corresponding
        // repetition
        stack<pair<char, int> > stk;

        // iterate through the string
        int n=s.length();
        for (int i = 0; i < n; i++) {
          
            // if stack is empty then simply add the
            // character with count 1 else check if character
            // is same as top of stack
            if (stk.empty() == true) {
                stk.push(make_pair(s[i], 1));
            }
            else {
              
                // if character at top of stack is same as
                // current character increase the number of
                // repetitions in the top of stack by 1
                if (s[i] == (stk.top()).first) {
                    (stk.top()).second++;
                  
                    // if the number of repetitions is equal
                    // to the k ie. number of duplicate
                    // characters has reached the limit to be
                    // removed
                    // then pop the top of stack
                    if ((stk.top()).second == k)
                        stk.pop();
                }
                else {
                  
                    // if character at top of stack is not
                    // same as current charcter push the
                    // character along with count 1 into the
                    // top of stack
                    stk.push(make_pair(s[i], 1));
                }
            }
        }
      
        // iterate through the stack
        // Use string(int,char) in order to replicate the
        // character multiple times and convert into string
        // then add in front of output string
        while (!stk.empty()) {
            string append = string((stk.top()).second,(stk.top()).first);
          
            output =append + output;
              stk.pop();
        }
        return output;
    }
```

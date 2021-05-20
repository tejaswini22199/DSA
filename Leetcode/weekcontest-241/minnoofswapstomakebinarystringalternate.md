>https://leetcode.com/contest/weekly-contest-241/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

```
class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int count0=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                count0++;
        }
        if(abs(count0-(n-count0))>1)
            return -1;
        // if(n%2==0)
        // {
            int start=0;
            int count2=0;
            int count1=0;
            for(int i=0;i<n;i++)
            {
                if((s[i]-'0')!=start)
                    count1++;
                start=1-start;
            }
            start=1;
            for(int i=0;i<n;i++)
            {
                if((s[i]-'0')!=start)
                    count2++;
                start=1-start;
            }
        if(count1%2!=0)
            return count2/2;
        if(count2%2!=0)
            return count1/2;
            return min(count1/2,count2/2);
            
      
    }
};
```
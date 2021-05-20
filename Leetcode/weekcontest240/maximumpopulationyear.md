> https://leetcode.com/contest/weekly-contest-240/problems/maximum-population-year/

```
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> freq(2051,0);
        int min_year;
        int max_year;
        int maximum;
        maximum=0;
        min_year=INT_MAX;
        max_year=INT_MIN;
        for(int i=0;i<logs.size();i++)
        {
            for(int j=logs[i][0];j<logs[i][1];j++)
            {
                freq[j]++;
                min_year=min(min_year,j);
                max_year=max(max_year,j);            
            }
        }
        for(int i=min_year;i<=max_year;i++)
        {
            if(freq[i]>freq[maximum])
               maximum=i;
        }
        return maximum;
    }
};
```




```
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
      
        vector<int> freq(2051,0); 
        for(int i=0;i<logs.size();i++)
        {
            freq[logs[i][1]]--;
            freq[logs[i][0]]++;
        }
        int maximum=freq[1950];
        int year=1950;
        for(int i=1951;i<=2050;i++)
        {
            
            freq[i]+=freq[i-1];
            if(freq[i]>maximum)
            {
                maximum=freq[i];
                year=i;
            }
           
        }
        return year;
    }
};
```
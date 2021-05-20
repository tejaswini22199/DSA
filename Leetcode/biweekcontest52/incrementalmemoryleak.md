>https://leetcode.com/contest/biweekly-contest-52/problems/incremental-memory-leak/

```
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int count=1;
        while(memory1>=count||memory2>=count)
        {
            if(memory1>=memory2)
            {
                memory1-=count;
            }
            else {
                memory2-=count;
            }
            count++;
        }
        return {count,memory1,memory2};
    }
};
```
//second approach todo
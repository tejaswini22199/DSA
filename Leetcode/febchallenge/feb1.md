```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        //return n%2;
        while(n)
        {
            res+=n%2;
            n=n/2;
        }
        return res;
    }
};
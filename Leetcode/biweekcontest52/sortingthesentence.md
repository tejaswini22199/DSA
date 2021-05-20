>https://leetcode.com/contest/biweekly-contest-52/problems/sorting-the-sentence/

```
class Solution {
public:
    string sortSentence(string s) {
        string temp;
        int n=s.length();
        vector<string> v(n+1,"");
        temp="";
      //  res;
        for(int i=0;i<n;i++)
        {
           // cout<<s[i]<<endl;
            if(s[i]<='9' && s[i]>='0')
            {
                v[s[i]-'0']=temp+" ";
                i++;
                temp="";  
            }
            else
            {
               
                temp=temp+s[i];
            }
                
        }
        
       std::string res;
for (std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); ++i)
    res += *i;
return res.substr(0,res.size()-1);
    }
};
```
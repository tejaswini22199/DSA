
```
#include <bits/stdc++.h>
using namespace std;
unordered_set<string> s;
void noSubseq(char output[],char str[],int i,int j)
{
  if(str[i]=='\0')
  {
    output[j]='\0';
    s.insert(output);
    return;
  }
  else{
   output[j]=str[i];
  noSubseq(output, str, i+1, j+1);
  noSubseq(output, str, i+1, j);
  }
  
}
int main() {
  char str[]="gfg";
  int m=sizeof(str)/sizeof(char);
 // int n=pow(2,m)+1;
  char output[m];
  
  noSubseq(output,str,0,0);
  cout<<s.size()<<endl;
  return 0;
}
```

```

// C++ program to count number of distinct
// subsequences of a given string.
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;

// Returns count of distinct sunsequences of str.
int countSub(string str)
{
	// Create an array to store index
	// of last
	vector<int> last(MAX_CHAR, -1);

	// Length of input string
	int n = str.length();

	// dp[i] is going to store count of distinct
	// subsequences of length i.
	int dp[n + 1];

	// Empty substring has only one subsequence
	dp[0] = 1;

	// Traverse through all lengths from 1 to n.
	for (int i = 1; i <= n; i++) {
		// Number of subsequences with substring
		// str[0..i-1]
		dp[i] = 2 * dp[i - 1];

		// If current character has appeared
		// before, then remove all subsequences
		// ending with previous occurrence.
		if (last[str[i - 1]] != -1)
			dp[i] = dp[i] - dp[last[str[i - 1]]];

		// Mark occurrence of current character
		last[str[i - 1]] = (i - 1);
	}

	return dp[n];
}

// Driver code
int main()
{
	cout << countSub("gfg");
	return 0;
}

```
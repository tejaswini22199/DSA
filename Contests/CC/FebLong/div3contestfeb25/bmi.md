>https://www.codechef.com/CCRC21C/problems/BMI/


```
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int m,h;
	    cin>>m>>h;
	    int res=m/(h*h);
	    if(res<=18)
	    cout<<"1"<<endl;
	    else if(res<=24)
	    cout<<"2"<<endl;
	    else if(res<=29)
	    cout<<"3"<<endl;
	    else
	    cout<<"4"<<endl;
	}
	return 0;
}

```
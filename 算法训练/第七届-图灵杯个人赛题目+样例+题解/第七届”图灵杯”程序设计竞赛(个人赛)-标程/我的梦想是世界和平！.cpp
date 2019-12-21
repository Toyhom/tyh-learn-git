#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(xx) push_back(xx);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		multiset<int> st;
		st.clear();
		if(a>c){
			st.insert(a/2);
			st.insert(a-a/2);
			st.insert(c);
		}else{
			st.insert(c/2);
			st.insert(c-c/2);
			st.insert(a);
		}
		for(int i=1;i<=b;i++)
		{
			int x=*st.begin();
			x++;
			st.erase(st.begin());
			st.insert(x);
		}
		cout<<*st.rbegin()<<endl;
	}
	return 0;
 } 

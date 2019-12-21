#include<bits/stdc++.h>
#define ll long long
#define lnode node*2,start,mid
#define rnode node*2+1,mid+1,end
#define rep(i,a,b) for(ll i=a;i<=(b);i+=1)
#define input freopen("in.txt", "r", stdin)
#define out freopen("in16.in", "w", stdout)
#define To_string(num,str) {stringstream ss;ss<<num;ss>>str;}
#define To_num(str,num) {stringstream ss;ss<<str;ss>>num;}
const double pi=acos(-1.0);
const int maxn=(1000+10);
const int inf=0x3f3f3f3f;
const ll mod=10000003;
using namespace std;
ll in()
{  ll x=0,f=0;char ch=getchar();
   while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
   while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
   return f? -x:x;
}
int main()
{   ios::sync_with_stdio(false);
    srand(time(0));
    out;
	int n=2e5;
	
	cout<<n<<"\n";
	for(int i=1;i<=n;i++)
	{  int x=rand();
	   while(x<1||x>1e9) x=rand();
	   cout<<x<<" ";
	} 
	return 0;
}

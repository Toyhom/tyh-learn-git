#include<bits/stdc++.h>
#define ll long long
#define lnode node*2,start,mid
#define rnode node*2+1,mid+1,end
#define rep(i,a,b) for(ll i=a;i<=(b);i+=1)
#define input freopen("in16.in", "r", stdin)
#define out freopen("out16.out", "w", stdout)
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
int a[500005];
int sum[500005];
int main()
{   ios::sync_with_stdio(false);
    int n,maxx=-1;
    input;
	out; 
	cin>>n;
	memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=n-1;i>=1;i--)
	  if(a[i+1]<a[i])
	    sum[i]=sum[i+1]+1;
	for(int i=1;i<=n;i++)
	  maxx=max(maxx,sum[i]);
	cout<<maxx;
	return 0;
}


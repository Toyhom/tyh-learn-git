#include<bits/stdc++.h>
#define ll long long
#define lnode node*2,start,mid
#define rnode node*2+1,mid+1,end
#define rep(i,a,b) for(ll i=a;i<=(b);i+=1)
#define input freopen("in.txt", "r", stdin)
#define out freopen("in20.in", "w", stdout)
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
{   //ios::sync_with_stdio(false);
	char chin[200];
    for(int xx=1;xx<=16;xx++)
    {
	    sprintf(chin,"in%d.in",xx);
	    //sprintf(chout,"in%d.out",xx);
	    freopen(chin, "w", stdout);
	    //freopen(chout,"w",stdout);
	    srand(time(0));
	    int n=3e5;
	    cout<<n<<"\n";
	    int k=rand();
	    while(k<1||k>1e9) k=rand();
	    cout<<k<<"\n";             
	    int q=1e5;                  
	    cout<<q<<"\n";
	    for(int i=1;i<=q;i++)
	    {  int now=rand();
	       while(now<1||now>n) now=rand();
		   cout<<now<<"\n"; 
		}
		fclose(stdin);
	}
	return 0;
}

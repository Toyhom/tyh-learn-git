#include<bits/stdc++.h>
#define ll long long
#define lnode node*2,start,mid
#define rnode node*2+1,mid+1,end
#define rep(i,a,b) for(ll i=a;i<=(b);i+=1)
#define input freopen("in20.in", "r", stdin)
#define out freopen("out20.out", "w", stdout)
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
int sum[300001];
int main()
{   

    int n,k,q;
	char chin[200];
	char chout[200];
    for(int xx=1;xx<=16;xx++)
    {
	    sprintf(chin,"in%d.in",xx);
	    sprintf(chout,"in%d.out",xx);
	    freopen(chin, "r", stdin);
	    freopen(chout,"w",stdout);
	    cin>>n>>k>>q; 
	    memset(sum,0,sizeof(sum));
	    for(int i=1;i<=q;i++)
	    {  int x;
	       cin>>x;
	       sum[x]+=1;
		}
		for(int i=1;i<=n;i++)
		  if(k-q+sum[i]>0)
	        cout<<"Yes ";
		  else 
		    cout<<"No "; 
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(xx) push_back(xx);
struct ss{
	ll x;
	ll y;
	double sum;
}a[200050];
ll f[300050];
bool cmp(ss x,ss y)
{
	return x.sum>y.sum;
}
int main()
{
	freopen("C://Users//HP//Desktop//新建文件夹//sample.in","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[i].x=x;
		a[i].y=y;
		a[i].sum=(double)y/x;
	}
	sort(a,a+n,cmp);
	ll sum=0;
	int index=-1;
	ll ans=0;
	for(int i=0;i<n;i++)   //因为最小花费是1~3，所以1~3的LCM最小公倍数是6 
							//我们贪心的取，取到只剩下6个的话，开始01背包 
	{
		if(sum>=m-9) break;
		sum+=a[i].x;
		ans+=a[i].y;
		index=i;
	}
	
	memset(f,0,sizeof(f));
	ll temp=0;
	for(int i=index+1;i<n;i++)
	{
		for(int j=m;j>=sum+1;j--)
		{
			int k=j-sum;
			if(k>=a[i].x)
				f[k]=max(f[k],f[k-a[i].x]+a[i].y);
			temp=max(temp,f[k]);
		}
	}
	
	cout<<ans+temp<<endl;
	return 0;
 } 

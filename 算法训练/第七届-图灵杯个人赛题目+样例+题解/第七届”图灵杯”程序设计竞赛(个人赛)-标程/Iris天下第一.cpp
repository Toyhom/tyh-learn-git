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
	freopen("C://Users//HP//Desktop//�½��ļ���//sample.in","r",stdin);
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
	for(int i=0;i<n;i++)   //��Ϊ��С������1~3������1~3��LCM��С��������6 
							//����̰�ĵ�ȡ��ȡ��ֻʣ��6���Ļ�����ʼ01���� 
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

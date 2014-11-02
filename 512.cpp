#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define pb push_back
class SubFibonacci
{
	public:
	vector<ll> s;
	ll fib[50];
	int solve(int x)
	{
		int ans1=0,ans2=0;
		ans1 = min(2,x);
		ans2 = min(2,(int)s.size()-x);
		set<ll> s1,s2;
		for(int i=0;i<x;i++)s1.insert(s[i]);
		for(int i=x;i<s.size();i++)s2.insert(s[i]);
		for(int i=0;i<x;i++)
		{
			for(int j=i+1;j<x;j++)
			{
				for(int k=1;k<40;k++)
				{
					ll r=s[j]-s[i]*fib[k];
					if(r%fib[k+1]==0&&r/fib[k+1]>0)
					{
						int b = r/fib[k+1];
						int cnt=0;
						for(int l=0;l<40;l++)
						{
							if(s1.find(s[i]*fib[l]+b*fib[l+1])!=s1.end())cnt++;
						}
						ans1 = max(ans1,cnt);
					}
				}
			}
		}
		for(int i=x;i<s.size();i++)
		{
			for(int j=i+1;j<s.size();j++)
			{
				for(int k=1;k<40;k++)
				{
					ll r=s[j]-s[i]*fib[k];
					if(r%fib[k+1]==0&&r/fib[k+1]>0)
					{
						int b = r/fib[k+1];
						int cnt=0;
						for(int l=0;l<40;l++)
						{
							if(s2.find(s[i]*fib[l]+b*fib[l+1])!=s2.end())cnt++;
						}
						ans2 = max(ans2,cnt);
					}
				}
			}
		}
		return ans1+ans2;
	}
	int maxElements(vector <int> S)
	{
		sort(S.begin(),S.end());
		for(int i=0;i<S.size();i++)s.pb((ll)S[i]);
		fib[0]=1;fib[1]=0;
		for(int i=2;i<=42;i++)fib[i]=fib[i-1]+fib[i-2];
		int ans=0;
		for(int i=0;i<s.size();i++)ans = max(ans,solve(i));
		return ans;
	}
};

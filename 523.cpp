#include <cstring>
using namespace std;
typedef long long ll;
#define MOD 1000000007
class BricksN
{
	public:
	ll num[55];
	ll dp[55][55];
	ll rec(int W,int H)
	{
		if(H==0||W<=0)return 1ll;
		if(dp[W][H]!=-1)return dp[W][H];
		ll res=0ll;
		for(int i=0;i<=W;i++)
		{
			res+=((num[i]*rec(i,H-1))%MOD)*rec(W-1-i,H)%MOD;
			res%=MOD;
		}
		return dp[W][H]=res;
	}
	int countStructures(int w, int h, int k)
	{
		memset(num,0,sizeof(num));
		memset(dp,-1,sizeof(dp));
		num[0]=1;
		for(int i=1;i<=w;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(i-j>=0)
				{
					num[i]+=num[i-j];
					num[i]%=MOD;
				}
			}
		}
		return rec(w,h);
	}
};

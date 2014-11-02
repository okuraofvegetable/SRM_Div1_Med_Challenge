#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 1000000
#define MAX 7*7*7*7*7*7*7
class AmoebaCode
{
	public:
	int dp[2][MAX+10];
	int K;
	int x[8],y[8];
	int encode(int *a)
	{
		int res = 0;
		for(int i=0;i<K;i++)
		{
			res*=7;
			res+=a[i];
		}
		return res;
	}
	void decode(int res)
	{
		for(int i=0;i<K;i++)
		{
			x[K-i-1]=res%7;
			res/=7;
		}
		return;
	}
	int find(string code, int K)
	{
		this->K = K;
		for(int i=0;i<K;i++)x[i]=K-1;
		memset(dp,-1,sizeof(dp));
		dp[0][encode(x)] = INF;
		for(int i=0;i<code.size();i++)
		{
			for(int j=0;j<=MAX;j++)
			{
				if(dp[0][j]!=-1)
				{
					if(code[i]=='0')
					{
						for(int k=0;k<K;k++)//irerumono
						{
							int res = dp[0][j];
							decode(j);
							for(int l=0;l<K;l++)//ikkomaeno'l'gadokoka
							{
								y[l] = x[l]+1;
								if(k==l)
								{
									if(y[k]<res)res = y[k];
									y[k]=0;
								}
								if(y[l]>=K)y[l]=K-1;
							}
							int nxt = encode(y);
							dp[1][nxt] = max(dp[1][nxt],res);
						}
					}
					else
					{
						int res = dp[0][j];
						decode(j);
						for(int k=0;k<K;k++)
						{
							y[k] = x[k]+1;
							if(k==code[i]-'1')
							{
								if(y[k]<res)res = y[k];
								y[k]=0;
							}
							if(y[k]>=K)y[k]=K-1;
						}
						int nxt = encode(y);
						dp[1][nxt] = max(dp[1][nxt],res);
					}
				}
			}
			for(int j=0;j<=MAX;j++)
			{
				dp[0][j]=dp[1][j];
				dp[1][j]=-1;
			}
		}
		int ans = 0;
		for(int i=0;i<=MAX;i++)ans = max(ans,dp[0][i]);
		return ans;
	}
};

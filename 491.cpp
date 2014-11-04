#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define INF 1000000000
int dp[1<<16];
int prefix[1<<16];
int num[20][30];
int cnt[30];
class PrefixTree
{
	public:
	int getNumNodes(vector <string> words)
	{
		int N = words.size();
		memset(num,0,sizeof(num));
		memset(prefix,0,sizeof(prefix));
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<words[i].size();j++)num[i][words[i][j]-'a']++;
		}
		for(int i=1;i<(1<<N);i++)
		{
			for(int j=0;j<30;j++)cnt[j]=INF;
			for(int j=0;j<N;j++)
			{
				if((i>>j)&1)
				{
					for(int k=0;k<30;k++)cnt[k]=min(cnt[k],num[j][k]);
				}
			}
			for(int j=0;j<30;j++)prefix[i] += cnt[j];
			//cout << prefix[i] << endl;
		}
		for(int i=1;i<(1<<N);i++)dp[i]=INF;
		for(int i=0;i<N;i++)dp[1<<i]=(int)words[i].size();
		for(int i=1;i<(1<<N);i++)
		{
			for(int j=i&(i-1);j>0;j=(j-1)&i)
			{
				dp[i] = min(dp[i],dp[j]+dp[i^j]-prefix[i]);
			}
			//cout << dp[i] << endl;
		}
		return dp[(1<<N)-1]+1;
	}
};

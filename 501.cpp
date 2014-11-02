#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007ll
class FoxAverageSequence
{
	public:
	ll dp[2][1650][45][2];
	int theCount(vector <int> seq)
	{
		int N = (int)seq.size();
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0]=1;
		for(int i=0;i<seq.size();i++)
		{
			memset(dp[(i+1)%2],0,sizeof(dp[(i+1)%2]));
			for(int j=0;j<=1600;j++)
			{
				for(int k=0;k<=40;k++)
				{
					for(int l=0;l<=40;l++)
					{
						if(!(seq[i]==-1||seq[i]==l))continue;
						if(j+l>1600)break;
						if(l*i>j)break;
						if(k>l)
						{
							dp[(i+1)%2][j+l][l][1]+=dp[i%2][j][k][0];
							dp[(i+1)%2][j+l][l][1]%=MOD;
						}
						else
						{
							dp[(i+1)%2][j+l][l][0]+=(dp[i%2][j][k][0]+dp[i%2][j][k][1]);
							dp[(i+1)%2][j+l][l][0]%=MOD;
						}
					}
				}
			}
		}
		ll ans = 0ll;
		for(int i=0;i<=1600;i++)
		{
			for(int j=0;j<=40;j++)
			{
				for(int k=0;k<2;k++)
				{
					ans += dp[N%2][i][j][k];
					ans %= MOD;
				}
			}
		}
		return ans;
	}
};

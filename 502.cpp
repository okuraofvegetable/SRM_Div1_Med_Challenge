#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define pb push_back
vector<ll> p,r;
bool comp(int a,int b)
{
	return p[a]*r[b] > p[b]*r[a];
}
class TheProgrammingContestDivOne
{
	public:
	ll dp[55][100100];
	vector<int> vec;
	int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime)
	{
		for(int i=0;i<pointsPerMinute.size();i++)p.pb(pointsPerMinute[i]);
		for(int i=0;i<requiredTime.size();i++)r.pb(requiredTime[i]);
		for(int i=0;i<maxPoints.size();i++)vec.pb(i);
		sort(vec.begin(),vec.end(),comp);
		for(int i=0;i<55;i++)
		{
			for(int j=0;j<100100;j++)
			{
				dp[i][j]=-INF;
			}
		}
		dp[0][0]=0;
		for(int i=0;i<vec.size();i++)
		{
			for(int t=0;t<=T;t++)
			{
				dp[i+1][t]=max(dp[i+1][t],dp[i][t]);
				if(t+r[vec[i]]<=T)
				{
					dp[i+1][t+r[vec[i]]]=max(dp[i+1][t+r[vec[i]]],dp[i][t]+maxPoints[vec[i]]-(t+r[vec[i]])*p[vec[i]]);
				}
			}
		}
		ll ans = 0;
		for(int i=0;i<=T;i++)ans = max(ans,dp[(int)vec.size()][i]);
		return (int)ans;
	}
};

#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define INF 1000000000000000
class TimeTravellingTour
{
	public:
	vector<int> city;
	ll dist[55][55];
	ll dp[55][55][55];
	int N,M;
	ll rec(int cur,int l,int r)
	{
		if(dp[cur][l][r]!=-1)return dp[cur][l][r];
		if(l==r)return dist[cur][city[l]];
		ll res = dist[cur][city[l]]+rec(city[l],l+1,r);
		for(int i=0;i<N;i++)
		{
			for(int j=l;j<r;j++)
			{
				res = min(res,dist[cur][i]+rec(i,l,j)+rec(i,j+1,r));
			}
		}
		return dp[cur][l][r]=res;
	}
	long long determineCost(int N, vector <int> cities, vector <string> roads)
	{
		this->N = N;
		M = (int)cities.size();
		city = cities;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				dist[i][j]=INF;
				if(i==j)dist[i][j]=0;
			}
		}
		string t;
		for(int i=0;i<roads.size();i++)
		{
			for(int j=0;j<roads[i].size();j++)if(roads[i][j]==',')roads[i][j]=' ';
			t += roads[i];
		}
		stringstream ss;
		ss << t;
		int a,b,c;
		while(ss >> a >> b >> c)
		{
			//printf("%d %d %d\n",a,b,c);
			dist[a][b]=c;
			dist[b][a]=c;
		}
		for(int k=0;k<N;k++)
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		memset(dp,-1,sizeof(dp));
		return (rec(0,0,M-1)>=INF?-1:rec(0,0,M-1));
	}
};

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define SQ(X) ((X)*(X))
#define pb push_back
vector<ll> cx,cy,vx,vy;
int N,M;
double dist[55][55];
double nc[55];
class KingdomXCitiesandVillages
{
	public:
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY)
	{
		N = cityX.size();
		M = villageX.size();
		for(int i=0;i<N;i++)
		{
			cx.pb(cityX[i]);
			cy.pb(cityY[i]);
		}
		for(int i=0;i<M;i++)
		{
			vx.pb(villageX[i]);
			vy.pb(villageY[i]);
		}
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<M;j++)
			{
				dist[i][j]=sqrt((double)(SQ(abs(vx[i]-vx[j]))+SQ(abs(vy[i]-vy[j]))));
			}
		}
		for(int i=0;i<M;i++)
		{
			nc[i]=INF;
			for(int j=0;j<N;j++)
			{
				nc[i]=min(nc[i],sqrt((double)(SQ(abs(vx[i]-cx[j]))+SQ(abs(vy[i]-cy[j])))));
			}
		}
		double ans = 0.0;
		for(int i=0;i<M;i++)
		{
			vector<double> vec;
			for(int j=0;j<M;j++)
			{
				if(i==j)continue;
				vec.pb(min(dist[i][j],nc[i]));
			}
			vec.pb(nc[i]);
			sort(vec.begin(),vec.end());
			for(int j=0;j<vec.size();j++)
			{
				if(vec[j]==nc[i])
				{
					//cout << vec[j] << ' ' << 1.0/(j+1.0) << endl;
					ans += vec[j]*(1.0/(j+1.0));
					break;
				}
				else
				{
					ans += vec[j]*(1.0/(j+1.0)/(j+2.0));
					//cout << vec[j] << ' '<< 1.0/(j+1.0)/(j+2.0) << endl;
				}
			}
		}
		return ans;
	}
};

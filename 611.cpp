#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define pb push_back
#define eps 1e-7
#define INF 2000000000
#define fi first
#define sec second
#define sq(X) ((X)*(X))
struct edge
{
	double cost;
	int from,to;
	edge(double cost,int from,int to):cost(cost),from(from),to(to){}
	bool operator < (const edge& a) const
	{
		return cost < a.cost;
	}
};
struct UnionFind
{
	int par[30],rank[30];
	void init()
	{
		for(int i=0;i<30;i++)par[i]=i,rank[i]=0;
	}
	int find(int x)
	{
		if(par[x]==x)return x;
		else return par[x]=find(par[x]);
	}
	void unite(int a,int b)
	{
		a = find(a);
		b = find(b);
		if(a==b)return;
		if(rank[a]<rank[b])par[a]=b;
		else
		{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
}uf;
int N;
vector<ll> X,Y;
vector<edge> Edge;
vector<double> cand;
double d[2]={-1.0,1.0};
double dist(int a,int b)
{
	return sqrt(sq(X[a]-X[b])+sq(Y[a]-Y[b]));
}
class Egalitarianism2
{
	public:
	double minStdev(vector <int> x, vector <int> y)
	{
		N = (int)x.size();
		for(int i=0;i<x.size();i++)
		{
			X.pb((ll)x[i]);
			Y.pb((ll)y[i]);
		}
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				Edge.pb(edge(dist(i,j),i,j));
			}
		}
		for(int i=0;i<Edge.size();i++)
		{
			cand.pb(Edge[i].cost);
		}
		sort(cand.begin(),cand.end());
		sort(Edge.begin(),Edge.end());
		double ans = INF;
		for(int i=0;i<cand.size();i++)
		{
			for(int j=i+1;j<cand.size();j++)
			{
				for(int t=0;t<2;t++)
				{
					double para = (cand[i]+cand[j])/2.0+eps*d[t];
					vector<P> vec;
					for(int k=0;k<Edge.size();k++)vec.pb(P(abs(Edge[k].cost-para),k));
					sort(vec.begin(),vec.end());
					uf.init();
					double sum=0;
					vector<double> val;
					for(int k=0;k<vec.size();k++)
					{
						int idx = vec[k].sec;
						if(!uf.same(Edge[idx].from,Edge[idx].to))
						{
							uf.unite(Edge[idx].from,Edge[idx].to);
							sum+=Edge[idx].cost;
							val.pb(Edge[idx].cost);
						}
					}
					double ave = sum/(double)(N-1);
					double c = 0.0;
					for(int i=0;i<val.size();i++)c+=sq(val[i]-ave);
					double dev = sqrt(c/(double)(N-1));
					ans = min(ans,dev);
				}
			}
		}
		return ans;
	}
};

#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1000000000
class WhiteSpaceEditing
{
	public:
	int dp[55][55][55][2];
	vector<int> l;
	int rec(int a,int b,int v,int d)
	{
		if(dp[a][b][v][d]!=-1)return dp[a][b][v][d];
		if(a==b)return abs(l[a]-l[v]);
		if(d==0)
		{
			int res = INF;
			for(int i=0;i<l.size();i++)
			{
				res = min(res,rec(a,b,i,1)+abs(l[i]-l[v]));
			}
			return dp[a][b][v][d]=res;
		}
		else
		{
			int res = INF;
			for(int i=a;i<b;i++)
			{
				res = min(res,rec(a,i,v,0)+rec(i+1,b,v,0));
			}
			return dp[a][b][v][d]=res;
		}
	}
	int getMinimum(vector <int> lines)
	{
		l = lines;
		l.push_back(0);
		memset(dp,-1,sizeof(dp));
		int N = (int)lines.size();
		return rec(0,N-1,N,0)+N-1;
	}
};

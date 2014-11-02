#include <cstring>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#define INF 10000000
class PalindromizationDiv1
{
	public:
	int add[30];
	int erase[30];
	int change[30][30];
	int dp[55][55];
	string Word;
	int rec(int l,int r)
	{
		if(l>=r)return 0;
		if(dp[l][r]!=-1)return dp[l][r];
		if(Word[l]==Word[r])return dp[l][r]=rec(l+1,r-1);
		int res=INF;
		int L = Word[l]-'a',R = Word[r]-'a';
		if(add[R]!=-1)res = min(res,rec(l,r-1)+add[R]);
		if(add[L]!=-1)res = min(res,rec(l+1,r)+add[L]);
		if(erase[R]!=-1)res = min(res,rec(l,r-1)+erase[R]);
		if(erase[L]!=-1)res = min(res,rec(l+1,r)+erase[L]);
		if(change[R][L]!=-1)res = min(res,rec(l+1,r-1)+change[R][L]);
		if(change[L][R]!=-1)res = min(res,rec(l+1,r-1)+change[L][R]);
		return dp[l][r]=res;
	}
	int getMinimumCost(string word, vector <string> operations)
	{
		Word = word;
		for(int i=0;i<30;i++)for(int j=0;j<30;j++)change[i][j]=INF;
		for(int i=0;i<30;i++)change[i][i]=0;
		for(int i=0;i<30;i++)add[i]=INF;
		for(int i=0;i<30;i++)erase[i]=INF;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<operations.size();i++)
		{
			stringstream ss;
			ss << operations[i];
			string op;
			ss >> op;
			string a,b;
			int cost;
			if(op=="add")
			{
				ss >> a >> cost;
				add[a[0]-'a']=cost;
			}
			else if(op=="erase")
			{
				ss >> a >> cost;
				erase[a[0]-'a']=cost;
			}
			else
			{
				ss >> a >> b >> cost;
				change[a[0]-'a'][b[0]-'a']=cost;
			}
		}
		for(int k=0;k<30;k++)for(int i=0;i<30;i++)for(int j=0;j<30;j++)change[i][j]=min(change[i][j],change[i][k]+change[k][j]);
		for(int k=0;k<30;k++)
		{
			for(int i=0;i<30;i++)
			{
				for(int j=0;j<30;j++)
				{
					if(change[i][j]!=INF&&erase[j]!=INF)
					{
						erase[i]=min(erase[i],change[i][j]+erase[j]);
					}
				}
			}
		}
		int ans = rec(0,(int)word.size()-1);
		if(ans>=INF)return -1;
		else return ans;
	}
};

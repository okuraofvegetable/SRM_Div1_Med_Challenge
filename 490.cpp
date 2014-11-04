#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define INF 1000000000
#define pb push_back
int key[256];
vector<string> vec;
map<string,set<string> > D;
map<string,int> M;
int dp[55];
class QuickT9
{
	public:
	int minimumPressings(vector <string> t9, string word)
	{
		int a[8]={3,3,3,3,3,4,3,4};
		int cnt=0;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<a[i];j++)
			{
				key['a'+cnt] = i;
				cnt++;
			}
		}
		for(int i=0;i<t9.size();i++)
		{
			stringstream ss;
			ss << t9[i];
			string s;
			while(ss >> s)vec.pb(s);
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++)
		{
			string tmp;
			for(int j=0;j<vec[i].size();j++)
			{
				int p = vec[i][j]-'a';
				tmp += key[p+'a']+'0';
				D[tmp].insert(vec[i].substr(0,j+1));
			}
		}
		map<string,set<string> >::iterator it;
		set<string>::iterator itr;
		for(it = D.begin();it!=D.end();it++)
		{
			int len = (int)((it->first).size());
			int k=0;
			for(itr=(it->second).begin();itr!=(it->second).end();itr++)
			{
				if(!M.count(*itr)||M[*itr]>len+k+1)M[*itr]=len+k+1;//length + jishojun + kakutei
				string s;
				for(int i=0;i<(int)(itr->size())-1;i++)
				{
					s+=(*itr)[i];
					if(!M.count(s)||M[s]>len+k+(int)(itr->size())-i-1)M[s]=len+k+(int)(itr->size())-i-1;//length + jishojun + sakujo(kakuteikomi)
				}
				k++;
			}
		}
		for(int i=0;i<55;i++)dp[i]=INF;
		dp[0] = 0;
		int ws = (int)word.size();
		for(int i=1;i<=ws;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(M.count(word.substr(j,i-j)))dp[i] = min(dp[i],dp[j]+M[word.substr(j,i-j)]);
			}
		}
		return ((dp[ws]==INF)?-1:dp[ws]);
	}
};

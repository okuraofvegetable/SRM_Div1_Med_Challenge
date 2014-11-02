#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll f[2][2505];
ll num[1<<11],dp[11][1<<11];
int fr[11][11];
int eo[11][11];
int H,W;
class MagicalGirlLevelTwoDivOne
{
	public: 
	int theCount(vector <string> palette, int n, int m)
	{
		H = palette.size(); W=palette[0].size();
		f[0][0]=f[1][0]=1;
		for(int i=1;i<=2500;i++)
		{
			f[0][i]=(f[0][i-1]*4)%MOD;
			f[1][i]=(f[1][i-1]*5)%MOD;
		}
		memset(eo,-1,sizeof(eo));
		memset(fr,0,sizeof(fr));
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(palette[i][j]!='.')
				{
					int k = (palette[i][j]-'0')%2;
					if(eo[i%n][j%m]!=-1&&eo[i%n][j%m]!=k)return 0;
					else eo[i%n][j%m]=k;
				}
				else
				{
					fr[i%n][j%m]++;
				}
				//cout << fr[i][j] << ' ';
			}
			//cout << endl;
		}
		memset(dp[0],0,sizeof(dp[0]));
		dp[0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int mask=0;mask<(1<<m);mask++)if(__builtin_popcount(mask)%2==1)
			{
				num[mask]=1;
				for(int j=0;j<m;j++)
				{
					if(eo[i][j]==-1)num[mask]=(num[mask]*f[(mask>>j)&1][fr[i][j]])%MOD;
					else
					{
						if(((mask>>j)&1)!=eo[i][j])
						{
							num[mask]=0;
							break;
						}
						else num[mask]=(num[mask]*f[eo[i][j]][fr[i][j]])%MOD;
					}
				}
				for(int mask2=0;mask2<(1<<m);mask2++)
				{
					dp[i+1][mask^mask2]+=((dp[i][mask2]*num[mask])%MOD);
					dp[i+1][mask^mask2]%=MOD;
				}
			}
		}
		return dp[n][(1<<m)-1];
	}
};

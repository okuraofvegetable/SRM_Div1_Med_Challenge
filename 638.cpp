#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define INF 2000000000
#define MOD 1000000007
class NarrowPassage2
{
	public:
	int N;
	bool used[55];
	int count(vector<int> size,int maxSizeSum)
	{
		N = (int)size.size();
		ll ans = 1ll;
		memset(used,false,sizeof(used));
		for(int i=0;i<N;i++)
		{
			int mi=INF,id=0,cnt=1;
			for(int j=0;j<N;j++)if(!used[j]&&size[j]<mi)
			{
				mi=size[j],id=j;
			}
			for(int j=id-1;j>=0;j--)if(!used[j])
			{
				if(size[id]+size[j]<=maxSizeSum)cnt++;
				else break;
			}
			for(int j=id+1;j<N;j++)if(!used[j])
			{
				if(size[id]+size[j]<=maxSizeSum)cnt++;
				else break;
			}
			used[id]=true;
			ans = (ans*cnt)%MOD;
		}
		return (int)ans;
	}
};

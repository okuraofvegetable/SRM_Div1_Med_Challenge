typedef long long ll;
#define MOD 1000000007
class SuperSum
{
	public:
	ll modpow(ll a,int x)
	{
		ll ret=1ll;
		while(x>0)
		{
			if(x&1)ret = (ret*a)%MOD;
			a = (a*a)%MOD;
			x>>=1;
		}
		return ret;
	}
	ll inv[60];
	ll C(int n,int k)
	{
		ll ret = 1ll;
		for(int i=0;i<k;i++)ret = (ret*(n-i))%MOD;
		for(int i=1;i<=k;i++)ret = (ret*inv[i])%MOD;
		return ret;
	} 
	int calculate(int k, int n)
	{
		for(int i=1;i<=60;i++)inv[i] = modpow(i,MOD-2);
		return (int)C(n+k,k+1);
	}
};

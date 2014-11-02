#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
class CubePacking
{
	public:
	ll l,nb;
	bool check(ll x)
	{
		vector<ll> fac;
		for(ll i=1;i*i<=x;i++)if(x%i==0)
		{
			fac.pb(i);
			if(i!=x/i)fac.pb(x/i);
		}
		sort(fac.begin(),fac.end());
		//for(int i=0;i<fac.size();i++)cout << fac[i] << endl;
		for(int i=0;i<fac.size();i++)
		{
			if(fac[i]>x/fac[i])break;
			for(int j=i;j<fac.size();j++)
			{
				if(x/(fac[i]*fac[j])<fac[j])break;
				if(x%(fac[i]*fac[j])!=0)continue;
				//cout << fac[i] << fac[j] << x/fac[i]/fac[j] << x/(fac[i]*fac[j]) << endl;
				if((fac[i]/l)*(fac[j]/l)*((x/(fac[i]*fac[j]))/l)>=nb)return true;
			}
		}
		return false;
	}
	int getMinimumVolume(int Ns, int Nb, int L)
	{
		l=L;
		nb = Nb;
		ll sum = (ll)Ns + l*l*l*nb;
		while(!check(sum))sum++;
		return sum;
	}
};

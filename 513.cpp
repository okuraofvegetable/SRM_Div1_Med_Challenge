class PerfectMemory
{
	public:
	double dp[2000][2000];
	double rec(int a,int b)
	{
		if(dp[a][b]!=0)return dp[a][b];
		if(a==0&&b==0)return 0.0;
		dp[a][b]=1.0;
		double A = 2*a;
		double B = b;
		double S = 2*a+b;
		if(b>0)dp[a][b]+=B/S*rec(a,b-1);
		if(a>0)dp[a][b]+=A/S/(S-1)*rec(a-1,b);
		if(a>0)dp[a][b]+=A/S*B/(S-1)*(1.0+rec(a-1,b));
		if(a>1)dp[a][b]+=A/S*(A-2)/(S-1)*rec(a-2,b+2);
		return dp[a][b];
	}
	double getExpectation(int N, int M)
	{
		return rec(N*M/2,0);
	}
};

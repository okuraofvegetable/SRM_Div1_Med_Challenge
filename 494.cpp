#include <vector>
using namespace std;
class AlternatingLane
{
	public:
	double expectedBeauty(vector <int> low, vector <int> high)
	{
		int N = (int)low.size();
		double ans = 0.0;
		for(int i=0;i<N-1;i++)
		{
			double t = 0.0;
			for(int j=low[i];j<=high[i];j++)
			{
				if(low[i+1]>=j)t+=((high[i+1]+low[i+1])/2.0-j)*(high[i+1]-low[i+1]+1);
				else if(high[i+1]<=j)t+=(j-(high[i+1]+low[i+1])/2.0)*(high[i+1]-low[i+1]+1);
				else
				{
					t+=((high[i+1]+j)/2.0-j)*(high[i+1]-j+1);
					t+=(j-(low[i+1]+j-1)/2.0)*(j-low[i+1]);
				}
			}
			ans += t/(high[i]-low[i]+1)/(high[i+1]-low[i+1]+1);
		}
		return ans;
	}
};

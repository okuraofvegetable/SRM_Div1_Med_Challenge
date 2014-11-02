typedef long long ll;
class BedroomFloor
{
	public:
	ll num[6]={0};
	long long numberOfSticks(int x1, int y1, int x2, int y2)
	{
		ll ans=0ll;
		int lx=(x1/5+((x1%5!=0)?1:0))*5;
		int rx=(x2/5)*5;
		int uy=(y1/5+((y1%5!=0)?1:0))*5;
		int dy=(y2/5)*5;
		ans+=((ll)(rx-lx))*(dy-uy)/5;
		ll k = (dy-uy)/10;
		num[lx-x1]+=5*k;
		num[5]+=(lx-x1)*k;
		if((lx/5+uy/5)%2==0&&(dy-uy)%10!=0)num[5]+=(lx-x1);
		else if((lx/5+uy/5)%2==1&&(dy-uy)%10!=0)num[lx-x1]+=5;
		num[x2-rx]+=5*k;
		num[5]+=(x2-rx)*k;
		if((rx/5+uy/5)%2==0&&(dy-uy)%10!=0)num[x2-rx]+=5;
		if((rx/5+uy/5)%2==1&&(dy-uy)%10!=0)num[5]+=(x2-rx);
		k = (rx-lx)/10;
		num[5]+=(uy-y1)*k;
		num[uy-y1]+=5*k;
		if((lx/5+uy/5)%2==0&&(rx-lx)%10!=0)num[uy-y1]+=5;
		else if((lx/5+uy/5)%2==1&&(rx-lx)%10!=0)num[5]+=uy-y1;
		num[5]+=(y2-dy)*k;
		num[y2-dy]+=5*k;
		if((lx/5+dy/5)%2==0&&(rx-lx)%10!=0)num[y2-dy]+=5;
		else if((lx/5+dy/5)%2==1&&(rx-lx)%10!=0)num[5]+=y2-dy;
		if((lx/5+uy/5)%2==0)num[lx-x1]+=uy-y1;
		else num[uy-y1]+=lx-x1;
		if((lx/5+dy/5)%2==0)num[y2-dy]+=lx-x1;
		else num[lx-x1]+=y2-dy;
		if((rx/5+dy/5)%2==0)num[x2-rx]+=y2-dy;
		else num[y2-dy]+=x2-rx;
		if((rx/5+uy/5)%2==0)num[uy-y1]+=x2-rx;
		else num[x2-rx]+=uy-y1;
		ll rem2=0,rem1=0;
		ans+=num[5];
		ans+=num[4];rem1+=num[4];
		ans+=num[3];rem2+=num[3];
		if(num[2]<=rem2)rem2-=num[2];
		else
		{
			ans+=(num[2]-rem2+1)/2;
			rem1+=((num[2]-rem2+1)/2)*5-2*(num[2]-rem2);
			rem2=0;
		}
		rem1+=rem2*2;
		if(rem1<num[1])
		{
			ll t = num[1]-rem1;
			ans+=t/5;
			if(t%5!=0)ans++;
		}
		return ans;
	}
};

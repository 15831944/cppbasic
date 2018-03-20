#include <iostream>
using namespace std;
int main ()
{
	long x,a[4];
	cin>>x;
	for(a[0]=0;a[0]*a[0]<=x/4;a[0]++)
		for(a[1]=0;a[1]*a[1]<=x/3;a[1]++)
			for(a[2]=0;a[2]*a[2]<=x/2;a[2]++)
				for(a[3]=0;a[3]*a[3]<=x;a[3]++)
					if(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]+a[3]*a[3]==x)
					{
						cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
						return 0;
					}
}

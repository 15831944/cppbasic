#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int w,m,n,ai,aj,bi,bj;
	cin>>w>>m>>n;
	if(m%w==0){
		ai=m/w-1;
		aj=0;
	}
	else {
		ai=m/w;
		if((m/w)%2==0) aj=m%w-1;
		else m=w-m%w;
	}
	if(n%w==0) {
		bi=n/w-1;
		bj=0;
	}
	else{
		bi=n/w;
		if((m/w)%2==0) aj=m%w-1;
		else m=w-m%w;
	}
	cout<<fabs(ai-bi)+fabs(aj-bj);
	return 0;
}

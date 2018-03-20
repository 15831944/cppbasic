#include <iostream>
using namespace std;
int main ()
{
	int a[15]={99,87,85,65,61,51,43,41,39,35,30,20,19,13,1};
	int x,m=0,n=14,b;
	cin>>x;
	while(1)
	{
		b=(m+n)/2;
		if(a[b]==x) {
			cout<<b+1;
			break;
		}
		else if(a[b]<x){
			n=b-1;
		}
		else if(a[b]>x){
			m=b+1;
		}
		if(m>n){
			cout<<"ÎÞ´ËÊý£¡";
			break;
		}
	}
	return 0;
}

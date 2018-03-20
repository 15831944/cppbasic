#include <iostream>
using namespace std;
int main ()
{
	int a,b,c;
	long fac(int x);
	cin>>a>>b>>c;
	cout<<fac(a)+fac(b)+fac(c);
	return 0;
}
long fac(int x)
{
	long sum=1;
	for(int i=2;i<=x;i++)
		sum*=i;
	return sum;
}

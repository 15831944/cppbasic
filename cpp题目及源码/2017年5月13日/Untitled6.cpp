#include <iostream>
using namespace std;
int main ()
{
	int n,f1,f2;
	f1=f2=1;
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		int f3;
		f3=f1+f2;
		f1=f2%10007;
		f2=f3%10007;
	}
	cout<<f2;
	return 0;
}

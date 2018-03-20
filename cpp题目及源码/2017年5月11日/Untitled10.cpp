#include <iostream>
using namespace std;
int main ()
{
	long long int  n,max;
	cin>>n;
	max=n;
	while(n!=1)
	{
		if(n%2==0) n/=2;
		else n=n*3+1;
		if(n>max) max=n;
		//cout<<n<<" ";
	}
	//cout<<endl;
	cout<<max;
	return 0;
}

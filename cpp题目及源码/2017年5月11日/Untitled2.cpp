#include <iostream>
using namespace std;
int main ()
{
	char str[100];
	int count=0;
	unsigned long long int x;
	cin>>x;
	while(x!=0)
	{
		str[count++]=x%10+'0';
		x/=10;
	}
	for(int i=count-1;i>=0;i--)
		cout<<str[i]<<" ";
	return 0;
}


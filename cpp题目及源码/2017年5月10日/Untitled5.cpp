#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	for(int i=1;i<10000;i++)
	{
		int m,n;
		m=sqrt(i+100);
		n=sqrt(i+168);
		if(m*m==i+100 && n*n==i+168)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}

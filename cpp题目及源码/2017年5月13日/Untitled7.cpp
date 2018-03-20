#include <iostream>
using namespace std;
int main ()
{
	int l,r,count=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		int j;
		if(i==2 || i==3)
		{
			count++;
			continue;
		}
		for(j=2;j*j<=i;j++)
			if(i%j==0) 
				break;
		if(i%j!=0) count++;
	}
	cout<<count;
	return 0;
	
}

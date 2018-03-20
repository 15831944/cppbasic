#include <iostream>
using namespace std;
int main()
{
	int sum=0,a[10],x=0;
	for(int i=999;i>0;i=i-2)
	{
		int j;
		for(j=2;j<i;j++)
		{
			if(i%j==0) break;
		}
		if(j==i)
		{
			sum+=i;
			a[x++]=i;
		}
		if(x==10) break;
	}
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl<<sum;
	return 0; 
}

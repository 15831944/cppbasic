#include <iostream>
using namespace std;
int main ()
{
	int count=0,a[50];
	for(int i=1;i<5;i++)
		for(int j=1;j<5;j++)
			for(int k=1;k<5;k++)
			{
				if(i==j || i==k || j==k) continue;
				a[count++]=i*100+j*10+k;
			}
	cout<<count<<endl;
	for(int i=0;i<count;i++)
		cout<<a[i]<<endl;
	return 0;
}

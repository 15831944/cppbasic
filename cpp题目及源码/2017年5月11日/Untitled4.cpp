#include <iostream>
using namespace std;
int main ()
{
	int a[10]={1,5,4,6,3,8,4,6,2,9};
	for(int i=0;i<10;i++)
		for(int j=0;j<9;j++)
			if(a[j+1]<a[j])
			{
				a[j+1]=a[j+1]+a[j];
				a[j]=a[j+1]-a[j];
				a[j+1]=a[j+1]-a[j];
			}	
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
}

#include <iostream>
using namespace std;
int main ()
{
	int a[10]={1,5,4,6,3,8,4,6,2,9};
	for(int i=0;i<10;i++)
	{
		int x=a[i],min=i;
		for(int j=i;j<10;j++)
			if(a[j]<a[min]) 
			{
				x=a[j];
				min=j;
			}
		if(min!=i)
		{
			a[i]+=a[min];
			a[min]=a[i]-a[min];
			a[i]-=a[min];	//�����������ʲô��˼ 
		}
	}
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
}

#include <iostream>
using namespace std;
int main ()
{
	int n,k,count=0;
	cin>>n>>k; 
	int *p=new int [n];
	for(int i=0;i<n;i++)
		cin>>*(p+i);
	for(int i=0;i<n;i++)
		for(int j=i,sum=0;j<n;j++)
		{
			sum+=*(p+j);
			if(sum%k==0) count++;
		}
	cout<<count;
	return 0;
}

#include <iostream>
using namespace std;
int main ()
{
	int n,count=0,i=1,a[100],f=1;
	cin>>n;
	for(i=0;i<n;i++)
		a[i]=i+1;
	while(1)
	{
		i=(i+1)%n;
		if(a[i]!=0) f++;
		else continue;
		if(f==3){
			f=0;
			a[i]=0;
			count++;
		}
		if(count==n-1) break;
	}
	for(i=0;i<n;i++)
		if(a[i]!=0){
			cout<<i+1;
			break;
		}
	return 0;
}

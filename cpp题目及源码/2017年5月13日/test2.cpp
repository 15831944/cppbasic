#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n,m;
	cin>>n;
	int *p=new int [n];
	for(int i=0;i<n;i++)
		cin>>*(p+i);
	cin>>m;
	int *l=new int [m];
	int *r=new int [m];
	int *k=new int [m];
	//int *result=new int [m];
	for(int i=0;i<m;i++)
	{
		cin>>*(l+i);
		cin>>*(r+i);
		cin>>*(k+i);
	}
	for(int i=0;i<m;i++)
	{
		int ll=*(l+i),rr=*(r+i),kk=*(k+i);
		int a[rr-ll+1];
		for(int j=ll;j<=rr;j++)
			a[j-ll]=*(p+j-1);
		sort(a,a+rr-ll+1);
		cout<<a[rr-ll+1-kk]<<endl;
	}
	return 0;
}

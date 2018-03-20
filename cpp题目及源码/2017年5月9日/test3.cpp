#include <iostream>
using namespace std;
int main ()
{
	int m,n,gbs,gys;
	cin>>m>>n;
	int a,b;
	a=m,b=n;
	if(a<b) 
	{
		a=a+b;
		b=a-b;
		a=a-b;
	}
	while(b!=0)	//欧几里得算法 
    {
    	int x;
        x=a%b;
        a=b;
        b=x;
    }
    gys=a;
    gbs=m*n/gys;
    cout<<"最大公约数："<<gys<<endl;
    cout<<"最小公倍数："<<gbs<<endl;
    return 0;
}

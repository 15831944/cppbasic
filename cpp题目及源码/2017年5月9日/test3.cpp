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
	while(b!=0)	//ŷ������㷨 
    {
    	int x;
        x=a%b;
        a=b;
        b=x;
    }
    gys=a;
    gbs=m*n/gys;
    cout<<"���Լ����"<<gys<<endl;
    cout<<"��С��������"<<gbs<<endl;
    return 0;
}

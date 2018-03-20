#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	long x,arr[4];
	cout<<"请输入一个正整数："<<endl;
	cin>>x;
	if(x<1) 
	{
		cout<<"数据非法！"<<endl;
		return 0;
	 } 
	for(arr[0]=0;arr[0]<=sqrt(x/4);arr[0]++)
		for(arr[1]=0;arr[1]<=sqrt(x/3);arr[1]++)
			for(arr[2]=0;arr[2]<=sqrt(x/2);arr[2]++)
				for(arr[3]=1;arr[3]<=sqrt(x);arr[3]++)
					if(arr[0]*arr[0]+arr[1]*arr[1]+arr[2]*arr[2]+arr[3]*arr[3]==x)
					{
						cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;
						return 0;
					}
}

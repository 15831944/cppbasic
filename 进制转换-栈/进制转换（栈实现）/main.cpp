#include <iostream>
#include "stack.h"
using namespace std;
int main ()
{
	Stack stack;
	int n,hex;
	char arr[]="0123456789ABCDEF";
	cout<<"请选择你需要讲十进制转换为什么进制：\n"<<endl;
	cout<<"  十六进制请输入16，2-9进制请输入相应的数字\n"<<endl;
	cout<<"请输入：";
	cin>>hex;
	if(hex!=16 && (hex<2 || hex>10))
	{
		cout<<"请输入数据无效"<<endl;
		return 0;
	}
	cout<<"\n请输入您需要转换的数字：";
	cin>>n;
	int temp;
	if(n<0) temp=-n;
	else temp=n;
	while(temp!=0)
	{
		stack.push(temp%hex);
		temp/=hex;
	}
	cout<<endl<<n<<"转换为"<<hex<<"进制数为：";
	if(n<0) cout<<"-";
	while(1)
	{
		temp=stack.pop();
		if(temp==-1)
			break;
		if(hex!=16)
			cout<<temp;
		else
			cout<<arr[temp];
	}
	cout<<endl<<endl;
	return 0;
}
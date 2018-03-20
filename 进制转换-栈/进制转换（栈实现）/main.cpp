#include <iostream>
#include "stack.h"
using namespace std;
int main ()
{
	Stack stack;
	int n,hex;
	char arr[]="0123456789ABCDEF";
	cout<<"��ѡ������Ҫ��ʮ����ת��Ϊʲô���ƣ�\n"<<endl;
	cout<<"  ʮ������������16��2-9������������Ӧ������\n"<<endl;
	cout<<"�����룺";
	cin>>hex;
	if(hex!=16 && (hex<2 || hex>10))
	{
		cout<<"������������Ч"<<endl;
		return 0;
	}
	cout<<"\n����������Ҫת�������֣�";
	cin>>n;
	int temp;
	if(n<0) temp=-n;
	else temp=n;
	while(temp!=0)
	{
		stack.push(temp%hex);
		temp/=hex;
	}
	cout<<endl<<n<<"ת��Ϊ"<<hex<<"������Ϊ��";
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
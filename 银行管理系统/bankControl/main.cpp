#include <iostream>
#include "bankUser.h"
using namespace std;

int main ()
{
	int x;		//���ܱ�־����

	cout<<"��ӭʹ�ã�"<<endl;
loop:
{
	MenuCout();		//����˵�ѡ����Ŀ
	cin>>x;
	if(x==1)	//����
	{
		CreateAccount();
		cout<<endl;
		goto loop;
	}
	else if(x==2)	//����
	{
		DeleteAccount();
		cout<<endl;
		goto loop;
	}
	else if(x==3)	//���
	{
		Deposit();
		cout<<endl;
		goto loop;
	}
	else if(x==4)	//ȡ��
	{
		RemoveMoney();
		cout<<endl;
		goto loop;
	}
	else if(x==5)	//ת��
	{
		TransferAccounts();
		cout<<endl;
		goto loop;
	}
	else if(x==6)	//��ѯ
	{
		Query();
		cout<<endl;
		goto loop;
	}
	else if(x==7)	//�޸��û���Ϣ
	{
		Revise();
		cout<<endl;
		goto loop;
	}
	else if(x==-1)
	{
		return 0;
	}
	else 
	{
		cout<<endl;
		cout<<"�������ݷǷ�!���������룺"<<endl;
		goto loop;
	}
}
	return 0;
}
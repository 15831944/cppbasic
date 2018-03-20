#include <iostream>
#include "bankUser.h"
using namespace std;

int main ()
{
	int x;		//功能标志变量

	cout<<"欢迎使用！"<<endl;
loop:
{
	MenuCout();		//输出菜单选择栏目
	cin>>x;
	if(x==1)	//开户
	{
		CreateAccount();
		cout<<endl;
		goto loop;
	}
	else if(x==2)	//销户
	{
		DeleteAccount();
		cout<<endl;
		goto loop;
	}
	else if(x==3)	//存款
	{
		Deposit();
		cout<<endl;
		goto loop;
	}
	else if(x==4)	//取款
	{
		RemoveMoney();
		cout<<endl;
		goto loop;
	}
	else if(x==5)	//转账
	{
		TransferAccounts();
		cout<<endl;
		goto loop;
	}
	else if(x==6)	//查询
	{
		Query();
		cout<<endl;
		goto loop;
	}
	else if(x==7)	//修改用户信息
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
		cout<<"输入数据非法!请重新输入："<<endl;
		goto loop;
	}
}
	return 0;
}
#include "bankUser.h"

//bankUser成员函数

bankUser::bankUser()   //无参构造函数
{

}

bankUser::~bankUser()	//析构函数
{

}

void bankUser::setID(unsigned long long int _ID)	//设置用户账号函数
{
	m_uID=_ID;
}

unsigned long long int bankUser::getID()	//获取用户账号函数
{
	return m_uID;
}

void bankUser::setName(string &_name)	//设置用户姓名
{
	m_sName=_name;
}

string* bankUser::getName()	//获取用户姓名
{
	return &m_sName;
}

void bankUser::setSex(string &_sex)	//设置用户性别
{
	m_sSex=_sex;
}

string* bankUser::getSex()	//获取用户性别
{
	return &m_sSex;
}

void bankUser::setBalance(string &_balance)		//设置账户余额
{
	m_sBalance=_balance;
}

string* bankUser::getBalance()	//获取账户余额
{
	return &m_sBalance;
}

void bankUser::setID_number(string &_ID_number)		//设置用户身份证号码
{
	m_sID_number=_ID_number;
}

string* bankUser::getID_number()	//获取用户身份证号码
{
	return &m_sID_number;
}

void bankUser::setCompany(string &_company)		//设置用户工作单位
{
	m_sCompany=_company;
}

string* bankUser::getCompany()		//获取用户工作单位
{
	return &m_sCompany;
}

void bankUser::setTelphone(unsigned long long int _telphone)	//设置用户联系方式
{
	m_uTelphone=_telphone;	
}

unsigned long long int bankUser::getTelphone()		//获取用户联系方式
{
	return m_uTelphone;
}

void bankUser::setAddress(string &_address)		//设置用户家庭住址
{
	m_sAddress=_address;
}

string* bankUser::getAddress()		//获取用户家庭住址
{
	return &m_sAddress;
}

void bankUser::setPassword(string &_password)	//设置用户密码
{
	m_sPassword=_password;
}

string* bankUser::getPassword()	//获取用户密码
{
	return &m_sPassword;
}


//普通函数

void MenuCout()		//输出菜单栏目函数
{
	cout<<endl;
	cout<<"请输入您的需求："<<endl;
	cout<<"    1:开户  2：销户  3：存款  4:取款   5:转账  6：查询  7：修改信息  -1：结束"<<endl;
	cout<<"请输入： ";
}

//1 1000000000 陈希 男 余额 510525199404168914 西华大学 13008142306 四川成都 156489
void CreateAccount()	//开户
{
	vector<bankUser> users;	//存放全部用户信息
	bankUser vec;	//中间变量，存放一个用户信息
	string str;		//存放信息
	long length;	//存储总用户数和计数变量
	unsigned long long int x,_ID;	//存放用户输入的电话号码或新增账号

	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//从文件中读取所有用户信息（方便申请账号）
	infile.close();
	length=users.size();	//获取总用户数目
	_ID=Increase(users,length);	//获取一个新增账号
	vec.setID(_ID);

	while(1)
	{
		bool f_ID_number=false,f_Telphone=false;	//标记变量
		cout<<endl<<endl;
		cout<<"请输入您的基本信息（姓名，性别，身份证号码，单位，电话号码，家庭住址）："<<endl;
		cin>>str;	vec.setName(str);	//输入并存储姓名
		cin>>str;	vec.setSex(str);	//输入并存储性别
		str="0";	vec.setBalance(str);	//默认余额为0
		cin>>str;	vec.setID_number(str);	//输入并存储身份证号码
		f_ID_number=VerifyID_number(str);		//验证用户身份证号码是否合法
		cin>>str;	vec.setCompany(str);	//输入并存储单位
		cin>>x;		vec.setTelphone(x);	//输入并存储电话号码
		f_Telphone=VerifyTelphone(x);		//验证用户电话号码是否合法
		cin>>str;	vec.setAddress(str);	//输入并存储家庭住址
		if(vec.getName()!=NULL && vec.getID_number()!=NULL && f_ID_number && f_Telphone)	break;
		else {
			cout<<endl<<"姓名和身份证号码都不能为空！"<<endl;
			if(!f_ID_number && !f_Telphone)
				cout<<"请输入合法的身份证号码和电话号码！"<<endl;
			cout<<"请重新输入、、"<<endl;
		}
	}
	cout<<"请输入您的密码：";
	cin>>str;	vec.setPassword(str);	//标准输入并存储用户密码
	cout<<"申请账号成功！账号为："<<_ID<<endl;
	cout<<"谢谢使用！"<<endl;
	ofstream outfile("d:\\bankUser.txt");
	ExportOutfile(outfile,users,vec);	//将users和vec中的用户信息按照账号升序存入文件
	outfile.close();
}

void DeleteAccount()	//销户
{
	vector<bankUser> users;	//存放全部用户信息
	int m;	//功能选择变量
	bool f;		//标记变量（用于判断是否销户成功）
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//从文件中读取所有用户信息（方便申请账号）
	infile.close();
	cout<<endl<<"请选择销户方式：1、账号+密码  2、用户名+密码"<<endl;
	cout<<"请输入： ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"请分别输入账号和密码： ";
		cin>>_ID;
		cin>>_password;
		f=DeleteAccount_ID(users,_ID,_password);		//以账号密码销户
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"请分别输入用户名和密码： ";
		cin>>_name;
		cin>>_password;
		f=DeleteAccount_Name(users,_name,_password);		//以用户名+密码方式销户
	}
	else 
	{
		cout<<endl<<"您输入数据非法！"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"销户成功！"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//将users和vec中的用户信息按照账号升序存入文件
		outfile.close();
	}
	else 
	{
		cout<<endl<<"销户失败！未找到相应的用户信息或者您输入的数据不匹配！"<<endl;
	}
}

void Deposit()		//存款
{
	vector<bankUser> users;	//存放全部用户信息
	int m;	//功能选择变量
	bool f;		//标记变量（用于判断是否存款成功）
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//从文件中读取所有用户信息（方便申请账号）
	infile.close();
	cout<<endl<<"请选择存款方式：1、账号+密码  2、用户名+密码"<<endl;
	cout<<"请输入： ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"请分别输入账号和密码： ";
		cin>>_ID;
		cin>>_password;
		f=Deposit_ID(users,_ID,_password);	//以账号+密码方式存款
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"请分别输入用户名和密码： ";
		cin>>_name;
		cin>>_password;
		f=Deposit_Name(users,_name,_password);		//以用户名+密码方式存款
	}
	else 
	{
		cout<<endl<<"您输入数据非法！"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"存款成功！"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//将users和vec中的用户信息按照账号升序存入文件
		outfile.close();
	}
	else 
	{
		cout<<endl<<"未找到相应的用户信息或者您输入的数据不匹配！"<<endl;
	}
}

void RemoveMoney()	//取款	
{
	vector<bankUser> users;	//存放全部用户信息
	int m;	//功能选择变量
	bool f;		//标记变量（用于判断是否取款成功）
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//从文件中读取所有用户信息（方便申请账号）
	infile.close();
	cout<<endl<<"请选择取款方式：1、账号+密码  2、用户名+密码"<<endl;
	cout<<"请输入： ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"请分别输入账号和密码： ";
		cin>>_ID;
		cin>>_password;
		f=RemoveMoney_ID(users,_ID,_password);	//以账号+密码方式取款
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"请分别输入用户名和密码： ";
		cin>>_name;
		cin>>_password;
		f=RemoveMoney_Name(users,_name,_password);	//以用户名+密码方式取款
	}
	else 
	{
		cout<<endl<<"您输入数据非法！"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"取款成功！"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//将users和vec中的用户信息按照账号升序存入文件
		outfile.close();
	}
	else 
	{
		cout<<endl<<"未找到相应的用户信息或者您输入的数据不匹配！"<<endl;
	}
}

void TransferAccounts()	//转账
{
	vector<bankUser> users;	//存放全部用户信息
	int m;	//功能选择变量
	bool f;		//标记变量（用于判断是否转账成功）
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//从文件中读取所有用户信息（方便申请账号）
	infile.close();
	cout<<endl<<"请选择转账方式：1、账号+密码  2、用户名+密码"<<endl;
	cout<<"请输入： ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"请分别输入账号和密码： ";
		cin>>_ID;
		cin>>_password;
		f=TransferAccounts_ID(users,_ID,_password);	//以账号+密码方式转账
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"请分别输入用户名和密码： ";
		cin>>_name;
		cin>>_password;	
		f=TransferAccounts_Name(users,_name,_password);	//以用户名+密码方式转账
	}
	else 
	{
		cout<<endl<<"您输入数据非法！"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"转账成功！"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//将users和vec中的用户信息按照账号升序存入文件
		outfile.close();
	}
	else 
	{
		cout<<endl<<"未找到相应的用户信息或者您输入的数据不匹配！"<<endl;
	}
}

void Query()	//查询
{
	vector<bankUser> users;	//存放全部用户信息
	int m;	//功能选择变量
	bool f;	//标记变量
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//从文件中读取所有用户信息
	infile.close();
	cout<<endl<<"请选择查询方式：1、账号+密码  2、用户名+密码"<<endl;
	cout<<"请输入： ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"请分别输入账号和密码： ";
		cin>>_ID;
		cin>>_password;
		f=Query_ID(users,_ID,_password);	//以账号+密码方式查询
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"请分别输入用户名和密码： ";
		cin>>_name;
		cin>>_password;	
		f=Query_Name(users,_name,_password);	//以用户名+密码方式查询
	}
	else 
	{
		cout<<endl<<"您输入数据非法！"<<endl;
		return ;
	}
	if(f)	cout<<endl<<"谢谢使用！"<<endl;
	else 
	{
		cout<<endl<<"未找到相应的用户信息或者您输入的数据不匹配！"<<endl;
	}
}

void Revise()	//修改
{
	vector<bankUser> users;	//存放全部用户信息
	int m;	//功能选择变量
	bool f;	//标记变量
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//从文件中读取所有用户信息
	infile.close();
	cout<<endl<<"请选择修改方式：1、账号+密码  2、用户名+密码"<<endl;
	cout<<"请输入： ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"请分别输入账号和密码： ";
		cin>>_ID;
		cin>>_password;
		f=Revise_ID(users,_ID,_password);	//以账号+密码方式修改
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"请分别输入用户名和密码： ";
		cin>>_name;
		cin>>_password;	
		f=Revise_Name(users,_name,_password);	//以用户名+密码方式修改
	}
	else 
	{
		cout<<endl<<"您输入数据非法！"<<endl;
		return ;
	}
	if(f)	
	{
		cout<<endl<<"修改成功！"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//将users中的用户信息按照账号升序存入文件
		outfile.close();
	}
	else 
	{
		cout<<endl<<"未找到相应的用户信息或者您输入的数据不匹配！"<<endl;
	}
}

void SeekInfile(ifstream &infile,bankUser vec)	//从文件中获取一个用户信息
{
	string str;	
	unsigned long long int x;
	infile>>str;	//获取多余信息（文件中非纯用户信息）
	infile>>x;		vec.setID(x);		//获取用户账号
	infile>>str;	vec.setName(str);		//获取用户姓名
	infile>>str;	vec.setSex(str);		//获取用户性别
	infile>>str;	vec.setBalance(str);	//获取用户余额
	infile>>str;	vec.setID_number(str);	//获取用户身份证号码
	infile>>str;	vec.setCompany(str);	//获取用户单位
	infile>>x;		vec.setTelphone(x);		//获取用户电话号码
	infile>>str;	vec.setAddress(str);	//获取用户家庭住址
	infile>>str;	vec.setPassword(str);	//获取用户密码
}

void SeekInfile(ifstream &infile,vector<bankUser> &users)	//从文件中读取所有用户信息存储于数组users
{
	while(!infile.eof())
	{   
		bankUser vec;	//中间变量
		//SeekInfile(infile,vec);	//获取一个用户信息

		string str;	
		unsigned long long int x;
		infile>>str;	//获取多余信息（文件中非纯用户信息）
		infile>>x;		vec.setID(x);		//获取用户账号
		infile>>str;	vec.setName(str);		//获取用户姓名
		infile>>str;	vec.setSex(str);		//获取用户性别
		infile>>str;	vec.setBalance(str);	//获取用户余额
		infile>>str;	vec.setID_number(str);	//获取用户身份证号码
		infile>>str;	vec.setCompany(str);	//获取用户单位
		infile>>x;		vec.setTelphone(x);		//获取用户电话号码
		infile>>str;	vec.setAddress(str);	//获取用户家庭住址
		infile>>str;	vec.setPassword(str);	//获取用户密码

		users.push_back(vec);	//将vec存入users
	}
}

void ExportOutfile(ofstream &outfile,vector<bankUser> &users)	//将users中的用户信息存入文件中
{
	long length;	//计数变量
	length=users.size();	//获取users的长度
	for(int i=0;i<length;i++)
	{
		unsigned long long int x;
		string *p;
		bool f=false;	//标记变量
		if(i!=0 && !f) outfile<<'\n';
		if(users[i].getID()==0)
		{
			f=true;
			continue;
		}
		if(f==false) outfile<<i+1<<" ";
		else if(f==true) outfile<<i<<" ";
		x=users[i].getID();		outfile<<x<<" ";
		p=users[i].getName();	outfile<<*p<<" ";
		p=users[i].getSex();	outfile<<*p<<" ";
		p=users[i].getBalance();	outfile<<*p<<" ";
		p=users[i].getID_number();	outfile<<*p<<" ";
		p=users[i].getCompany();	outfile<<*p<<" ";
		outfile<<users[i].getTelphone()<<" ";
		p=users[i].getAddress();	outfile<<*p<<" ";
		p=users[i].getPassword();	outfile<<*p;
	}
}

void ExportOutfile(ofstream &outfile,vector<bankUser> &users,bankUser &vec)	//将users和vec中的用户信息按照账号升序存入文件
{
	long length;	//计数变量
	length=users.size();	//获取users的长度
	for(int i=0;i<length;i++)
	{
		string *p,str;
		bool f=false;		//标记变量
		unsigned long long x;
		if(i!=0) outfile<<'\n';
		if(f){
			outfile<<i+2<<" ";
		}
		else outfile<<i+1<<" ";
		x=users[i].getID();			outfile<<x<<" ";
		p=users[i].getName();		outfile<<*p<<" ";
		p=users[i].getSex();		outfile<<*p<<" ";
		p=users[i].getBalance();	outfile<<*p<<" ";
		p=users[i].getID_number();	outfile<<*p<<" ";
		p=users[i].getCompany();	outfile<<*p<<" ";
		outfile<<users[i].getTelphone()<<" ";
		p=users[i].getAddress();	outfile<<*p<<" ";
		p=users[i].getPassword();	outfile<<*p;
		if(users[i].getID()+1==vec.getID())
		{
			outfile<<'\n';
			outfile<<i+2<<" ";
			x=vec.getID();			outfile<<x<<" ";
			p=vec.getName();		outfile<<*p<<" ";
			p=users[i].getSex();	outfile<<*p<<" ";
			p=vec.getBalance();		outfile<<*p<<" ";
			p=vec.getID_number();	outfile<<*p<<" ";
			p=vec.getCompany();		outfile<<*p<<" ";
			outfile<<vec.getTelphone()<<" ";
			p=vec.getAddress();		outfile<<*p<<" ";
			p=vec.getPassword();	outfile<<*p;
			f=true;
		}
	 }
}
	
unsigned long long int Increase(vector<bankUser> &users,long length)	//获取一个新增账号并且与当前用户不重号
{
	unsigned long long int x;
	for(int i=0;i<length;i++)
	{
		if(i==length-1)
		{
			x=users[i].getID()+1;
			break;
		}
		else if(users[i].getID()+1!=users[i+1].getID())
		{
			x=users[i].getID()+1;
			break;
		}
	}
	return x;
}

bool VerifyID_number(string &str)		//验证用户身份证号码是否合法
{
	int length;
	bool f=true;
	length=str.size();
	if(length!=18)	f=false;
	for(int i=0;i<length-2;i++)
	{
		if(str.at(i)<'0' || str.at(i)>'9')
		{
			f=false;
			break;
		}
	}
	if((str.at(length-1)>='0' && str.at(length-1)<='9') || (str.at(length-1)>='a' && str.at(length-1)<='z'))
		f=true;
	else f=false;
	return f;
}

bool VerifyTelphone(unsigned long long int tel)	//验证用户电话号码是否合法
{
	if(tel/10000000000==0)
		return false;
	else return true;
}

bool DeleteAccount_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//以账号+密码方式销户
{
	 long length,i;
	 length=users.size();
	 for(i=0;i<length;i++)
	 {
		 if(users[i].getID()==_ID)	break;
	 }
	 if(i==length)	return false;
	 else
	 {
		 string *p;
		 p=users[i].getPassword();
		 if(*p==_password)
		 {
			 Initialize(users[i]);	//使users[i]的数据成员全为0
			 return true;
		 }
		 else return false;
	 }
}
	
bool DeleteAccount_Name(vector<bankUser> &users,string &_name,string &_password)	//以用户名+密码方式销户
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		 string *name;
		 name=users[i].getName();
		 if(*name==_name)	break;
	}
	if(i==length)	return false;
	else
	{
		string *password;
		password=users[i].getPassword();
		if(*password==_password)
		{
			Initialize(users[i]);	//使users[i]的数据成员全为0
			return true;
		}
		else return false;
	}

}

void Initialize(bankUser &vec)		//初始化对象vec，使其数据成员全为0
{
	string str="0";
	vec.setID(0);
	vec.setName(str);
	vec.setSex(str);
	vec.setBalance(str);
	vec.setID_number(str);
	vec.setCompany(str);
	vec.setTelphone(0);
	vec.setAddress(str);
	vec.setPassword(str);
}

bool Deposit_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//以账号+密码方式存款
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		if(users[i].getID()==_ID) break;
	}
	if(i==length) return false;
	else
	{
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		string money;
		cout<<endl<<"请输入存款金额（不含小数）: ";
		cin>>money;
		Deposit_AddMoney(users[i],money);		//增加用户users[i]的余额（金额以字符串形式）
		return true;
	}
}
	
bool Deposit_Name(vector<bankUser> &users,string &_name,string &_password)	//以用户名+密码方式存款
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		string *name;
		name=users[i].getName();
		if(*name==_name) break;
	}
	if(i==length) return false;
	else
	{
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		string money;
		cout<<endl<<"请输入存款金额（不含小数）: ";
		cin>>money;
		Deposit_AddMoney(users[i],money);		//增加用户users[i]的余额（金额以字符串形式）
		return true;
	}
}

bool Deposit_AddMoney(bankUser &user,string &money)	//增加用户余额（金额以字符串形式）
{
	string *balance,sum;
	balance=user.getBalance();
	sum=Additive(*balance,money);		//大数加法
	user.setBalance(sum);
	return true;
}

bool RemoveMoney_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//以账号+密码方式取款
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		if(users[i].getID()==_ID) break;
	}
	if(i==length) return false;
	else
	{
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		string money;
		cout<<endl<<"请输入取款金额（不含小数）: ";
		cin>>money;
		bool f;	//判断是否取款成功
		f=Remove_ReduceMoney(users[i],money);	//减少用户users[i]的余额（金额以字符串形式）
		if(!f)	cout<<endl<<"余额不足、、"<<endl;
		return f;
	}
}
	
bool RemoveMoney_Name(vector<bankUser> &users,string &_name,string &_password)	//以用户名+密码方式取款
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		string *name;
		name=users[i].getName();
		if(*name==_name) break;
	}
	if(i==length) return false;
	else
	{
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		string money;
		cout<<endl<<"请输入存款金额（不含小数）: ";
		cin>>money;
		bool f;	//判断是否取款成功
		f=Remove_ReduceMoney(users[i],money);	//减少用户users[i]的余额（金额以字符串形式）
		if(!f)	cout<<endl<<"余额不足、、"<<endl;
		return f;
	}
}

bool Remove_ReduceMoney(bankUser &user,string &money)	//减少用户余额（金额以字符串形式）
{
	string *balance,result;
	long length_user,length_money;
	balance=user.getBalance();
	length_user=(*balance).size();
	length_money=money.size();
	if(length_user<length_money) return false;
	else if(length_user==length_money)
	{
		for(long i=0;i<length_user;i++)
		{
			if((*balance).at(i)-money.at(i)<0) return false;
		}
	}
	result=Subtraction((*balance),money);	//大数减法
	user.setBalance(result);
	return true;
}

bool TransferAccounts_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//以账号+密码方式转账
{
	long length,i,j;
	length=users.size();
	for(i=0;i<length;i++)
	{
		if(users[i].getID()==_ID) break;
	}
	if(i==length) return false;
	else
	{
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		string money;
		unsigned long long int AimUser_ID;	//目标用户的账号
		cout<<endl<<"请输入转账账号：";
		cin>>AimUser_ID;
		for(j=0;j<length;j++)
		{
			if(users[j].getID()==AimUser_ID) break;
		}
		if(j==length) 
		{
			cout<<endl<<"不存在此账号、、"<<endl;
			return false;
		}
		cout<<endl<<"请输入存款金额（不含小数）: ";
		cin>>money;
		bool f_Add,f_Reduce;	//判断是否取款成功
		f_Reduce=Remove_ReduceMoney(users[i],money);	//减少用户users[i]的余额（金额以字符串形式）
		if(!f_Reduce)	
		{
			cout<<endl<<"余额不足、、"<<endl;
			return f_Reduce;
		}
		else
		{
			f_Add=Deposit_AddMoney(users[j],money);	//增加用户users[j]的余额（金额以字符串形式）
			return f_Add;
		}
	}
}
	
bool TransferAccounts_Name(vector<bankUser> &users,string &_name,string &_password)	//以用户名+密码方式转账
{
	long length,i,j;
	length=users.size();
	for(i=0;i<length;i++)
	{
		string *name;
		name=users[i].getName();
		if(*name==_name) break;
	}
	if(i==length) return false;
	else
	{
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		string money;
		unsigned long long int AimUser_ID;	//目标用户的账号
		cout<<endl<<"请输入转账账号：";
		cin>>AimUser_ID;
		for(j=0;j<length;j++)
		{
			if(users[j].getID()==AimUser_ID) break;
		}
		if(j==length) 
		{
			cout<<endl<<"不存在此账号、、"<<endl;
			return false;
		}
		cout<<endl<<"请输入存款金额（不含小数）: ";
		cin>>money;
		bool f_Add,f_Reduce;	//判断是否取款成功
		f_Reduce=Remove_ReduceMoney(users[i],money);	//减少用户users[i]的余额（金额以字符串形式）
		if(!f_Reduce)	
		{
			cout<<endl<<"余额不足、、"<<endl;
			return f_Reduce;
		}
		else
		{
			f_Add=Deposit_AddMoney(users[j],money);	//增加用户users[j]的余额（金额以字符串形式）
			return f_Add;
		}
	}
}

bool Query_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//以账号+密码方式查询
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		if(users[i].getID()==_ID) break;
	}
	if(i==length) return false;
	else
	{
		bool f;
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		f=Display_User(users[i]);		//输出用户信息
		return f;
	}
}

bool Query_Name(vector<bankUser> &users,string &_name,string &_password)	//以用户名+密码方式查询
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		string *name;
		name=users[i].getName();
		if(*name==_name) break;
	}
	if(i==length) return false;
	else
	{
		bool f;
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		f=Display_User(users[i]);	//输出用户信息
		return f;
	}
}

bool Display_User(bankUser &user)	//输出对象user的信息（数据）
{
	string *p;
	unsigned long long int x;
	cout<<endl<<endl;
	cout<<"此用户信息如下："<<endl;
	x=user.getID();
	cout<<"  "<<"账号："<<x<<endl;
	p=user.getName();
	cout<<"  "<<"姓名："<<*p<<endl;
	p=user.getSex();
	cout<<"  "<<"性别："<<*p<<endl;
	p=user.getBalance();
	cout<<"  "<<"余额："<<*p<<endl;
	p=user.getID_number();
	cout<<"  "<<"身份证号码："<<*p<<endl;
	p=user.getCompany();
	cout<<"  "<<"单位："<<*p<<endl;
	x=user.getTelphone();
	cout<<"  "<<"联系方式："<<x<<endl;
	p=user.getAddress();
	cout<<"  "<<"家庭住址："<<*p<<endl;
	cout<<endl<<endl;
	return true;
}

bool Revise_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//以账号+密码方式修改
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		if(users[i].getID()==_ID) break;
	}
	if(i==length) return false;
	else
	{
		bool f;
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		f=Revise_do(users[i]);		//修改实现
		return f;
	}
}

bool Revise_Name(vector<bankUser> &users,string &_name,string &_password)	//以用户名+密码方式修改
{
	long length,i;
	length=users.size();
	for(i=0;i<length;i++)
	{
		string *name;
		name=users[i].getName();
		if(*name==_name) break;
	}
	if(i==length) return false;
	else
	{
		bool f;
		string *password;
		password=users[i].getPassword();
		if(*password!=_password) return false;
		f=Revise_do(users[i]);		//修改实现
		return f;
	}
}

bool Revise_do(bankUser &user)		//修改实现
{
	int select;
	cout<<endl;
	cout<<endl<<"请选择修改的信息：1、姓名 2、性别 3、单位 4、电话号码 5、地址 6、密码 7、全部"<<endl;
	cout<<"请输入：";
	cin>>select;
	if(select==1)	//姓名
	{
		string newName;
		cout<<endl<<"请输入新姓名：";
		cin>>newName;
		user.setName(newName);
	}
	else if(select==2) //性别
	{
		string newSex;
		cout<<endl<<"请输入新性别：";
		cin>>newSex;
		user.setSex(newSex);
	}
	else if(select==3) //单位
	{
		string newCompany;
		cout<<endl<<"请输入新单位：";
		cin>>newCompany;
		user.setCompany(newCompany);
	}
	else if(select==4)	//电话号码
	{
		unsigned long long int newTelphone;
		cout<<endl<<"请输入新电话号码：";
		cin>>newTelphone;
		user.setTelphone(newTelphone);
	}
	else if(select==5)	//地址
	{
		string newAddress;
		cout<<endl<<"请输入新家庭住址：";
		cin>>newAddress;
		user.setAddress(newAddress);
	}
	else if(select==6)	//密码
	{
		string newPassword;
		cout<<endl<<"请输入新密码：";
		cin>>newPassword;
		user.setPassword(newPassword);
	}
	else if(select==7)	//全部
	{
		bankUser vec;
		vec=user;
		while(1)
		{
			string str;
			unsigned long long int x;
			bool f_Telphone=false;	//标记变量
			cout<<endl;
			cout<<"请输入您新的基本信息（姓名，性别，单位，电话号码，家庭住址,密码）："<<endl;
			cin>>str;	vec.setName(str);	//输入并存储姓名
			cin>>str;	vec.setSex(str);	//输入并存储性别
			cin>>str;	vec.setCompany(str);	//输入并存储单位
			cin>>x;		vec.setTelphone(x);	//输入并存储电话号码
			f_Telphone=VerifyTelphone(x);		//验证用户电话号码是否合法
			cin>>str;	vec.setAddress(str);	//输入并存储家庭住址
			cin>>str;	vec.setPassword(str);	//输入并存储密码
			if(vec.getName()!=NULL && vec.getID_number()!=NULL && f_Telphone)	break;
			else 
			{
				cout<<endl<<"姓名和身份证号码都不能为空！"<<endl;
				if(!f_Telphone)
					cout<<"请输入合法的电话号码！"<<endl;
				cout<<endl<<"请重新输入、、"<<endl;
			}
		}
		user=vec;
	}
	else 
	{
		cout<<endl<<"输入数据非法！"<<endl;
		return false;
	}
	return true;
}

string Additive(string num1,string num2)	//大数加法
{
	if(num1.size()<num2.size())
	{//把num1固定为位数较大的那个数，方便后面处理  
        string temp=num1;  
        num1=num2;  
        num2=temp;  
    }  
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag是进位标记  
    while(length1>0)
	{//从低位开始把对应的位相加  
        a=num1[length1-1]-'0';//获取num1当前位的数字  
        if(length2>0)//如果num2还没加完（注意，num2是位数较少的）  
            b=num2[length2-1]-'0';//获取num2当前位的数字  
        else  
            b=0;//如果num2加完了，num2对应位上就没有数来加了  
                //这时我没有break，因为虽然num2没有数字来加了，但可能还有进位需要加  
        sum=a+b+flag;//num1与num2对应位上的数字相加，再加上进位位  
        if(sum>=10)
		{//如果加起来大于于10，那就需要进位了  
            num1[length1-1]='0'+sum%10;//计算加完之后，当前位应该是多少  
            flag=1;//把进位标记置1  
        }
		else
		{  
            num1[length1-1]='0'+sum;//计算加完之后，当前位应该是多少  
            flag=0;//把进位标记置0  
        }  
        length1--;//向高位移动1位  
        length2--;//向高位移动1位  
    }  
    //如果两个数对应位都加完了，进位位是1，说明位数要增加1了  
    //比如99+1，加完之后，变成了三位数100，其实就是再在前面加一位1  
    if(1==flag)  
        num1="1"+num1;  
    return num1; 
}

string Subtraction(string num1,string num2)	//大数减法
{
	if(num1.size()<num2.size())
	{//把num1固定为位数较大的那个数，方便后面处理  
        string temp=num1;  
        num1=num2;  
        num2=temp;  
    }  
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag是进位标记  
    while(length1>0)
	{//从低位开始把对应的位相减  
        a=num1[length1-1]-'0';//获取num1当前位的数字  
        if(length2>0)//如果num2还没减完（注意，num2是位数较少的）  
            b=num2[length2-1]-'0';//获取num2当前位的数字  
        else  
            b=0;//如果num2减完了，num2对应位上就没有数来减了  
                //这时我没有break，因为虽然num2没有数字来减了，但可能还有进位需要减 
        if(a-flag-b>=0) 
		{
			sum=a-flag-b;
			flag=0;
			num1[length1-1]='0'+sum;
		}
        else 
        {
        	sum=a-flag-b+10;
        	num1[length1-1]='0'+sum;
			flag=1;
		}
        
        length1--;//向高位移动1位  
        length2--;//向高位移动1位  
    } 
	if(num1.at(0)=='0')
	{
		num2="0";
		long i=0;
		length1=num1.size();
		while(i<length1)
		{
			if(num1.at(i)!='0') break;
			i++;
		}
		if(i==length1)	num1=num2;
		else
		{
			num2=num1.substr(i,length1-i);
			num1=num2;
		}
	}
    return num1;  
}

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class bankUser
{
public:
	bankUser();      //无参构造函数
	~bankUser();	//析构函数
	void setID(unsigned long long int _ID);   //设置账号
	unsigned long long int getID();   // 获取账号
	void setName(string &_name);	//设置姓名
	string* getName();		//获取姓名
	void setSex(string &_sex);		//设置性别
	string* getSex();	//获取性别
	void setBalance(string &_balance);   //设置余额
	string* getBalance();	//获取账户余额
	void setID_number(string &_ID_number);		//设置身份证号码
	string* getID_number();			//获取身份证号码
	void setCompany(string &_company);		//设置用户工作单位（公司）
	string* getCompany();		//获取用户单位
	void setTelphone(unsigned long long int _telphone);  //设置联系方式
	unsigned long long int getTelphone();     //获取用户联系方式
	void setAddress(string &_address);		//设置家庭住址
	string* getAddress();		//获取用户家庭住址
	void setPassword(string &_password);	//设置用户密码
	string* getPassword();	//获取用户密码
private:
	unsigned long long int m_uID;   //账号（唯一）
	string m_sName;   //姓名
	string m_sSex;   //性别  
	string m_sBalance;    //余额(无上限)
	string m_sID_number;   //身份证号码
	string m_sCompany;   //单位
	unsigned long long int m_uTelphone;  //电话号码
	string m_sAddress;  //家庭住址
	string m_sPassword;		//密码
};

void MenuCout();		//输出菜单栏目函数
//void HeaderCout();		//输出表头
void CreateAccount();	//开户
void DeleteAccount();	//销户
void Deposit();		//存款
void RemoveMoney();	//取款	
void TransferAccounts();	//转账
void Query();	//查询
void Revise();	//修改

void Initialize(bankUser &vec);		//初始化对象vec，使其数据成员全为0
void SeekInfile(ifstream &infile,bankUser vec);	//从文件中获取一个用户信息
void SeekInfile(ifstream &infile,vector<bankUser> &users);	//从文件中读取所有用户信息存储于数组users
void ExportOutfile(ofstream &outfile,vector<bankUser> &users);	//将users中的用户信息存入文件中
void ExportOutfile(ofstream &outfile,vector<bankUser> &users,bankUser &vec);	//将users和vec中的用户信息按照账号升序存入文件

unsigned long long int Increase(vector<bankUser> &users,long length);	//获取一个新增账号并且与当前用户不重号
bool VerifyID_number(string &str);		//验证用户身份证号码是否合法
bool VerifyTelphone(unsigned long long int tel);	//验证用户电话号码是否合法

bool DeleteAccount_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//以账号+密码方式销户
bool DeleteAccount_Name(vector<bankUser> &users,string &_name,string &_password);	//以用户名+密码方式销户

bool Deposit_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//以账号+密码方式存款
bool Deposit_Name(vector<bankUser> &users,string &_name,string &_password);	//以用户名+密码方式存款
bool Deposit_AddMoney(bankUser &user,string &money);	//增加用户余额（金额以字符串形式）

bool RemoveMoney_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//以账号+密码方式取款
bool RemoveMoney_Name(vector<bankUser> &users,string &_name,string &_password);	//以用户名+密码方式取款
bool Remove_ReduceMoney(bankUser &user,string &money);	//减少用户余额（金额以字符串形式）

bool TransferAccounts_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//以账号+密码方式转账
bool TransferAccounts_Name(vector<bankUser> &users,string &_name,string &_password);	//以用户名+密码方式转账

bool Query_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//以账号+密码方式查询
bool Query_Name(vector<bankUser> &users,string &_name,string &_password);	//以用户名+密码方式查询
bool Display_User(bankUser &user);	//输出对象user的信息（数据）

bool Revise_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//以账号+密码方式修改
bool Revise_Name(vector<bankUser> &users,string &_name,string &_password);	//以用户名+密码方式修改
bool Revise_do(bankUser &user);		//修改实现

string Additive(string num1,string num2);	//大数加法
string Subtraction(string num1,string num2);	//大数减法
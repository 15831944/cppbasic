#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
class bankUser
{
public:
	bankUser();      //�޲ι��캯��
	~bankUser();	//��������
	void setID(unsigned long long int _ID);   //�����˺�
	unsigned long long int getID();   // ��ȡ�˺�
	void setName(string &_name);	//��������
	string* getName();		//��ȡ����
	void setSex(string &_sex);		//�����Ա�
	string* getSex();	//��ȡ�Ա�
	void setBalance(string &_balance);   //�������
	string* getBalance();	//��ȡ�˻����
	void setID_number(string &_ID_number);		//�������֤����
	string* getID_number();			//��ȡ���֤����
	void setCompany(string &_company);		//�����û�������λ����˾��
	string* getCompany();		//��ȡ�û���λ
	void setTelphone(unsigned long long int _telphone);  //������ϵ��ʽ
	unsigned long long int getTelphone();     //��ȡ�û���ϵ��ʽ
	void setAddress(string &_address);		//���ü�ͥסַ
	string* getAddress();		//��ȡ�û���ͥסַ
	void setPassword(string &_password);	//�����û�����
	string* getPassword();	//��ȡ�û�����
private:
	unsigned long long int m_uID;   //�˺ţ�Ψһ��
	string m_sName;   //����
	string m_sSex;   //�Ա�  
	string m_sBalance;    //���(������)
	string m_sID_number;   //���֤����
	string m_sCompany;   //��λ
	unsigned long long int m_uTelphone;  //�绰����
	string m_sAddress;  //��ͥסַ
	string m_sPassword;		//����
};

void MenuCout();		//����˵���Ŀ����
//void HeaderCout();		//�����ͷ
void CreateAccount();	//����
void DeleteAccount();	//����
void Deposit();		//���
void RemoveMoney();	//ȡ��	
void TransferAccounts();	//ת��
void Query();	//��ѯ
void Revise();	//�޸�

void Initialize(bankUser &vec);		//��ʼ������vec��ʹ�����ݳ�ԱȫΪ0
void SeekInfile(ifstream &infile,bankUser vec);	//���ļ��л�ȡһ���û���Ϣ
void SeekInfile(ifstream &infile,vector<bankUser> &users);	//���ļ��ж�ȡ�����û���Ϣ�洢������users
void ExportOutfile(ofstream &outfile,vector<bankUser> &users);	//��users�е��û���Ϣ�����ļ���
void ExportOutfile(ofstream &outfile,vector<bankUser> &users,bankUser &vec);	//��users��vec�е��û���Ϣ�����˺���������ļ�

unsigned long long int Increase(vector<bankUser> &users,long length);	//��ȡһ�������˺Ų����뵱ǰ�û����غ�
bool VerifyID_number(string &str);		//��֤�û����֤�����Ƿ�Ϸ�
bool VerifyTelphone(unsigned long long int tel);	//��֤�û��绰�����Ƿ�Ϸ�

bool DeleteAccount_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//���˺�+���뷽ʽ����
bool DeleteAccount_Name(vector<bankUser> &users,string &_name,string &_password);	//���û���+���뷽ʽ����

bool Deposit_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//���˺�+���뷽ʽ���
bool Deposit_Name(vector<bankUser> &users,string &_name,string &_password);	//���û���+���뷽ʽ���
bool Deposit_AddMoney(bankUser &user,string &money);	//�����û���������ַ�����ʽ��

bool RemoveMoney_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//���˺�+���뷽ʽȡ��
bool RemoveMoney_Name(vector<bankUser> &users,string &_name,string &_password);	//���û���+���뷽ʽȡ��
bool Remove_ReduceMoney(bankUser &user,string &money);	//�����û���������ַ�����ʽ��

bool TransferAccounts_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//���˺�+���뷽ʽת��
bool TransferAccounts_Name(vector<bankUser> &users,string &_name,string &_password);	//���û���+���뷽ʽת��

bool Query_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//���˺�+���뷽ʽ��ѯ
bool Query_Name(vector<bankUser> &users,string &_name,string &_password);	//���û���+���뷽ʽ��ѯ
bool Display_User(bankUser &user);	//�������user����Ϣ�����ݣ�

bool Revise_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password);	//���˺�+���뷽ʽ�޸�
bool Revise_Name(vector<bankUser> &users,string &_name,string &_password);	//���û���+���뷽ʽ�޸�
bool Revise_do(bankUser &user);		//�޸�ʵ��

string Additive(string num1,string num2);	//�����ӷ�
string Subtraction(string num1,string num2);	//��������
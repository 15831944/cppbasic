#include "bankUser.h"

//bankUser��Ա����

bankUser::bankUser()   //�޲ι��캯��
{

}

bankUser::~bankUser()	//��������
{

}

void bankUser::setID(unsigned long long int _ID)	//�����û��˺ź���
{
	m_uID=_ID;
}

unsigned long long int bankUser::getID()	//��ȡ�û��˺ź���
{
	return m_uID;
}

void bankUser::setName(string &_name)	//�����û�����
{
	m_sName=_name;
}

string* bankUser::getName()	//��ȡ�û�����
{
	return &m_sName;
}

void bankUser::setSex(string &_sex)	//�����û��Ա�
{
	m_sSex=_sex;
}

string* bankUser::getSex()	//��ȡ�û��Ա�
{
	return &m_sSex;
}

void bankUser::setBalance(string &_balance)		//�����˻����
{
	m_sBalance=_balance;
}

string* bankUser::getBalance()	//��ȡ�˻����
{
	return &m_sBalance;
}

void bankUser::setID_number(string &_ID_number)		//�����û����֤����
{
	m_sID_number=_ID_number;
}

string* bankUser::getID_number()	//��ȡ�û����֤����
{
	return &m_sID_number;
}

void bankUser::setCompany(string &_company)		//�����û�������λ
{
	m_sCompany=_company;
}

string* bankUser::getCompany()		//��ȡ�û�������λ
{
	return &m_sCompany;
}

void bankUser::setTelphone(unsigned long long int _telphone)	//�����û���ϵ��ʽ
{
	m_uTelphone=_telphone;	
}

unsigned long long int bankUser::getTelphone()		//��ȡ�û���ϵ��ʽ
{
	return m_uTelphone;
}

void bankUser::setAddress(string &_address)		//�����û���ͥסַ
{
	m_sAddress=_address;
}

string* bankUser::getAddress()		//��ȡ�û���ͥסַ
{
	return &m_sAddress;
}

void bankUser::setPassword(string &_password)	//�����û�����
{
	m_sPassword=_password;
}

string* bankUser::getPassword()	//��ȡ�û�����
{
	return &m_sPassword;
}


//��ͨ����

void MenuCout()		//����˵���Ŀ����
{
	cout<<endl;
	cout<<"��������������"<<endl;
	cout<<"    1:����  2������  3�����  4:ȡ��   5:ת��  6����ѯ  7���޸���Ϣ  -1������"<<endl;
	cout<<"�����룺 ";
}

//1 1000000000 ��ϣ �� ��� 510525199404168914 ������ѧ 13008142306 �Ĵ��ɶ� 156489
void CreateAccount()	//����
{
	vector<bankUser> users;	//���ȫ���û���Ϣ
	bankUser vec;	//�м���������һ���û���Ϣ
	string str;		//�����Ϣ
	long length;	//�洢���û����ͼ�������
	unsigned long long int x,_ID;	//����û�����ĵ绰����������˺�

	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//���ļ��ж�ȡ�����û���Ϣ�����������˺ţ�
	infile.close();
	length=users.size();	//��ȡ���û���Ŀ
	_ID=Increase(users,length);	//��ȡһ�������˺�
	vec.setID(_ID);

	while(1)
	{
		bool f_ID_number=false,f_Telphone=false;	//��Ǳ���
		cout<<endl<<endl;
		cout<<"���������Ļ�����Ϣ���������Ա����֤���룬��λ���绰���룬��ͥסַ����"<<endl;
		cin>>str;	vec.setName(str);	//���벢�洢����
		cin>>str;	vec.setSex(str);	//���벢�洢�Ա�
		str="0";	vec.setBalance(str);	//Ĭ�����Ϊ0
		cin>>str;	vec.setID_number(str);	//���벢�洢���֤����
		f_ID_number=VerifyID_number(str);		//��֤�û����֤�����Ƿ�Ϸ�
		cin>>str;	vec.setCompany(str);	//���벢�洢��λ
		cin>>x;		vec.setTelphone(x);	//���벢�洢�绰����
		f_Telphone=VerifyTelphone(x);		//��֤�û��绰�����Ƿ�Ϸ�
		cin>>str;	vec.setAddress(str);	//���벢�洢��ͥסַ
		if(vec.getName()!=NULL && vec.getID_number()!=NULL && f_ID_number && f_Telphone)	break;
		else {
			cout<<endl<<"���������֤���붼����Ϊ�գ�"<<endl;
			if(!f_ID_number && !f_Telphone)
				cout<<"������Ϸ������֤����͵绰���룡"<<endl;
			cout<<"���������롢��"<<endl;
		}
	}
	cout<<"�������������룺";
	cin>>str;	vec.setPassword(str);	//��׼���벢�洢�û�����
	cout<<"�����˺ųɹ����˺�Ϊ��"<<_ID<<endl;
	cout<<"ллʹ�ã�"<<endl;
	ofstream outfile("d:\\bankUser.txt");
	ExportOutfile(outfile,users,vec);	//��users��vec�е��û���Ϣ�����˺���������ļ�
	outfile.close();
}

void DeleteAccount()	//����
{
	vector<bankUser> users;	//���ȫ���û���Ϣ
	int m;	//����ѡ�����
	bool f;		//��Ǳ����������ж��Ƿ������ɹ���
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//���ļ��ж�ȡ�����û���Ϣ�����������˺ţ�
	infile.close();
	cout<<endl<<"��ѡ��������ʽ��1���˺�+����  2���û���+����"<<endl;
	cout<<"�����룺 ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"��ֱ������˺ź����룺 ";
		cin>>_ID;
		cin>>_password;
		f=DeleteAccount_ID(users,_ID,_password);		//���˺���������
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"��ֱ������û��������룺 ";
		cin>>_name;
		cin>>_password;
		f=DeleteAccount_Name(users,_name,_password);		//���û���+���뷽ʽ����
	}
	else 
	{
		cout<<endl<<"���������ݷǷ���"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"�����ɹ���"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//��users��vec�е��û���Ϣ�����˺���������ļ�
		outfile.close();
	}
	else 
	{
		cout<<endl<<"����ʧ�ܣ�δ�ҵ���Ӧ���û���Ϣ��������������ݲ�ƥ�䣡"<<endl;
	}
}

void Deposit()		//���
{
	vector<bankUser> users;	//���ȫ���û���Ϣ
	int m;	//����ѡ�����
	bool f;		//��Ǳ����������ж��Ƿ���ɹ���
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//���ļ��ж�ȡ�����û���Ϣ�����������˺ţ�
	infile.close();
	cout<<endl<<"��ѡ���ʽ��1���˺�+����  2���û���+����"<<endl;
	cout<<"�����룺 ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"��ֱ������˺ź����룺 ";
		cin>>_ID;
		cin>>_password;
		f=Deposit_ID(users,_ID,_password);	//���˺�+���뷽ʽ���
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"��ֱ������û��������룺 ";
		cin>>_name;
		cin>>_password;
		f=Deposit_Name(users,_name,_password);		//���û���+���뷽ʽ���
	}
	else 
	{
		cout<<endl<<"���������ݷǷ���"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"���ɹ���"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//��users��vec�е��û���Ϣ�����˺���������ļ�
		outfile.close();
	}
	else 
	{
		cout<<endl<<"δ�ҵ���Ӧ���û���Ϣ��������������ݲ�ƥ�䣡"<<endl;
	}
}

void RemoveMoney()	//ȡ��	
{
	vector<bankUser> users;	//���ȫ���û���Ϣ
	int m;	//����ѡ�����
	bool f;		//��Ǳ����������ж��Ƿ�ȡ��ɹ���
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//���ļ��ж�ȡ�����û���Ϣ�����������˺ţ�
	infile.close();
	cout<<endl<<"��ѡ��ȡ�ʽ��1���˺�+����  2���û���+����"<<endl;
	cout<<"�����룺 ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"��ֱ������˺ź����룺 ";
		cin>>_ID;
		cin>>_password;
		f=RemoveMoney_ID(users,_ID,_password);	//���˺�+���뷽ʽȡ��
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"��ֱ������û��������룺 ";
		cin>>_name;
		cin>>_password;
		f=RemoveMoney_Name(users,_name,_password);	//���û���+���뷽ʽȡ��
	}
	else 
	{
		cout<<endl<<"���������ݷǷ���"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"ȡ��ɹ���"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//��users��vec�е��û���Ϣ�����˺���������ļ�
		outfile.close();
	}
	else 
	{
		cout<<endl<<"δ�ҵ���Ӧ���û���Ϣ��������������ݲ�ƥ�䣡"<<endl;
	}
}

void TransferAccounts()	//ת��
{
	vector<bankUser> users;	//���ȫ���û���Ϣ
	int m;	//����ѡ�����
	bool f;		//��Ǳ����������ж��Ƿ�ת�˳ɹ���
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//���ļ��ж�ȡ�����û���Ϣ�����������˺ţ�
	infile.close();
	cout<<endl<<"��ѡ��ת�˷�ʽ��1���˺�+����  2���û���+����"<<endl;
	cout<<"�����룺 ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"��ֱ������˺ź����룺 ";
		cin>>_ID;
		cin>>_password;
		f=TransferAccounts_ID(users,_ID,_password);	//���˺�+���뷽ʽת��
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"��ֱ������û��������룺 ";
		cin>>_name;
		cin>>_password;	
		f=TransferAccounts_Name(users,_name,_password);	//���û���+���뷽ʽת��
	}
	else 
	{
		cout<<endl<<"���������ݷǷ���"<<endl;
		return ;
	}

	if(f)
	{
		cout<<endl<<"ת�˳ɹ���"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//��users��vec�е��û���Ϣ�����˺���������ļ�
		outfile.close();
	}
	else 
	{
		cout<<endl<<"δ�ҵ���Ӧ���û���Ϣ��������������ݲ�ƥ�䣡"<<endl;
	}
}

void Query()	//��ѯ
{
	vector<bankUser> users;	//���ȫ���û���Ϣ
	int m;	//����ѡ�����
	bool f;	//��Ǳ���
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//���ļ��ж�ȡ�����û���Ϣ
	infile.close();
	cout<<endl<<"��ѡ���ѯ��ʽ��1���˺�+����  2���û���+����"<<endl;
	cout<<"�����룺 ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"��ֱ������˺ź����룺 ";
		cin>>_ID;
		cin>>_password;
		f=Query_ID(users,_ID,_password);	//���˺�+���뷽ʽ��ѯ
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"��ֱ������û��������룺 ";
		cin>>_name;
		cin>>_password;	
		f=Query_Name(users,_name,_password);	//���û���+���뷽ʽ��ѯ
	}
	else 
	{
		cout<<endl<<"���������ݷǷ���"<<endl;
		return ;
	}
	if(f)	cout<<endl<<"ллʹ�ã�"<<endl;
	else 
	{
		cout<<endl<<"δ�ҵ���Ӧ���û���Ϣ��������������ݲ�ƥ�䣡"<<endl;
	}
}

void Revise()	//�޸�
{
	vector<bankUser> users;	//���ȫ���û���Ϣ
	int m;	//����ѡ�����
	bool f;	//��Ǳ���
	ifstream infile;
	infile.open("d:\\bankUser.txt");
	SeekInfile(infile,users);	//���ļ��ж�ȡ�����û���Ϣ
	infile.close();
	cout<<endl<<"��ѡ���޸ķ�ʽ��1���˺�+����  2���û���+����"<<endl;
	cout<<"�����룺 ";
	cin>>m;
	if(m==1)
	{
		unsigned long long int _ID;
		string _password;
		cout<<endl<<"��ֱ������˺ź����룺 ";
		cin>>_ID;
		cin>>_password;
		f=Revise_ID(users,_ID,_password);	//���˺�+���뷽ʽ�޸�
	}
	else if(m==2)
	{
		string _name,_password;
		cout<<endl<<"��ֱ������û��������룺 ";
		cin>>_name;
		cin>>_password;	
		f=Revise_Name(users,_name,_password);	//���û���+���뷽ʽ�޸�
	}
	else 
	{
		cout<<endl<<"���������ݷǷ���"<<endl;
		return ;
	}
	if(f)	
	{
		cout<<endl<<"�޸ĳɹ���"<<endl;
		ofstream outfile("d:\\bankUser.txt");
		ExportOutfile(outfile,users);	//��users�е��û���Ϣ�����˺���������ļ�
		outfile.close();
	}
	else 
	{
		cout<<endl<<"δ�ҵ���Ӧ���û���Ϣ��������������ݲ�ƥ�䣡"<<endl;
	}
}

void SeekInfile(ifstream &infile,bankUser vec)	//���ļ��л�ȡһ���û���Ϣ
{
	string str;	
	unsigned long long int x;
	infile>>str;	//��ȡ������Ϣ���ļ��зǴ��û���Ϣ��
	infile>>x;		vec.setID(x);		//��ȡ�û��˺�
	infile>>str;	vec.setName(str);		//��ȡ�û�����
	infile>>str;	vec.setSex(str);		//��ȡ�û��Ա�
	infile>>str;	vec.setBalance(str);	//��ȡ�û����
	infile>>str;	vec.setID_number(str);	//��ȡ�û����֤����
	infile>>str;	vec.setCompany(str);	//��ȡ�û���λ
	infile>>x;		vec.setTelphone(x);		//��ȡ�û��绰����
	infile>>str;	vec.setAddress(str);	//��ȡ�û���ͥסַ
	infile>>str;	vec.setPassword(str);	//��ȡ�û�����
}

void SeekInfile(ifstream &infile,vector<bankUser> &users)	//���ļ��ж�ȡ�����û���Ϣ�洢������users
{
	while(!infile.eof())
	{   
		bankUser vec;	//�м����
		//SeekInfile(infile,vec);	//��ȡһ���û���Ϣ

		string str;	
		unsigned long long int x;
		infile>>str;	//��ȡ������Ϣ���ļ��зǴ��û���Ϣ��
		infile>>x;		vec.setID(x);		//��ȡ�û��˺�
		infile>>str;	vec.setName(str);		//��ȡ�û�����
		infile>>str;	vec.setSex(str);		//��ȡ�û��Ա�
		infile>>str;	vec.setBalance(str);	//��ȡ�û����
		infile>>str;	vec.setID_number(str);	//��ȡ�û����֤����
		infile>>str;	vec.setCompany(str);	//��ȡ�û���λ
		infile>>x;		vec.setTelphone(x);		//��ȡ�û��绰����
		infile>>str;	vec.setAddress(str);	//��ȡ�û���ͥסַ
		infile>>str;	vec.setPassword(str);	//��ȡ�û�����

		users.push_back(vec);	//��vec����users
	}
}

void ExportOutfile(ofstream &outfile,vector<bankUser> &users)	//��users�е��û���Ϣ�����ļ���
{
	long length;	//��������
	length=users.size();	//��ȡusers�ĳ���
	for(int i=0;i<length;i++)
	{
		unsigned long long int x;
		string *p;
		bool f=false;	//��Ǳ���
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

void ExportOutfile(ofstream &outfile,vector<bankUser> &users,bankUser &vec)	//��users��vec�е��û���Ϣ�����˺���������ļ�
{
	long length;	//��������
	length=users.size();	//��ȡusers�ĳ���
	for(int i=0;i<length;i++)
	{
		string *p,str;
		bool f=false;		//��Ǳ���
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
	
unsigned long long int Increase(vector<bankUser> &users,long length)	//��ȡһ�������˺Ų����뵱ǰ�û����غ�
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

bool VerifyID_number(string &str)		//��֤�û����֤�����Ƿ�Ϸ�
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

bool VerifyTelphone(unsigned long long int tel)	//��֤�û��绰�����Ƿ�Ϸ�
{
	if(tel/10000000000==0)
		return false;
	else return true;
}

bool DeleteAccount_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//���˺�+���뷽ʽ����
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
			 Initialize(users[i]);	//ʹusers[i]�����ݳ�ԱȫΪ0
			 return true;
		 }
		 else return false;
	 }
}
	
bool DeleteAccount_Name(vector<bankUser> &users,string &_name,string &_password)	//���û���+���뷽ʽ����
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
			Initialize(users[i]);	//ʹusers[i]�����ݳ�ԱȫΪ0
			return true;
		}
		else return false;
	}

}

void Initialize(bankUser &vec)		//��ʼ������vec��ʹ�����ݳ�ԱȫΪ0
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

bool Deposit_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//���˺�+���뷽ʽ���
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
		cout<<endl<<"�������������С����: ";
		cin>>money;
		Deposit_AddMoney(users[i],money);		//�����û�users[i]����������ַ�����ʽ��
		return true;
	}
}
	
bool Deposit_Name(vector<bankUser> &users,string &_name,string &_password)	//���û���+���뷽ʽ���
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
		cout<<endl<<"�������������С����: ";
		cin>>money;
		Deposit_AddMoney(users[i],money);		//�����û�users[i]����������ַ�����ʽ��
		return true;
	}
}

bool Deposit_AddMoney(bankUser &user,string &money)	//�����û���������ַ�����ʽ��
{
	string *balance,sum;
	balance=user.getBalance();
	sum=Additive(*balance,money);		//�����ӷ�
	user.setBalance(sum);
	return true;
}

bool RemoveMoney_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//���˺�+���뷽ʽȡ��
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
		cout<<endl<<"������ȡ�������С����: ";
		cin>>money;
		bool f;	//�ж��Ƿ�ȡ��ɹ�
		f=Remove_ReduceMoney(users[i],money);	//�����û�users[i]����������ַ�����ʽ��
		if(!f)	cout<<endl<<"���㡢��"<<endl;
		return f;
	}
}
	
bool RemoveMoney_Name(vector<bankUser> &users,string &_name,string &_password)	//���û���+���뷽ʽȡ��
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
		cout<<endl<<"�������������С����: ";
		cin>>money;
		bool f;	//�ж��Ƿ�ȡ��ɹ�
		f=Remove_ReduceMoney(users[i],money);	//�����û�users[i]����������ַ�����ʽ��
		if(!f)	cout<<endl<<"���㡢��"<<endl;
		return f;
	}
}

bool Remove_ReduceMoney(bankUser &user,string &money)	//�����û���������ַ�����ʽ��
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
	result=Subtraction((*balance),money);	//��������
	user.setBalance(result);
	return true;
}

bool TransferAccounts_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//���˺�+���뷽ʽת��
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
		unsigned long long int AimUser_ID;	//Ŀ���û����˺�
		cout<<endl<<"������ת���˺ţ�";
		cin>>AimUser_ID;
		for(j=0;j<length;j++)
		{
			if(users[j].getID()==AimUser_ID) break;
		}
		if(j==length) 
		{
			cout<<endl<<"�����ڴ��˺š���"<<endl;
			return false;
		}
		cout<<endl<<"�������������С����: ";
		cin>>money;
		bool f_Add,f_Reduce;	//�ж��Ƿ�ȡ��ɹ�
		f_Reduce=Remove_ReduceMoney(users[i],money);	//�����û�users[i]����������ַ�����ʽ��
		if(!f_Reduce)	
		{
			cout<<endl<<"���㡢��"<<endl;
			return f_Reduce;
		}
		else
		{
			f_Add=Deposit_AddMoney(users[j],money);	//�����û�users[j]����������ַ�����ʽ��
			return f_Add;
		}
	}
}
	
bool TransferAccounts_Name(vector<bankUser> &users,string &_name,string &_password)	//���û���+���뷽ʽת��
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
		unsigned long long int AimUser_ID;	//Ŀ���û����˺�
		cout<<endl<<"������ת���˺ţ�";
		cin>>AimUser_ID;
		for(j=0;j<length;j++)
		{
			if(users[j].getID()==AimUser_ID) break;
		}
		if(j==length) 
		{
			cout<<endl<<"�����ڴ��˺š���"<<endl;
			return false;
		}
		cout<<endl<<"�������������С����: ";
		cin>>money;
		bool f_Add,f_Reduce;	//�ж��Ƿ�ȡ��ɹ�
		f_Reduce=Remove_ReduceMoney(users[i],money);	//�����û�users[i]����������ַ�����ʽ��
		if(!f_Reduce)	
		{
			cout<<endl<<"���㡢��"<<endl;
			return f_Reduce;
		}
		else
		{
			f_Add=Deposit_AddMoney(users[j],money);	//�����û�users[j]����������ַ�����ʽ��
			return f_Add;
		}
	}
}

bool Query_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//���˺�+���뷽ʽ��ѯ
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
		f=Display_User(users[i]);		//����û���Ϣ
		return f;
	}
}

bool Query_Name(vector<bankUser> &users,string &_name,string &_password)	//���û���+���뷽ʽ��ѯ
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
		f=Display_User(users[i]);	//����û���Ϣ
		return f;
	}
}

bool Display_User(bankUser &user)	//�������user����Ϣ�����ݣ�
{
	string *p;
	unsigned long long int x;
	cout<<endl<<endl;
	cout<<"���û���Ϣ���£�"<<endl;
	x=user.getID();
	cout<<"  "<<"�˺ţ�"<<x<<endl;
	p=user.getName();
	cout<<"  "<<"������"<<*p<<endl;
	p=user.getSex();
	cout<<"  "<<"�Ա�"<<*p<<endl;
	p=user.getBalance();
	cout<<"  "<<"��"<<*p<<endl;
	p=user.getID_number();
	cout<<"  "<<"���֤���룺"<<*p<<endl;
	p=user.getCompany();
	cout<<"  "<<"��λ��"<<*p<<endl;
	x=user.getTelphone();
	cout<<"  "<<"��ϵ��ʽ��"<<x<<endl;
	p=user.getAddress();
	cout<<"  "<<"��ͥסַ��"<<*p<<endl;
	cout<<endl<<endl;
	return true;
}

bool Revise_ID(vector<bankUser> &users,unsigned long long int _ID,string &_password)	//���˺�+���뷽ʽ�޸�
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
		f=Revise_do(users[i]);		//�޸�ʵ��
		return f;
	}
}

bool Revise_Name(vector<bankUser> &users,string &_name,string &_password)	//���û���+���뷽ʽ�޸�
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
		f=Revise_do(users[i]);		//�޸�ʵ��
		return f;
	}
}

bool Revise_do(bankUser &user)		//�޸�ʵ��
{
	int select;
	cout<<endl;
	cout<<endl<<"��ѡ���޸ĵ���Ϣ��1������ 2���Ա� 3����λ 4���绰���� 5����ַ 6������ 7��ȫ��"<<endl;
	cout<<"�����룺";
	cin>>select;
	if(select==1)	//����
	{
		string newName;
		cout<<endl<<"��������������";
		cin>>newName;
		user.setName(newName);
	}
	else if(select==2) //�Ա�
	{
		string newSex;
		cout<<endl<<"���������Ա�";
		cin>>newSex;
		user.setSex(newSex);
	}
	else if(select==3) //��λ
	{
		string newCompany;
		cout<<endl<<"�������µ�λ��";
		cin>>newCompany;
		user.setCompany(newCompany);
	}
	else if(select==4)	//�绰����
	{
		unsigned long long int newTelphone;
		cout<<endl<<"�������µ绰���룺";
		cin>>newTelphone;
		user.setTelphone(newTelphone);
	}
	else if(select==5)	//��ַ
	{
		string newAddress;
		cout<<endl<<"�������¼�ͥסַ��";
		cin>>newAddress;
		user.setAddress(newAddress);
	}
	else if(select==6)	//����
	{
		string newPassword;
		cout<<endl<<"�����������룺";
		cin>>newPassword;
		user.setPassword(newPassword);
	}
	else if(select==7)	//ȫ��
	{
		bankUser vec;
		vec=user;
		while(1)
		{
			string str;
			unsigned long long int x;
			bool f_Telphone=false;	//��Ǳ���
			cout<<endl;
			cout<<"���������µĻ�����Ϣ���������Ա𣬵�λ���绰���룬��ͥסַ,���룩��"<<endl;
			cin>>str;	vec.setName(str);	//���벢�洢����
			cin>>str;	vec.setSex(str);	//���벢�洢�Ա�
			cin>>str;	vec.setCompany(str);	//���벢�洢��λ
			cin>>x;		vec.setTelphone(x);	//���벢�洢�绰����
			f_Telphone=VerifyTelphone(x);		//��֤�û��绰�����Ƿ�Ϸ�
			cin>>str;	vec.setAddress(str);	//���벢�洢��ͥסַ
			cin>>str;	vec.setPassword(str);	//���벢�洢����
			if(vec.getName()!=NULL && vec.getID_number()!=NULL && f_Telphone)	break;
			else 
			{
				cout<<endl<<"���������֤���붼����Ϊ�գ�"<<endl;
				if(!f_Telphone)
					cout<<"������Ϸ��ĵ绰���룡"<<endl;
				cout<<endl<<"���������롢��"<<endl;
			}
		}
		user=vec;
	}
	else 
	{
		cout<<endl<<"�������ݷǷ���"<<endl;
		return false;
	}
	return true;
}

string Additive(string num1,string num2)	//�����ӷ�
{
	if(num1.size()<num2.size())
	{//��num1�̶�Ϊλ���ϴ���Ǹ�����������洦��  
        string temp=num1;  
        num1=num2;  
        num2=temp;  
    }  
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag�ǽ�λ���  
    while(length1>0)
	{//�ӵ�λ��ʼ�Ѷ�Ӧ��λ���  
        a=num1[length1-1]-'0';//��ȡnum1��ǰλ������  
        if(length2>0)//���num2��û���꣨ע�⣬num2��λ�����ٵģ�  
            b=num2[length2-1]-'0';//��ȡnum2��ǰλ������  
        else  
            b=0;//���num2�����ˣ�num2��Ӧλ�Ͼ�û����������  
                //��ʱ��û��break����Ϊ��Ȼnum2û�����������ˣ������ܻ��н�λ��Ҫ��  
        sum=a+b+flag;//num1��num2��Ӧλ�ϵ�������ӣ��ټ��Ͻ�λλ  
        if(sum>=10)
		{//���������������10���Ǿ���Ҫ��λ��  
            num1[length1-1]='0'+sum%10;//�������֮�󣬵�ǰλӦ���Ƕ���  
            flag=1;//�ѽ�λ�����1  
        }
		else
		{  
            num1[length1-1]='0'+sum;//�������֮�󣬵�ǰλӦ���Ƕ���  
            flag=0;//�ѽ�λ�����0  
        }  
        length1--;//���λ�ƶ�1λ  
        length2--;//���λ�ƶ�1λ  
    }  
    //�����������Ӧλ�������ˣ���λλ��1��˵��λ��Ҫ����1��  
    //����99+1������֮�󣬱������λ��100����ʵ��������ǰ���һλ1  
    if(1==flag)  
        num1="1"+num1;  
    return num1; 
}

string Subtraction(string num1,string num2)	//��������
{
	if(num1.size()<num2.size())
	{//��num1�̶�Ϊλ���ϴ���Ǹ�����������洦��  
        string temp=num1;  
        num1=num2;  
        num2=temp;  
    }  
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag�ǽ�λ���  
    while(length1>0)
	{//�ӵ�λ��ʼ�Ѷ�Ӧ��λ���  
        a=num1[length1-1]-'0';//��ȡnum1��ǰλ������  
        if(length2>0)//���num2��û���꣨ע�⣬num2��λ�����ٵģ�  
            b=num2[length2-1]-'0';//��ȡnum2��ǰλ������  
        else  
            b=0;//���num2�����ˣ�num2��Ӧλ�Ͼ�û����������  
                //��ʱ��û��break����Ϊ��Ȼnum2û�����������ˣ������ܻ��н�λ��Ҫ�� 
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
        
        length1--;//���λ�ƶ�1λ  
        length2--;//���λ�ƶ�1λ  
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

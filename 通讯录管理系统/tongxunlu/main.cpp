/*
�������ƣ�ͨѶ¼������������
˵����ͨѶ¼���ٰ��������������������ַ���绰���ʱ࣬E-mail�ȡ�
Ҫ��
1��ͨѶ¼�༭����ӡ�ɾ������
2������ͬ������в��ң�
3�����Ѵ��ڵ�ͨѶ¼����ͬ��������
4����ͨѶ¼д���ļ���
5�����ļ�����ͨѶ¼��
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

struct people{
	string name;  //����
	char sex;   //�Ա�    1�����У�0����Ů
	string location;  //��ַ
	unsigned long long int telphone;  //�绰����
	long postcode;   //�ʱ�
	string e_mail;   //E_mail
	//people * next;   //ָ����һ���ڵ��ָ��
	/*����ʹ���������洢��ϵ����Ϣ������Ŀʹ�ò���������vector*/ 
};

void function_1(void);   //����ͨѶ¼���
void function_2(void);   //ɾ��ͨѶ¼���
void function_3(void);   //����ͨѶ¼���
void function_4(void);   //����ȫ����ϵ�˺���
void import(people &m,ifstream &infile);   //���ļ�����һ��������ݺ���
void output(people &m,ofstream &outfile);  //���ļ�д��һ��������ݺ���
void new_people(people &m);    //��ʼ���ṹ�������ʹ�����Ϊ0
void c_out(people &m);   //��׼����ṹ���������
void c_out_head(void);   //��׼���ͨѶ¼��ͷ
void vec_sort(vector<people> &vec_1);   //�Խṹ������vec_1���յ绰��������(����)���绰����Ψһ��

int main()    //ͨѶ¼�������
{
	int x;   //����ѡ�����
	loop:
	{
		cout<<"��������������"<<endl;
		cout<<"1:����ͨѶ¼��  2:ɾ��ͨѶ¼��  3:������ϵ��  4:�鿴ȫ����ϵ�� -1:���� "<<endl;
		cin>>x;
		if(x==1)   //����ͨѶ¼��(���غ�ֱ�����ļ�ĩβ������ݣ�
		{    
			function_1();
			cout<<endl;
			goto loop;
		}
		else if(x==2)   //ɾ��ͨѶ¼��(����ȡ�ļ����������ݣ����ĺ�������д��ȫ�����ݣ�
		{
			function_2();
			cout<<endl;
			goto loop;
		}
		else if(x==3)   //����ͨѶ¼
		{
			function_3();
			cout<<endl;
			goto loop;
		}
		else if(x==4)   //�鿴ȫ����ϵ��
		{
			function_4();
			cout<<endl;
			goto loop;
		}
		else if(x==-1)
		{
			//system("pause");
			return 0;
		}
		else 
		{
			cout<<"����������Ч!"<<endl;
			cout<<endl;
			goto loop;
		}
	}
	return 0;
}

void function_1(void)   //����ͨѶ¼���                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
{
	vector<people> vec;   //���ȫ����ϵ����Ϣ
	people m;    //����һ���ṹ��������ڽ���ͨѶ¼����
	int i;   //�������� 
	ifstream infile("d:\\tongxunlu.txt");  //���ļ�
	if(infile==0)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		return ;
	}
	while(!infile.eof())   //���ļ��е�����ϵ����Ϣ��vec��
	{
		new_people(m);
		import(m,infile);
		vec.push_back(m);
	}
	infile.close();
	
	ofstream outfile("d:\\tongxunlu.txt",ios::app);
	if(outfile==0)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		return ;
	}
	cout<<"��������˳��������ϵ����Ϣ����ȱʧ��Ϣ������0���棩���������Ա�1���У�0��Ů������ַ���绰���ʱ࣬E_mail"<<endl;
	//��׼������ϵ����Ϣ
	cin>>m.name;
	cin>>m.sex;
	cin>>m.location;
	cin>>m.telphone;
	cin>>m.postcode;
	cin>>m.e_mail;

	for(i=0;i<vec.size();i++)   //�ж��Ƿ������ӵĵ绰�������ϵ�� 
	{
		if(m.telphone==vec.at(i).telphone)
			break;
	}
	if(i==vec.size() || vec.size()==0)
	{
		output(m,outfile);
		cout<<"�����ϵ�˳ɹ���"<<endl;
		return ;
	}
	else 
	{
		cout<<"�Ѵ��ڴ˵绰�������ϵ��"<<endl; 
		c_out_head();
		c_out(vec.at(i));
		system("pause");
		return ;
	}
	outfile.close();
}

void function_2(void)   //ɾ��ͨѶ¼���
{
	vector<people> vec;
	long len;  //��ϵ������
	people m;  //�ṹ����������ڽ�����ϵ����Ϣ
	unsigned long long int phone;  //���ڽ����û�ɾ������ϵ�˵ĵ绰����
	int i;   //��������
	ifstream infile("d:\\tongxunlu.txt");
	if(infile==0)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		return ;
	}
	while(!infile.eof())
	{
		new_people(m);   //��ʼ��m
		import(m,infile); //infile��ʽ����һ����ϵ����Ϣ
		vec.push_back(m);  
	}
	infile.close();
	cout<<"����������ɾ������ϵ�˵ĵ绰���룡"<<endl;  //�绰����Ψһ
	cin>>phone;	
	len=vec.size();
	for(i=0;i<len;i++)
	{
		if(vec.at(i).telphone==phone)
		{
			new_people(vec.at(i));  //��մ���ϵ������
			break;
		}
	}
	if(i==len)
	{
		cout<<"ͨѶ¼�в����ڴ˺������ϵ��"<<endl;
		return ;
	}
	else
	{
		cout<<"ɾ����ϵ�˳ɹ�!"<<endl;
		ofstream outfile("d:\\tongxunlu.txt");
		if(outfile==0)
		{
			cout<<"�ļ���ʧ�ܣ�"<<endl;
			return ;
		}
		for(int j=0;j<vec.size();j++)
		{
			m=vec.at(j);
			if(m.name=="0" && m.telphone==0) continue;
			else 
			{
				output(m,outfile);
			}
		}
		outfile.close();
	}
}

void function_3(void)   //����ͨѶ¼���
{
	vector<people> vec;   //���ȫ����ϵ����Ϣ
	vector<people> vec_1;  //��Ų��ҽ����ϵ����Ϣ
	people m;    //����һ���ṹ��������ڽ���ͨѶ¼���ݻ��м���� 
	short int y;  //����ѡ��

	ifstream infile("d:\\tongxunlu.txt");  //���ļ�
	if(infile==0)
	{
		cout<<"���ļ�ʧ�ܣ�";
		return ;
	}
	while(!infile.eof())   //���ļ��е�����ϵ����Ϣ��vec��
	{
		new_people(m);
		import(m,infile);
		vec.push_back(m);
	}
	infile.close();

	loop1:
	{
		cout<<endl;
		cout<<"��������ҷ�ʽ��0:������һ��  1����������  2���Ա����  3����ַ����  4���绰�������  5���ʱ����  6��E_mail����  7:������Ϣ���� "<<endl;
		cin>>y;
		if(y==0)   //������һ��
		{
			return ;
		}
		else if(y==1)  //������������
		{
			string seek_name;  //��������������
			long len_1;   //��Ž����ϵ������
			cout<<endl<<"�������������ϵ��������";
			cin>>seek_name;
			for(int i=0;i<vec.size();i++)
			{
				if(vec.at(i).name==seek_name)
				{
					vec_1.push_back(vec.at(i));
				}
			}
			len_1=vec_1.size();
			if(len_1==0)    //�޷�������������������ϵ��
			{
				cout<<"�޴���ϵ�ˣ�"<<endl;
				return ;
			}
			else if(len_1==1)   //����Ϊ��������������������ϵ��
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else     //�ж�λ��������������������ϵ��
			{
				vec_sort(vec_1);   //�Խṹ������vec_1���յ绰��������(�绰����Ψһ)
				cout<<"����Ϊ"<<seek_name<<"����ϵ����Ϊ��"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<vec_1.size();i++)  //������ҽ�������յ绰��������
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}

		}
		else if(y==2)  //�����Ա����
		{
			char seek_sex;   //�����ҵ��Ա����
			long len_1;     //�����ϵ������
			cout<<"��������Ҫ���ҵ��Ա���:1��Ů:0����";
			cin>>seek_sex;

			for(int i=0;i<vec.size();i++)   //���ҷ����������Ա𣩵���ϵ�ˣ��������vec_1
			{
				if(vec.at(i).sex==seek_sex)
				{
					vec_1.push_back(vec.at(i));  //��������������ϵ�������vec_1������
				}
			}

			len_1=vec_1.size();
			if(len_1==0)    //�޷����������Ա𣩵���ϵ��
			{
				cout<<"���Ա�Ϊ";
				if(seek_sex=='1') cout<<"��";
				else cout<<"Ů";
				cout<<"����ϵ�ˣ�";
				system("pause");
				return ;
			}
			else if(len_1==1)   //��һλ�����������Ա𣩵���ϵ��
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //�ж�λ�����������Ա𣩵���ϵ��
			{
				vec_sort(vec_1);    //������vec_1���յ绰����������
				cout<<"�Ա�Ϊ"<<seek_sex<<"����ϵ����Ϊ"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}
		else if(y==3)  //���յ�ַ����
		{
			string seek_location;   //�����ҵĵ�ַ����
			long len_1;   //��Ž����ϵ������
			cout<<"����������Ҫ���ҵ���ϵ�˵ĵ�ַ��";
			cin>>seek_location;
			for(int i=0;i<vec.size();i++)      //���ҷ�����������ַ������ϵ�ˣ��������vec_1��
			{
				if(vec.at(i).location==seek_location)
				{
					vec_1.push_back(vec.at(i));   //��������������ϵ�������vec_1
				}
			}
			len_1=vec_1.size();
			if(len_1==0)    //�޷�����������ַ������ϵ��
			{
				cout<<"�޵�ַΪ"<<seek_location<<"����ϵ����Ϣ"<<endl;
				system("pause");
				return ; 
			}
			else if(len_1==1)   //��һλ������������ַ������ϵ��
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //�ж�λ������������ַ������ϵ��
			{
				vec_sort(vec_1);    //�Խ����ϵ�˰�������������
				cout<<"��ַΪ"<<seek_location<<"����ϵ����Ϊ��"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}
		else if(y==4)  //���յ绰�������
		{
			unsigned long long int seek_phone; //�����ҵ���ϵ�˺���
			long len_1;  //�����ϵ�˵���������˵ǰ�����Ӳ����Ѿ����ڲ��ع��ܣ��������ļ������ʱ��Ͷ�������ͬ�绰�������ϵ�ˣ�
			cout<<"����������Ҫ���ҵ���ϵ�˵ĵ绰����";
			cin>>seek_phone;
			for(int i=0;i<vec.size();i++)   //���ҷ����������绰���룩�������vec_1��
			{
				if(vec.at(i).telphone==seek_phone)
				{
					vec_1.push_back(vec.at(i));  //���绰������ͬ����ϵ�������vec_1
				}
			}
			len_1=vec_1.size();
			if(len_1==0)   //�޷�������(�绰���룩����ϵ��
			{
				cout<<"�޵绰����Ϊ"<<seek_phone<<"����ϵ����Ϣ"<<endl;
				system("pause");
				return ;
			}
			else if(len_1==1)   //��һλ��������(�绰���룩����ϵ��
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //�ж�λ��������(�绰���룩����ϵ��
			{
				cout<<"�绰����Ϊ"<<seek_phone<<"����ϵ����Ϊ��"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)   //�����ѯ���
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}

		}
		else if(y==5)  //�����ʱ����
		{
			long seek_postcode;   //��������ϵ�˵��ʱ�
			long len_1;   //��Ž����ϵ������
			cout<<"����������Ҫ���ҵ���ϵ�˵��ʱࣺ";
			cin>>seek_postcode;
			for(int i=0;i<vec.size();i++)    //���ҷ����������ʱࣩ����ϵ�˲������vec_1��
			{
				if(vec.at(i).postcode==seek_postcode)
				{
					vec_1.push_back(vec.at(i));   
				}
			}
			len_1=vec_1.size();
			if(len_1==0)   //�޷����������ʱࣩ����ϵ��
			{
				cout<<"���ʱ�wei"<<seek_postcode<<"����ϵ����Ϣ��"<<endl;
				system("pause");
				return ;
			}
			else if(len_1==1)   //ֻ��һ�������������ʱࣩ����ϵ��
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else     //�ж�������������ʱࣩ����ϵ��
			{
				vec_sort(vec_1);    //���յ绰�����vec_1������
				cout<<"�ʱ�Ϊ"<<seek_postcode<<"����ϵ����Ϊ:"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)   //��������ϵ��
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}

		else if(y==6)  //����E_mail����
		{
			string seek_email;    //��Ŵ����ҵ���ϵ��E_mail
			long len_1;     //��Ž����ϵ������
			cout<<"����������Ҫ���ҵ���ϵ�˵�E_mail:";
			cin>>seek_email;
			for(int i=0;i<vec.size();i++)   //���ҷ�������E_mail����ϵ�˲������vec_1��
			{
				if(vec.at(i).e_mail==seek_email)
				{
					vec_1.push_back(vec.at(i));
				}
			}
			len_1=vec_1.size();
			if(len_1==0)   //�޷���������E_mail)����ϵ��
			{
				cout<<"��E_mailΪ"<<seek_email<<"����ϵ����Ϣ"<<endl;
				system("pause");
				return ;
			}
			else if(len_1==1)   //ֻ��һ������������E_mail)����ϵ��
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //�ж�λ����������E_mail)����ϵ��
			{
				vec_sort(vec_1);   //�Խ����ϵ�˰��յ绰����������
				cout<<"E_mailΪ"<<seek_email<<"����ϵ����Ϊ��"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)     //��������ϵ��
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}
		else if(y==7)   //���ղ�����Ϣ����
		{
			people m;   //��ŵ�����ϵ�ˣ������м������
			long len_1;  //��ŷ�����������ϵ���� 
			cout<<"����������������ϵ�˵Ĳ�����Ϣ����������˳�����룬��δ֪����0���棺�������Ա𣬵�ַ���绰���ʱ࣬E_mail"<<endl;
			cin>>m.name;
			cin>>m.sex;
			cin>>m.location;
			cin>>m.telphone;
			cin>>m.postcode;
			cin>>m.e_mail;

			for(int i=0;i<vec.size();i++)    //���ҷ�����������ϵ�˲������vec_1��
			{
				if(m.name=="0" || m.name==vec.at(i).name)
					if(m.sex=='0' || m.sex==vec.at(i).sex)
						if(m.location=="0" || m.location==vec.at(i).location)
							if(m.telphone==0 || m.telphone==vec.at(i).telphone)
								if(m.postcode==0 || m.postcode==vec.at(i).postcode)
									if(m.e_mail=="0" || m.e_mail==vec.at(i).e_mail)
									{
										vec_1.push_back(vec.at(i)) ;    
									}
			}
			if(len_1==0)  //�޷�����������ϵ��
			{
				cout<<"�޷�����������ϵ�ˣ�"<<endl;
				system("pause");
				return ;
			} 
			else if(len_1==1)  //��һλ������������ϵ��
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			} 
			else     //�ж�λ������������ϵ��
			{
				vec_sort(vec_1);     //�Խ����ϵ�˰��յ绰����������
				cout<<"������������ϵ����Ϊ��"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++) //��������ϵ�� 
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ; 
			 } 

		}
		else   
		{
			cout<<"����������Ч��"<<endl;
			goto loop1; 
		}
	}		
}

void function_4(void)   //����ȫ����ϵ�˺���
{
	vector<people> vec;   //�����ϵ��
	people m;  //��ŵ�����ϵ����Ϣ
	ifstream infile("d:\\tongxunlu.txt");
	if(infile==0)
	{
		cout<<"���ļ�ʧ�ܣ�";
		return ;
	}
	while(!infile.eof())
	{
		new_people(m);
		import(m,infile);
		vec.push_back(m);
	}
	infile.close();
	c_out_head();   //��׼���ͨѶ¼��ͷ
	for(int i=0;i<vec.size();i++)
	{
		c_out(vec.at(i));  //��׼���ÿһ����ϵ����Ϣ
	}
	cout<<"��ϣ�"<<endl;
}

void import(people &m,ifstream &infile)   //���ļ�����һ��������ݺ���
{
	infile>>m.name;
	infile>>m.sex;
	infile>>m.location;
	infile>>m.telphone;
	infile>>m.postcode;
	infile>>m.e_mail;
}

void output(people &m,ofstream &outfile)  //���ļ�д��һ��������ݺ���
{
	outfile<<'\n';
	outfile<<m.name;
	outfile<<"  ";
	outfile<<m.sex;
	outfile<<"  ";
	outfile<<m.location;
	outfile<<"  ";
	outfile<<m.telphone;
	outfile<<"  ";
	outfile<<m.postcode;
	outfile<<"  ";
	outfile<<m.e_mail;
}

void new_people(people &m)    //��ʼ���ṹ�������ʹ�����Ϊ"0"
{
	m.name="0";
	m.sex='0';
	m.location="0";
	m.telphone=0;
	m.postcode=0;
	m.e_mail="0";
}

void c_out(people &m)   //��׼����ṹ���������
{
	cout<<setiosflags(ios::left);
	cout<<setw(8)<<m.name;
	if(m.sex=='1') cout<<setw(5)<<"��";
	else cout<<setw(5)<<"Ů";
	cout<<setw(15)<<m.location;
	cout<<setw(13)<<m.telphone;
	cout<<setw(9)<<m.postcode;
	cout<<setw(20)<<m.e_mail;
	cout<<endl;
}

void c_out_head(void)   //��׼���ͨѶ¼��ͷ
{
	cout<<endl;
	cout<<setiosflags(ios::left);
	cout<<endl;
	cout<<setw(8)<<"����";
	cout<<setw(5)<<"�Ա�";
	cout<<setw(15)<<"��ַ";
	cout<<setw(13)<<"�绰����";
	cout<<setw(9)<<"�ʱ�";
	cout<<setw(20)<<"E_mail";
	cout<<endl;
}

void vec_sort(vector<people> &vec_1)   //�Խṹ������vec���յ绰��������
{
	people m;    //�ṹ����������м����
	unsigned long long int phone_min;   //��Ž�С�ĵ绰����ֵ 
	//long len;    //���vec�Ĺ�ģ��С
	for(long i=0;i<vec_1.size();i++)
	{
		phone_min=vec_1.at(i).telphone;
		long j,min=i;
		for(j=i+1;j<vec_1.size();j++)
		{
			if(vec_1.at(j).telphone<phone_min)
				min=j;
		}
		if(min!=i)
		{
			m=vec_1.at(i);
			vec_1.at(i)=vec_1.at(min);
			vec_1.at(min)=m;
		}
	}
}

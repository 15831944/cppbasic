/*
课题名称：通讯录管理软件的设计
说明：通讯录至少包括以下数据项：姓名，地址，电话，邮编，E-mail等。
要求：
1）通讯录编辑（添加、删除）；
2）按不同的项进行查找；
3）对已存在的通讯录按不同的项排序；
4）将通讯录写入文件；
5）从文件读入通讯录。
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

struct people{
	string name;  //姓名
	char sex;   //性别    1代表男，0代表女
	string location;  //地址
	unsigned long long int telphone;  //电话号码
	long postcode;   //邮编
	string e_mail;   //E_mail
	//people * next;   //指向下一个节点的指针
	/*可以使用链表来存储联系人信息，本项目使用不定长数组vector*/ 
};

void function_1(void);   //增加通讯录项函数
void function_2(void);   //删除通讯录项函数
void function_3(void);   //查找通讯录项函数
void function_4(void);   //查找全部联系人函数
void import(people &m,ifstream &infile);   //从文件读入一个结点数据函数
void output(people &m,ofstream &outfile);  //向文件写入一个结点数据函数
void new_people(people &m);    //初始化结构体变量，使各项均为0
void c_out(people &m);   //标准输出结构体变量数据
void c_out_head(void);   //标准输出通讯录表头
void vec_sort(vector<people> &vec_1);   //对结构体数组vec_1按照电话号码排序(升序)（电话号码唯一）

int main()    //通讯录管理软件
{
	int x;   //功能选择变量
	loop:
	{
		cout<<"请输入您的需求："<<endl;
		cout<<"1:增加通讯录项  2:删除通讯录项  3:查找联系人  4:查看全部联系人 -1:结束 "<<endl;
		cin>>x;
		if(x==1)   //增加通讯录项(查重后直接在文件末尾添加数据）
		{    
			function_1();
			cout<<endl;
			goto loop;
		}
		else if(x==2)   //删除通讯录项(先提取文件中所有数据，更改后再重新写入全部数据）
		{
			function_2();
			cout<<endl;
			goto loop;
		}
		else if(x==3)   //查找通讯录
		{
			function_3();
			cout<<endl;
			goto loop;
		}
		else if(x==4)   //查看全部联系人
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
			cout<<"输入数据无效!"<<endl;
			cout<<endl;
			goto loop;
		}
	}
	return 0;
}

void function_1(void)   //增加通讯录项函数                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
{
	vector<people> vec;   //存放全部联系人信息
	people m;    //创建一个结构体变量用于接收通讯录数据
	int i;   //计数变量 
	ifstream infile("d:\\tongxunlu.txt");  //打开文件
	if(infile==0)
	{
		cout<<"打开文件失败！"<<endl;
		return ;
	}
	while(!infile.eof())   //从文件中导出联系人信息到vec中
	{
		new_people(m);
		import(m,infile);
		vec.push_back(m);
	}
	infile.close();
	
	ofstream outfile("d:\\tongxunlu.txt",ios::app);
	if(outfile==0)
	{
		cout<<"打开文件失败！"<<endl;
		return ;
	}
	cout<<"请您按照顺序输入联系人信息（如缺失信息，请以0代替）：姓名，性别（1：男，0：女），地址，电话，邮编，E_mail"<<endl;
	//标准输入联系人信息
	cin>>m.name;
	cin>>m.sex;
	cin>>m.location;
	cin>>m.telphone;
	cin>>m.postcode;
	cin>>m.e_mail;

	for(i=0;i<vec.size();i++)   //判断是否存在添加的电话号码的联系人 
	{
		if(m.telphone==vec.at(i).telphone)
			break;
	}
	if(i==vec.size() || vec.size()==0)
	{
		output(m,outfile);
		cout<<"添加联系人成功！"<<endl;
		return ;
	}
	else 
	{
		cout<<"已存在此电话号码的联系人"<<endl; 
		c_out_head();
		c_out(vec.at(i));
		system("pause");
		return ;
	}
	outfile.close();
}

void function_2(void)   //删除通讯录项函数
{
	vector<people> vec;
	long len;  //联系人总数
	people m;  //结构体变量，用于接收联系人信息
	unsigned long long int phone;  //用于接收用户删除的联系人的电话号码
	int i;   //计数变量
	ifstream infile("d:\\tongxunlu.txt");
	if(infile==0)
	{
		cout<<"打开文件失败！"<<endl;
		return ;
	}
	while(!infile.eof())
	{
		new_people(m);   //初始化m
		import(m,infile); //infile方式读入一个联系人信息
		vec.push_back(m);  
	}
	infile.close();
	cout<<"请输入您欲删除的联系人的电话号码！"<<endl;  //电话号码唯一
	cin>>phone;	
	len=vec.size();
	for(i=0;i<len;i++)
	{
		if(vec.at(i).telphone==phone)
		{
			new_people(vec.at(i));  //清空此联系人数据
			break;
		}
	}
	if(i==len)
	{
		cout<<"通讯录中不存在此号码的联系人"<<endl;
		return ;
	}
	else
	{
		cout<<"删除联系人成功!"<<endl;
		ofstream outfile("d:\\tongxunlu.txt");
		if(outfile==0)
		{
			cout<<"文件打开失败！"<<endl;
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

void function_3(void)   //查找通讯录项函数
{
	vector<people> vec;   //存放全部联系人信息
	vector<people> vec_1;  //存放查找结果联系人信息
	people m;    //创建一个结构体变量用于接收通讯录数据或中间变量 
	short int y;  //功能选择

	ifstream infile("d:\\tongxunlu.txt");  //打开文件
	if(infile==0)
	{
		cout<<"打开文件失败！";
		return ;
	}
	while(!infile.eof())   //从文件中导出联系人信息到vec中
	{
		new_people(m);
		import(m,infile);
		vec.push_back(m);
	}
	infile.close();

	loop1:
	{
		cout<<endl;
		cout<<"请输入查找方式：0:返回上一层  1：姓名查找  2：性别查找  3：地址查找  4：电话号码查找  5：邮编查找  6：E_mail查找  7:部分信息查找 "<<endl;
		cin>>y;
		if(y==0)   //返回上一层
		{
			return ;
		}
		else if(y==1)  //按照姓名查找
		{
			string seek_name;  //待查找姓名变量
			long len_1;   //存放结果联系人总数
			cout<<endl<<"请输入待查找联系人姓名：";
			cin>>seek_name;
			for(int i=0;i<vec.size();i++)
			{
				if(vec.at(i).name==seek_name)
				{
					vec_1.push_back(vec.at(i));
				}
			}
			len_1=vec_1.size();
			if(len_1==0)    //无符合条件（姓名）的联系人
			{
				cout<<"无此联系人！"<<endl;
				return ;
			}
			else if(len_1==1)   //有以为符合条件（姓名）的联系人
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else     //有多位符合条件（姓名）的联系人
			{
				vec_sort(vec_1);   //对结构体数组vec_1按照电话号码排序(电话号码唯一)
				cout<<"姓名为"<<seek_name<<"的联系人数为："<<len_1<<endl;
				c_out_head();
				for(int i=0;i<vec_1.size();i++)  //输出查找结果（按照电话号码升序）
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}

		}
		else if(y==2)  //按照性别查找
		{
			char seek_sex;   //待查找的性别变量
			long len_1;     //结果联系人总数
			cout<<"请输入您要查找的性别（男:1或女:0）：";
			cin>>seek_sex;

			for(int i=0;i<vec.size();i++)   //查找符合条件（性别）的联系人，并添加至vec_1
			{
				if(vec.at(i).sex==seek_sex)
				{
					vec_1.push_back(vec.at(i));  //将符合条件的联系人添加至vec_1数组中
				}
			}

			len_1=vec_1.size();
			if(len_1==0)    //无符合条件（性别）的联系人
			{
				cout<<"无性别为";
				if(seek_sex=='1') cout<<"男";
				else cout<<"女";
				cout<<"的联系人！";
				system("pause");
				return ;
			}
			else if(len_1==1)   //有一位符合条件（性别）的联系人
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //有多位符合条件（性别）的联系人
			{
				vec_sort(vec_1);    //对数组vec_1按照电话号码排升序
				cout<<"性别为"<<seek_sex<<"的联系人数为"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}
		else if(y==3)  //按照地址查找
		{
			string seek_location;   //待查找的地址变量
			long len_1;   //存放结果联系人总数
			cout<<"请输入您需要查找的联系人的地址：";
			cin>>seek_location;
			for(int i=0;i<vec.size();i++)      //查找符合条件（地址）的联系人，并添加至vec_1中
			{
				if(vec.at(i).location==seek_location)
				{
					vec_1.push_back(vec.at(i));   //将符合条件的联系人添加至vec_1
				}
			}
			len_1=vec_1.size();
			if(len_1==0)    //无符合条件（地址）的联系人
			{
				cout<<"无地址为"<<seek_location<<"的联系人信息"<<endl;
				system("pause");
				return ; 
			}
			else if(len_1==1)   //有一位符合条件（地址）的联系人
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //有多位符合条件（地址）的联系人
			{
				vec_sort(vec_1);    //对结果联系人按照姓名排升序
				cout<<"地址为"<<seek_location<<"的联系人数为："<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}
		else if(y==4)  //按照电话号码查找
		{
			unsigned long long int seek_phone; //待查找的联系人号码
			long len_1;  //结果联系人的总数（虽说前面的添加操作已经存在查重功能，难免在文件读入的时候就读入有相同电话号码的联系人）
			cout<<"请输入您需要查找的联系人的电话号码";
			cin>>seek_phone;
			for(int i=0;i<vec.size();i++)   //查找符合条件（电话号码）并添加至vec_1中
			{
				if(vec.at(i).telphone==seek_phone)
				{
					vec_1.push_back(vec.at(i));  //将电话号码相同的联系人添加至vec_1
				}
			}
			len_1=vec_1.size();
			if(len_1==0)   //无符合条件(电话号码）的联系人
			{
				cout<<"无电话号码为"<<seek_phone<<"的联系人信息"<<endl;
				system("pause");
				return ;
			}
			else if(len_1==1)   //有一位符合条件(电话号码）的联系人
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //有多位符合条件(电话号码）的联系人
			{
				cout<<"电话号码为"<<seek_phone<<"的联系人数为："<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)   //输出查询结果
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}

		}
		else if(y==5)  //按照邮编查找
		{
			long seek_postcode;   //待查找联系人的邮编
			long len_1;   //存放结果联系人总数
			cout<<"请输入您需要查找的联系人的邮编：";
			cin>>seek_postcode;
			for(int i=0;i<vec.size();i++)    //查找符合条件（邮编）的联系人并添加至vec_1中
			{
				if(vec.at(i).postcode==seek_postcode)
				{
					vec_1.push_back(vec.at(i));   
				}
			}
			len_1=vec_1.size();
			if(len_1==0)   //无符合条件（邮编）的联系人
			{
				cout<<"无邮编wei"<<seek_postcode<<"的联系人信息！"<<endl;
				system("pause");
				return ;
			}
			else if(len_1==1)   //只有一个符合条件（邮编）的联系人
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else     //有多个符合条件（邮编）的联系人
			{
				vec_sort(vec_1);    //按照电话号码对vec_1排升序
				cout<<"邮编为"<<seek_postcode<<"的联系人数为:"<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)   //输出结果联系人
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}

		else if(y==6)  //按照E_mail查找
		{
			string seek_email;    //存放待查找的联系人E_mail
			long len_1;     //存放结果联系人总数
			cout<<"请输入您需要查找的联系人的E_mail:";
			cin>>seek_email;
			for(int i=0;i<vec.size();i++)   //查找符合条件E_mail的联系人并添加至vec_1中
			{
				if(vec.at(i).e_mail==seek_email)
				{
					vec_1.push_back(vec.at(i));
				}
			}
			len_1=vec_1.size();
			if(len_1==0)   //无符合条件（E_mail)的联系人
			{
				cout<<"无E_mail为"<<seek_email<<"的联系人信息"<<endl;
				system("pause");
				return ;
			}
			else if(len_1==1)   //只有一个符合条件（E_mail)的联系人
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			}
			else    //有多位符合条件（E_mail)的联系人
			{
				vec_sort(vec_1);   //对结果联系人按照电话号码排升序
				cout<<"E_mail为"<<seek_email<<"的联系人数为："<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++)     //输出结果联系人
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ;
			}
		}
		else if(y==7)   //按照部分信息查找
		{
			people m;   //存放单个联系人（用作中间变量）
			long len_1;  //存放符合条件的联系人数 
			cout<<"请输入您待查找联系人的部分信息（按照以下顺序输入，若未知则用0代替：姓名，性别，地址，电话，邮编，E_mail"<<endl;
			cin>>m.name;
			cin>>m.sex;
			cin>>m.location;
			cin>>m.telphone;
			cin>>m.postcode;
			cin>>m.e_mail;

			for(int i=0;i<vec.size();i++)    //查找符合条件的联系人并添加至vec_1中
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
			if(len_1==0)  //无符合条件的联系人
			{
				cout<<"无符合条件的联系人！"<<endl;
				system("pause");
				return ;
			} 
			else if(len_1==1)  //有一位符合条件的联系人
			{
				c_out_head();
				c_out(vec_1.at(0));
				system("pause");
				return ;
			} 
			else     //有多位符合条件的联系人
			{
				vec_sort(vec_1);     //对结果联系人按照电话号码排升序
				cout<<"符合条件的联系人数为："<<len_1<<endl;
				c_out_head();
				for(int i=0;i<len_1;i++) //输出结果联系人 
				{
					c_out(vec_1.at(i));
				}
				system("pause");
				return ; 
			 } 

		}
		else   
		{
			cout<<"输入数据无效！"<<endl;
			goto loop1; 
		}
	}		
}

void function_4(void)   //查找全部联系人函数
{
	vector<people> vec;   //存放联系人
	people m;  //存放单个联系人信息
	ifstream infile("d:\\tongxunlu.txt");
	if(infile==0)
	{
		cout<<"打开文件失败！";
		return ;
	}
	while(!infile.eof())
	{
		new_people(m);
		import(m,infile);
		vec.push_back(m);
	}
	infile.close();
	c_out_head();   //标准输出通讯录表头
	for(int i=0;i<vec.size();i++)
	{
		c_out(vec.at(i));  //标准输出每一个联系人信息
	}
	cout<<"完毕！"<<endl;
}

void import(people &m,ifstream &infile)   //从文件读入一个结点数据函数
{
	infile>>m.name;
	infile>>m.sex;
	infile>>m.location;
	infile>>m.telphone;
	infile>>m.postcode;
	infile>>m.e_mail;
}

void output(people &m,ofstream &outfile)  //向文件写入一个结点数据函数
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

void new_people(people &m)    //初始化结构体变量，使各项均为"0"
{
	m.name="0";
	m.sex='0';
	m.location="0";
	m.telphone=0;
	m.postcode=0;
	m.e_mail="0";
}

void c_out(people &m)   //标准输出结构体变量数据
{
	cout<<setiosflags(ios::left);
	cout<<setw(8)<<m.name;
	if(m.sex=='1') cout<<setw(5)<<"男";
	else cout<<setw(5)<<"女";
	cout<<setw(15)<<m.location;
	cout<<setw(13)<<m.telphone;
	cout<<setw(9)<<m.postcode;
	cout<<setw(20)<<m.e_mail;
	cout<<endl;
}

void c_out_head(void)   //标准输出通讯录表头
{
	cout<<endl;
	cout<<setiosflags(ios::left);
	cout<<endl;
	cout<<setw(8)<<"姓名";
	cout<<setw(5)<<"性别";
	cout<<setw(15)<<"地址";
	cout<<setw(13)<<"电话号码";
	cout<<setw(9)<<"邮编";
	cout<<setw(20)<<"E_mail";
	cout<<endl;
}

void vec_sort(vector<people> &vec_1)   //对结构体数组vec按照电话号码排序
{
	people m;    //结构体变量用作中间变量
	unsigned long long int phone_min;   //存放较小的电话号码值 
	//long len;    //存放vec的规模大小
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

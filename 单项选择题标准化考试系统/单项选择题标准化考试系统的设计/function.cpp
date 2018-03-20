#include "class.h"
#include <iostream>
#include <string>
using namespace std;

void Project::setM_problem(string problem)
{	//���ã��޸ģ���Ŀ
	m_problem=problem;
}

void Project::setM_candidate(string candidate,int i)
{	//���ã��޸ģ���ѡ��
	if(i==0)
		m_candidateA=candidate;
	else if(i==1)
		m_candidateB=candidate;
	else if(i==2)
		m_candidateC=candidate;
	else if(i==3)
		m_candidateD=candidate;
}

void Project::setM_answer(string answer)
{//���ã��޸ģ���׼��
	m_answer=answer;
}

void Project::setM_option(char option)
{//���ã��޸ģ���׼�𰸵�ѡ��
	m_option=option;
}

void Project::display()
{//��ӡ��Ŀ
	cout<<m_problem<<endl;
	cout<<"  "<<m_candidateA<<endl;
	cout<<"  "<<m_candidateB<<endl;
	cout<<"  "<<m_candidateC<<endl;
	cout<<"  "<<m_candidateD<<endl;
}

void Project::display(int option)
{//��ӡ��׼�𰸺ʹ�ѡ��
	cout<<"����ı�׼��Ϊ:"<<m_option<<"��"<<m_answer<<endl;
}

char Project::getM_option()
{	//���m_option
	return m_option;
}

void welcome()
{	//�����ӭ��
	cout<<"**-----------------------------------------------------**\n"<<endl;
	cout<<"            ��ӭʹ�õ���ѡ�����׼������ϵͳ\n"<<endl;
	cout<<"| ����˵�� |\n"<<endl;
	cout<<"    ������ѡ�����׼������ϵͳ��Ϊ�����Ѷȼ�����Ŀ����"<<endl;
	cout<<"������������ȡ��ÿ��5�֣����ֱַ�Ϊ50��100��150�֡���"<<endl;
	cout<<"�ύÿһ����Ŀ��ϵͳ���Զ��о���������Ӧ�ı�׼�𰸡�\n"<<endl;
	cout<<"    Ԥף�����Գɹ���\n"<<endl;
	cout<<"**-----------------------------------------------------**\n"<<endl;
}

void import_file(vector<Project> & project,ifstream &infile)
{//���ļ��ж���������Ŀ��project
	while(!infile.eof())
	{
		Project temp;
		string str;
		infile>>str;
		temp.setM_problem(str);
		for(int j=0;j<4;j++){
			infile>>str;
			temp.setM_candidate(str,j);
		}
		infile>>str;
		temp.setM_answer(str);
		char ch;
		infile>>ch;
		temp.setM_option(ch);
		project.push_back(temp);
	}
}


bool judge(vector<Project> & project,int serialNumber[],int i,char answerOption)
{	//�жϴ�
	char ch=project[serialNumber[i]].getM_option();
	if(ch==answerOption)
		return true;
	return false;
}


#include "class.h"
#include <iostream>
#include <string>
using namespace std;

void Project::setM_problem(string problem)
{	//设置（修改）题目
	m_problem=problem;
}

void Project::setM_candidate(string candidate,int i)
{	//设置（修改）候选答案
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
{//设置（修改）标准答案
	m_answer=answer;
}

void Project::setM_option(char option)
{//设置（修改）标准答案的选项
	m_option=option;
}

void Project::display()
{//打印题目
	cout<<m_problem<<endl;
	cout<<"  "<<m_candidateA<<endl;
	cout<<"  "<<m_candidateB<<endl;
	cout<<"  "<<m_candidateC<<endl;
	cout<<"  "<<m_candidateD<<endl;
}

void Project::display(int option)
{//打印标准答案和答案选项
	cout<<"本题的标准答案为:"<<m_option<<"、"<<m_answer<<endl;
}

char Project::getM_option()
{	//获得m_option
	return m_option;
}

void welcome()
{	//输出欢迎词
	cout<<"**-----------------------------------------------------**\n"<<endl;
	cout<<"            欢迎使用单项选择题标准化考试系统\n"<<endl;
	cout<<"| 考试说明 |\n"<<endl;
	cout<<"    本单项选择题标准化考试系统分为三个难度级别，题目均来"<<endl;
	cout<<"自题库中随机抽取，每题5分，满分分别为50、100、150分。在"<<endl;
	cout<<"提交每一道题目后，系统会自动判卷，并给出相应的标准答案。\n"<<endl;
	cout<<"    预祝您考试成功！\n"<<endl;
	cout<<"**-----------------------------------------------------**\n"<<endl;
}

void import_file(vector<Project> & project,ifstream &infile)
{//从文件中读入所有题目到project
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
{	//判断答案
	char ch=project[serialNumber[i]].getM_option();
	if(ch==answerOption)
		return true;
	return false;
}


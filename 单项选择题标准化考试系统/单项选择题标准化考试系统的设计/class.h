#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;
class Project
{
public:
	//Project();		//构造函数
	//~Project();		//析构函数
	void setM_problem(string problem);		//设置（修改）题目
	void setM_candidate(string candidate,int i);		//设置（修改）候选答案
	void setM_answer(string answer);		//设置（修改）标准答案
	void setM_option(char option);		//设置（修改）标准答案的选项
	void display();		//打印题目
	void display(int option);		//打印标准答案和答案选项
	char getM_option();		//获得m_option
private:
	string m_problem;			//题目
	string m_candidateA;		//四个候选答案
	string m_candidateB;
	string m_candidateC;
	string m_candidateD;
	string m_answer;		//标准答案
	char m_option;			//标准答案的答案选项
};

void welcome();		//输出欢迎词
void import_file(vector<Project> & project,ifstream &infile);		//从文件中读入所有题目到project
bool judge(vector<Project> & project,int serialNumber[],int i,char answerOption);		//判断答案
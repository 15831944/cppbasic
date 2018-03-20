#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;
class Project
{
public:
	//Project();		//���캯��
	//~Project();		//��������
	void setM_problem(string problem);		//���ã��޸ģ���Ŀ
	void setM_candidate(string candidate,int i);		//���ã��޸ģ���ѡ��
	void setM_answer(string answer);		//���ã��޸ģ���׼��
	void setM_option(char option);		//���ã��޸ģ���׼�𰸵�ѡ��
	void display();		//��ӡ��Ŀ
	void display(int option);		//��ӡ��׼�𰸺ʹ�ѡ��
	char getM_option();		//���m_option
private:
	string m_problem;			//��Ŀ
	string m_candidateA;		//�ĸ���ѡ��
	string m_candidateB;
	string m_candidateC;
	string m_candidateD;
	string m_answer;		//��׼��
	char m_option;			//��׼�𰸵Ĵ�ѡ��
};

void welcome();		//�����ӭ��
void import_file(vector<Project> & project,ifstream &infile);		//���ļ��ж���������Ŀ��project
bool judge(vector<Project> & project,int serialNumber[],int i,char answerOption);		//�жϴ�
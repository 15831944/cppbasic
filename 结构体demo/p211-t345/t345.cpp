#include <iostream>
using namespace std;
struct student 
	{
		float num[5];
		char name[5][20];
		int score[5][4];
	};
student st1;
int main ()
{
	void input(student st1);
	void print(student st1);
	int i,j,max;
	input(st1);
	for(i=0;i<5;i++)
		st1.score[i][3]=(st1.score[i][0]+st1.score[i][1]+st1.score[i][2])/3;
	max=st1.score[0][3];
	cout<<endl<<endl;
	print(st1);
	cout<<endl<<endl;
	for(i=0;i<5;i++)
		if(st1.score[i][3]>max) 
		{max=st1.score[i][3];j=i;}
	cout<<"最高分学生的数据："<<endl;
	cout<<"学号："<<st1.num[j]<<endl;
	cout<<"姓名："<<st1.name[j]<<endl;
	cout<<"分数："<<st1.score[j][0]<<"  "<<st1.score[j][1]<<"  "<<st1.score[j][2]<<endl;
	cout<<"平均分数："<<st1.score[j][3]<<endl;
	return 0;
}
void input(student st1)
{
	int i,j;
	cout<<"请依次输入五个学生的学号："<<endl;
	for(i=0;i<5;i++)
		cin>>st1.num[i];
	cout<<"请依次输入五个学生的姓名："<<endl;
	for(i=0;i<5;i++)
		cin>>st1.name[i];
	cout<<"请依次输入五个学生的三门成绩："<<endl;
	for(i=0;i<5;i++)
		for(j=0;j<3;j++)
			cin>>st1.score[i][j];
}
void print(student st1)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		cout<<"第"<<i<<"个学生的信息如下："<<endl;
		cout<<"学号："<<st1.num[i]<<endl;
		cout<<"姓名："<<st1.name[i]<<endl;
		cout<<"三门成绩："<<st1.score[i][0]<<st1.score[i][1]<<st1.score[i][2]<<endl;
		cout<<"平均成绩"<<st1.score[i][3]<<endl;
	}
}




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
	cout<<"��߷�ѧ�������ݣ�"<<endl;
	cout<<"ѧ�ţ�"<<st1.num[j]<<endl;
	cout<<"������"<<st1.name[j]<<endl;
	cout<<"������"<<st1.score[j][0]<<"  "<<st1.score[j][1]<<"  "<<st1.score[j][2]<<endl;
	cout<<"ƽ��������"<<st1.score[j][3]<<endl;
	return 0;
}
void input(student st1)
{
	int i,j;
	cout<<"�������������ѧ����ѧ�ţ�"<<endl;
	for(i=0;i<5;i++)
		cin>>st1.num[i];
	cout<<"�������������ѧ����������"<<endl;
	for(i=0;i<5;i++)
		cin>>st1.name[i];
	cout<<"�������������ѧ�������ųɼ���"<<endl;
	for(i=0;i<5;i++)
		for(j=0;j<3;j++)
			cin>>st1.score[i][j];
}
void print(student st1)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		cout<<"��"<<i<<"��ѧ������Ϣ���£�"<<endl;
		cout<<"ѧ�ţ�"<<st1.num[i]<<endl;
		cout<<"������"<<st1.name[i]<<endl;
		cout<<"���ųɼ���"<<st1.score[i][0]<<st1.score[i][1]<<st1.score[i][2]<<endl;
		cout<<"ƽ���ɼ�"<<st1.score[i][3]<<endl;
	}
}




#include <iostream>
using namespace std;
struct Student{
	int num;
	string name;
	int score[3];
};
int main ()
{
	void Print(Student stu[],int length);
	Student stu[5];
	cout<<"����������5λѧ����ѧ�ţ����������ſγɼ���"<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>stu[i].num;
		cin>>stu[i].name;
		for(int j=0;j<3;j++)
			cin>>stu[i].score[j];
	}
	cout<<"ѧ����Ϣ���£�"<<endl;
	Print(stu,3);
	return 0;
}
void Print(Student stu[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<stu[i].num<<"  ";
		cout<<stu[i].name<<"  ";
		for(int j=0;j<3;j++)
			cout<<stu[i].score[j]<<" ";
	}
}


#include "class.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	vector<Project> allProject;
	ifstream infile("E:\\project.txt");
	import_file(allProject,infile);		//���ļ��ж������е���Ŀ��allProject
	infile.close();
	welcome();
	int n,num,score=0;		//num:��Ŀ����
loop:
{
	cout<<"�����뿼���Ѷȣ�1����    2��һ��   3������   0���˳�����\n"<<endl;
	cout<<"����ѡ���ǣ� ";
	cin>>n;
	if(n==1) num=10;
	else if(n==2) num=10;		//��������������������ġ�10��
	else if(n==3) num=10;		//��������������������ġ�10��
	else if(n==0) return 0;
	else goto loop;
}
	
	//����α�����������������������ȡ
	int serialNumber[35],i=0;
	srand(time(NULL));
	serialNumber[0]=rand()%10;			//��������������������ġ�10��
	while(1)
	{
		int m=rand()%10,j;		//��������������������ġ�10��
		for(j=0;j<i;j++)
		{
			if(m==serialNumber[j]) break;
		}
		if(i==j)
		{
			serialNumber[i]=m;
			i++;
		}
		if(i==num) break;
	}

	for(i=0;i<num;i++){
		cout<<endl;
		char answerOption;
		bool answer;
		cout<<"<"<<i+1<<">";
		allProject[serialNumber[i]].display();	//�����i����Ŀ
		cout<<"���������Ĵ𰸣�";
		cin>>answerOption;
		answer=judge(allProject,serialNumber,i,answerOption);		//�жϴ�
		cout<<endl;
		if(answer) {
			score+=5;
			cout<<"����ȷ��"<<endl;
		}
		else {
			cout<<"���ź������Ĵ𰸴���"<<endl;
			allProject.at(serialNumber[i]).display(i);		//�����i����Ŀ�Ĵ�
		}
		cout<<"Ŀǰ������"<<score<<endl;
		cout<<endl;
	}
	cout<<endl;
	cout<<"��ɴ��"<<endl;
	cout<<endl<<"�������ճɼ��ǣ�"<<score<<endl;
	if(score>=(num*5)*0.6) cout<<"�ɼ��ϸ�"<<endl;
	else cout<<"�ɼ����ϸ�"<<endl<<endl<<endl;
	return 0;
}
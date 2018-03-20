
#include "class.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	vector<Project> allProject;
	ifstream infile("E:\\project.txt");
	import_file(allProject,infile);		//从文件中读入所有的题目到allProject
	infile.close();
	welcome();
	int n,num,score=0;		//num:题目总数
loop:
{
	cout<<"请输入考试难度：1、简单    2、一般   3、困难   0、退出程序\n"<<endl;
	cout<<"您的选择是： ";
	cin>>n;
	if(n==1) num=10;
	else if(n==2) num=10;		//若增加题量，更改这里的“10”
	else if(n==3) num=10;		//若增加题量，更改这里的“10”
	else if(n==0) return 0;
	else goto loop;
}
	
	//利用伪随机数生成器在题库中随机抽取
	int serialNumber[35],i=0;
	srand(time(NULL));
	serialNumber[0]=rand()%10;			//若增加题量，更改这里的“10”
	while(1)
	{
		int m=rand()%10,j;		//若增加题量，更改这里的“10”
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
		allProject[serialNumber[i]].display();	//输出第i道题目
		cout<<"请输入您的答案：";
		cin>>answerOption;
		answer=judge(allProject,serialNumber,i,answerOption);		//判断答案
		cout<<endl;
		if(answer) {
			score+=5;
			cout<<"答案正确！"<<endl;
		}
		else {
			cout<<"很遗憾，您的答案错误！"<<endl;
			allProject.at(serialNumber[i]).display(i);		//输出第i道题目的答案
		}
		cout<<"目前分数："<<score<<endl;
		cout<<endl;
	}
	cout<<endl;
	cout<<"完成答卷！"<<endl;
	cout<<endl<<"您的最终成绩是："<<score<<endl;
	if(score>=(num*5)*0.6) cout<<"成绩合格！"<<endl;
	else cout<<"成绩不合格！"<<endl<<endl<<endl;
	return 0;
}
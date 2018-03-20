#include <iostream>
#include "queue.h"
using namespace std;
int main ()
{
	Queue queue;
	int user[]={3,5,4,1,6,9};
	for(int i=0;i<6;i++)
		queue.push(user[i]);
	int temp=0;
	while(1)
	{
		temp=queue.pop();
		if(temp==-1)
			break;
		cout<<"data为 "<<temp<<" 的排号信息："<<endl;
		cout<<"    前面还有 "<<temp<<" 位用户正在等待！"<<endl;
		cout<<endl;
	}
	return 0;
}
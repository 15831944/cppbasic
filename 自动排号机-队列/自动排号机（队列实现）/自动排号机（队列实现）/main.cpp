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
		cout<<"dataΪ "<<temp<<" ���ź���Ϣ��"<<endl;
		cout<<"    ǰ�滹�� "<<temp<<" λ�û����ڵȴ���"<<endl;
		cout<<endl;
	}
	return 0;
}
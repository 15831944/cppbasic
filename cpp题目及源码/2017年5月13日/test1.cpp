#include<iostream>
#include <string>
using namespace std;
int main ()
{
	string str[101];
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>str[i];
	for(int i=0;i<N;i++)
	{
		int length,a[100],count=0;
		char b[100];
		length=str[i].size();
		for(int j=0;j<length;)
		{
			char ch=str[i].at(j);
			int f=0;
			while(1)
			{
				f++;
				if(j+f>length-1 || str[i].at(j+f)!=ch) break;
			}
			a[count]=f;
			b[count]=ch;
			count++;
			j+=f;
		}
		for(int j=0;j<count;j++)
		{
			if(a[j]!=1) cout<<a[j];
			cout<<b[j];
		}
		cout<<endl;
	}
	return 0;
 } 

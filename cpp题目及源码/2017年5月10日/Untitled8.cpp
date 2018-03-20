#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int shuzi=0,zifu=0,kongge=0,qita=0,length;
	string str;
	getline(cin,str);
	length=str.size();
	for(int i=0;i<length;i++)
	{
		if((str.at(i)>='a' && str.at(i)<='z') || (str.at(i)>='A' && str.at(i)<='Z'))
			zifu++;
		else if(str.at(i)>='0' && str.at(i)<='9')
			shuzi++;
		else if(str.at(i)==' ')
			kongge++;
		else qita++;
	}
	cout<<"英文字母："<<zifu<<endl;
	cout<<"数字："<<shuzi<<endl;
	cout<<"空格："<<kongge<<endl;
	cout<<"其他字符："<<qita<<endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string x;
	cin>>x;
	int length;
	length=x.size();
	cout<<length<<endl;
	for(int i=0;i<length;i++)
		cout<<x.at(i)<<" ";
	cout<<endl;
	for(int i=length-1;i>=0;i--)
		cout<<x.at(i)<<" ";
	cout<<endl;
	return 0;
}

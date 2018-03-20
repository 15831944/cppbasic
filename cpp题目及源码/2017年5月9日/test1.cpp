#include <iostream>
#include <string>
using namespace std;
int main()
{
	string text;
	cin>>text;
	int length=text.size();
	for(int i=0;i<length;i++)
		cout<<char((int(text.at(i)-'a')+i+1)%26+'a');
	return 0;
} 

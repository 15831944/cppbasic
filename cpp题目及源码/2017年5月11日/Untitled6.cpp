#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string str;
	int length;
	char arr[26]={0};
	cin>>str;
	length=str.size();
	for(int i=0;i<length;i++)
		arr[str.at(i)-'a']++;
	for(int i=0;i<26;i++)
		for(int j=0;j<arr[i];j++)
			cout<<char(i+'a'); 
	return 0;
}

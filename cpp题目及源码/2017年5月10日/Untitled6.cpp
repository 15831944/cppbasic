#include <iostream>
using namespace std;
int main ()
{
	int year,month,day,count=0;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	cin>>year>>month>>day;
	if(year<0 || month<0 || month>12 || day>31)
	{
		cout<<"数据非法";
		return 0;
	}
	if((year%4==0 && year%100==0) || year%400==0)
		a[1]=29;
	if(a[month]<day) 
	{
		cout<<"数据非法";
		return 0;
	}
	for(int i=0;i<month;i++)
		count+=a[i];
	cout<<count+day;
	return 0;
}

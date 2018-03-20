#include <iostream>
using namespace std;
int main ()
{
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31},year,month,day,sum=0;
	cin>>year>>month>>day;
	if((year%4==0 && year%100==0) || year%400==0)
		a[1]=29;
	for(int i=0;i<month;i++)
		sum+=a[i];
	if(day>a[month]) 
		cout<<"数据非法！";
	else cout<<sum+day;
	return 0;	
}

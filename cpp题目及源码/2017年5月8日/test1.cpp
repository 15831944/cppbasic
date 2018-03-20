#include <iostream>
using namespace std;
int main ()
{
	int count=0;
	for(int i=10000;i<100000;i++)
		if(i/10000==4 || (i%10000)/1000==4 || (i%1000)/100==4 || (i%100)/10==4 || i%10==4)
			continue;
		else count++;
	cout<<"½±È¯×ÜÊý£º"<<count<<endl;
	return 0;
}
	

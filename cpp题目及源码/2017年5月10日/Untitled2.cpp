#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	for(int i=100;i<1000;i++)
	{
		if(pow(i/100,3)+pow((i%100)/10,3)+pow(i%10,3)==i)
			cout<<i<<endl;
	}
	return 0;
}

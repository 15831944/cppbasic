#include <iostream>
using namespace std;
int main ()
{
	float score;
	cin>>score;
	if(score==100) cout<<"good A";
	else if(score>=85) cout<<"A";
	else if(score>=75) cout<<"B";
	else if(score>=60) cout<<"C";
	else cout<<"D";
	return 0;
}

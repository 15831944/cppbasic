#define MAXN 100
class Stack
{
public:
	Stack();
	//~Stack();
	bool push(int data);	//压栈
	int pop();		//弹栈
private:
	int m_iArr[MAXN];	
	int m_iStackTop;		//栈顶元素下标
	int m_iSize;		//栈的最大容量
};
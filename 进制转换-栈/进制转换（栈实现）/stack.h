#define MAXN 100
class Stack
{
public:
	Stack();
	//~Stack();
	bool push(int data);	//ѹջ
	int pop();		//��ջ
private:
	int m_iArr[MAXN];	
	int m_iStackTop;		//ջ��Ԫ���±�
	int m_iSize;		//ջ���������
};
#define MAXN 100
class Queue
{
public:
	Queue();
	~Queue();
	bool push(int data=0);
	int pop();
private:
	int m_iQueue[MAXN];
	int m_iHead;
	int m_iTail;
	int m_iSize;
	int m_iLength;
};
#include "queue.h"
Queue::Queue()
{
	m_iHead=m_iTail=0;
	m_iSize=MAXN;
	m_iLength=0;
}

Queue::~Queue()
{
	m_iHead=m_iTail=0;
	m_iLength=0;
}

bool Queue::push(int data)
{
	if(m_iLength>=m_iSize)
		return false;
	m_iQueue[m_iTail]=data;
	m_iTail=(m_iTail+1)%m_iSize;
	m_iLength++;
	return true;
}

int Queue::pop()
{
	if(m_iLength<=0)
		return -1;
	int temp=m_iHead;
	m_iHead=(m_iHead+1)%m_iSize;
	m_iLength--;
	return temp;
}
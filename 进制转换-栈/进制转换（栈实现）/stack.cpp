#include "stack.h"

Stack::Stack()
{
	m_iSize=MAXN;
	m_iStackTop=0;
}

//Stack::~Stack()
//{
//
//}

bool Stack::push(int data)
{
	if(m_iStackTop>=m_iSize-1){
		return false;
	}
	m_iArr[m_iStackTop]=data;
	m_iStackTop++;
	return true;
}

int Stack::pop()
{
	if(m_iStackTop<=0)
		return -1;
	m_iStackTop--;
	return m_iArr[m_iStackTop];
}
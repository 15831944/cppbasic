// TipLogPassword.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "TipLogPassword.h"
#include "afxdialogex.h"


// CTipLogPassword �Ի���

IMPLEMENT_DYNAMIC(CTipLogPassword, CDialogEx)

CTipLogPassword::CTipLogPassword(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTipLogPassword::IDD, pParent)
{

}

CTipLogPassword::~CTipLogPassword()
{
}

void CTipLogPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipLogPassword, CDialogEx)
END_MESSAGE_MAP()


// CTipLogPassword ��Ϣ�������

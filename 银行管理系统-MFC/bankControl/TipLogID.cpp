// TipLogID.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "TipLogID.h"
#include "afxdialogex.h"


// CTipLogID 对话框

IMPLEMENT_DYNAMIC(CTipLogID, CDialogEx)

CTipLogID::CTipLogID(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTipLogID::IDD, pParent)
{

}

CTipLogID::~CTipLogID()
{
}

void CTipLogID::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipLogID, CDialogEx)
END_MESSAGE_MAP()


// CTipLogID 消息处理程序

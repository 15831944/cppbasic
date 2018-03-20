// TransferSucceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "TransferSucceDlg.h"
#include "afxdialogex.h"


// TransferSucceDlg 对话框

IMPLEMENT_DYNAMIC(TransferSucceDlg, CDialogEx)

TransferSucceDlg::TransferSucceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TransferSucceDlg::IDD, pParent)
{

}

TransferSucceDlg::~TransferSucceDlg()
{
}

void TransferSucceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TransferSucceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TransferSucceDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TransferSucceDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// TransferSucceDlg 消息处理程序


void TransferSucceDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HomePage homePage;
	homePage.DoModal();
}


void TransferSucceDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

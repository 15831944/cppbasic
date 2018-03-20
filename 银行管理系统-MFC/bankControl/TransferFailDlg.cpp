// TransferFailDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "TransferFailDlg.h"
#include "afxdialogex.h"


// TransferFailDlg 对话框

IMPLEMENT_DYNAMIC(TransferFailDlg, CDialogEx)

TransferFailDlg::TransferFailDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TransferFailDlg::IDD, pParent)
{

}

TransferFailDlg::~TransferFailDlg()
{
}

void TransferFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TransferFailDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TransferFailDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TransferFailDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// TransferFailDlg 消息处理程序


void TransferFailDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HomePage homePage;
	homePage.DoModal();
}


void TransferFailDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

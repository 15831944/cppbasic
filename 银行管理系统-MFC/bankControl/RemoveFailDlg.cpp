// RemoveFailDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "RemoveFailDlg.h"
#include "afxdialogex.h"


// RemoveFailDlg 对话框

IMPLEMENT_DYNAMIC(RemoveFailDlg, CDialogEx)

RemoveFailDlg::RemoveFailDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RemoveFailDlg::IDD, pParent)
{

}

RemoveFailDlg::~RemoveFailDlg()
{
}

void RemoveFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RemoveFailDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RemoveFailDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RemoveFailDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// RemoveFailDlg 消息处理程序


void RemoveFailDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	//取款成功，返回首页
	HomePage homePageDlg;
	homePageDlg.DoModal();
}


void RemoveFailDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}

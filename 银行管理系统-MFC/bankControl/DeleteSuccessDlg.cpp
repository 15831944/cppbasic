// DeleteSuccessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "DeleteSuccessDlg.h"
#include "afxdialogex.h"


// DeleteSuccessDlg 对话框

IMPLEMENT_DYNAMIC(DeleteSuccessDlg, CDialogEx)

DeleteSuccessDlg::DeleteSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DeleteSuccessDlg::IDD, pParent)
{

}

DeleteSuccessDlg::~DeleteSuccessDlg()
{
}

void DeleteSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DeleteSuccessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// DeleteSuccessDlg 消息处理程序


void DeleteSuccessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CbankControlDlg myPage;
	myPage.DoModal();
}


void DeleteSuccessDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

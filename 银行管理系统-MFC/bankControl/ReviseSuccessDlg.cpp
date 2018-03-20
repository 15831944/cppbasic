// ReviseSuccessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "ReviseSuccessDlg.h"
#include "afxdialogex.h"


// ReviseSuccessDlg 对话框

IMPLEMENT_DYNAMIC(ReviseSuccessDlg, CDialogEx)

ReviseSuccessDlg::ReviseSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ReviseSuccessDlg::IDD, pParent)
{

}

ReviseSuccessDlg::~ReviseSuccessDlg()
{
}

void ReviseSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReviseSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ReviseSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ReviseSuccessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ReviseSuccessDlg 消息处理程序


void ReviseSuccessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HomePage homePage;
	homePage.DoModal();
}


void ReviseSuccessDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

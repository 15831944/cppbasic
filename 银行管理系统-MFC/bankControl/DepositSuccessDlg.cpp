// DepositSuccessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "DepositSuccessDlg.h"
#include "afxdialogex.h"


// DepositSuccessDlg 对话框

IMPLEMENT_DYNAMIC(DepositSuccessDlg, CDialogEx)

DepositSuccessDlg::DepositSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DepositSuccessDlg::IDD, pParent)
{

}

DepositSuccessDlg::~DepositSuccessDlg()
{
}

void DepositSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DepositSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DepositSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DepositSuccessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// DepositSuccessDlg 消息处理程序


void DepositSuccessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//存款成功，返回首页
	HomePage homePage;
	homePage.DoModal();
}


void DepositSuccessDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

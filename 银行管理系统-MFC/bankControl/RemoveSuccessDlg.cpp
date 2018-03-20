// RemoveSuccessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "RemoveSuccessDlg.h"
#include "afxdialogex.h"


// RemoveSuccessDlg 对话框

IMPLEMENT_DYNAMIC(RemoveSuccessDlg, CDialogEx)

RemoveSuccessDlg::RemoveSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RemoveSuccessDlg::IDD, pParent)
	, RemoveSuccess_Balance(0)
{

}

RemoveSuccessDlg::~RemoveSuccessDlg()
{
}

void RemoveSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RemoveSuccessBalance_Edit, RemoveSuccess_Balance);
}


BEGIN_MESSAGE_MAP(RemoveSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RemoveSuccessDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RemoveSuccessDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &RemoveSuccessDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// RemoveSuccessDlg 消息处理程序


void RemoveSuccessDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	HomePage homePage;
	homePage.DoModal();
}


void RemoveSuccessDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}


void RemoveSuccessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//显示余额
	RemoveSuccess_Balance=oneUser.m_sBalance;
	UpdateData(FALSE);
}

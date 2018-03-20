// CreateSuccessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "CreateSuccessDlg.h"
#include "afxdialogex.h"


// CreateSuccessDlg 对话框

IMPLEMENT_DYNAMIC(CreateSuccessDlg, CDialogEx)

CreateSuccessDlg::CreateSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CreateSuccessDlg::IDD, pParent)
	, _newID(0)
{

}

CreateSuccessDlg::~CreateSuccessDlg()
{
}

void CreateSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _newID);
}


BEGIN_MESSAGE_MAP(CreateSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CreateSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CreateSuccessDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CreateSuccessDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CreateSuccessDlg 消息处理程序


void CreateSuccessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//返回登陆界面
	CbankControlDlg controlDlg;
	controlDlg.DoModal();
}


void CreateSuccessDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CreateSuccessDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	_newID=oneUser.m_uID;
	UpdateData(FALSE);
}

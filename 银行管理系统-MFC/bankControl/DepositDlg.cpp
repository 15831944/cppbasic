// DepositDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "DepositDlg.h"
#include "afxdialogex.h"


// DepositDlg 对话框

IMPLEMENT_DYNAMIC(DepositDlg, CDialogEx)

DepositDlg::DepositDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DepositDlg::IDD, pParent)
	, depositMoney(0)
{

}

DepositDlg::~DepositDlg()
{
}

void DepositDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, depositMoney);
}


BEGIN_MESSAGE_MAP(DepositDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DepositDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DepositDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// DepositDlg 消息处理程序


void DepositDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	oneUser.m_sBalance+=depositMoney;
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	str.Format(_T("%d"),oneUser.m_sBalance);
	CString sql=_T("update bankUser set m_balance='")+str+_T("'where m_ID=")+str_ID;
	db.ExecuteSQL(sql);
	rs.Close();
	db.Close();
	DepositSuccessDlg depositSuccessDlg;
	depositSuccessDlg.DoModal();
}


void DepositDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//返回首页
	HomePage homePage;
	homePage.DoModal();
}

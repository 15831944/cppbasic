// DeleteDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"


// DeleteDlg 对话框

IMPLEMENT_DYNAMIC(DeleteDlg, CDialogEx)

DeleteDlg::DeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DeleteDlg::IDD, pParent)
{

}

DeleteDlg::~DeleteDlg()
{
}

void DeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DeleteDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DeleteDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// DeleteDlg 消息处理程序


void DeleteDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	CString sql=_T("delete from bankUser where m_ID=")+str_ID;
	db.ExecuteSQL(sql);
	rs.Close();
	db.Close();
	DeleteSuccessDlg myDlg;
	myDlg.DoModal();
}


void DeleteDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	HomePage myPage;
	myPage.DoModal();
}


void DeleteDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

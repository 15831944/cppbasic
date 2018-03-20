// QuerySucessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "QuerySucessDlg.h"
#include "afxdialogex.h"


// QuerySucessDlg 对话框

IMPLEMENT_DYNAMIC(QuerySucessDlg, CDialogEx)

QuerySucessDlg::QuerySucessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(QuerySucessDlg::IDD, pParent)
{

}

QuerySucessDlg::~QuerySucessDlg()
{
}

void QuerySucessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QuerySucessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &QuerySucessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &QuerySucessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// QuerySucessDlg 消息处理程序


void QuerySucessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HomePage homePage;
	homePage.DoModal();
}


void QuerySucessDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

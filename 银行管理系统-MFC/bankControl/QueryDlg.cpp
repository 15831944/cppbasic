// QueryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "QueryDlg.h"
#include "afxdialogex.h"


// QueryDlg 对话框

IMPLEMENT_DYNAMIC(QueryDlg, CDialogEx)

QueryDlg::QueryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(QueryDlg::IDD, pParent)
	, message(_T(""))
{

}

QueryDlg::~QueryDlg()
{
}

void QueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, message);
}


BEGIN_MESSAGE_MAP(QueryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &QueryDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &QueryDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &QueryDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// QueryDlg 消息处理程序


void QueryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//确定提交意见
	QuerySucessDlg querySuccessDlg;
	querySuccessDlg.DoModal();
}


void QueryDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	HomePage homePage;
	homePage.DoModal();
}


void QueryDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

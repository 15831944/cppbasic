// OnlineDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "OnlineDlg.h"
#include "afxdialogex.h"


// OnlineDlg 对话框

IMPLEMENT_DYNAMIC(OnlineDlg, CDialogEx)

OnlineDlg::OnlineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(OnlineDlg::IDD, pParent)
{

}

OnlineDlg::~OnlineDlg()
{
}

void OnlineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OnlineDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &OnlineDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &OnlineDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// OnlineDlg 消息处理程序


void OnlineDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HomePage homePage;
	homePage.DoModal();
}


void OnlineDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

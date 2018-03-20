// ReviseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "ReviseDlg.h"
#include "afxdialogex.h"


// ReviseDlg 对话框

IMPLEMENT_DYNAMIC(ReviseDlg, CDialogEx)

ReviseDlg::ReviseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ReviseDlg::IDD, pParent)
{

}

ReviseDlg::~ReviseDlg()
{
}

void ReviseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReviseDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ReviseDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ReviseDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ReviseDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &ReviseDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// ReviseDlg 消息处理程序


void ReviseDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改一般信息
	ReviseMostDlg reviseMostDlg;
	reviseMostDlg.DoModal();
}


void ReviseDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改密码
	RevisePasswordDlg rePasswordDlg;
	rePasswordDlg.DoModal();
}


void ReviseDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//返回首页
	HomePage homePage;
	homePage.DoModal();
}


void ReviseDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//退出程序
	exit(0);
}

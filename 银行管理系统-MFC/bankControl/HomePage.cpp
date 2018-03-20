// HomePage.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "HomePage.h"
#include "afxdialogex.h"


// HomePage 对话框

IMPLEMENT_DYNAMIC(HomePage, CDialogEx)

HomePage::HomePage(CWnd* pParent /*=NULL*/)
	: CDialogEx(HomePage::IDD, pParent)
{

}

HomePage::~HomePage()
{
}

void HomePage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HomePage, CDialogEx)
	ON_BN_CLICKED(IDC_Transfer_Button, &HomePage::OnBnClickedTransferButton)
	ON_BN_CLICKED(IDC_RemoveMoney_Button, &HomePage::OnBnClickedRemovemoneyButton)
	ON_BN_CLICKED(IDC_Deposit_Button, &HomePage::OnBnClickedDepositButton)
	ON_BN_CLICKED(IDC_Change_Button, &HomePage::OnBnClickedChangeButton)
	ON_BN_CLICKED(IDC_Check_Button, &HomePage::OnBnClickedCheckButton)
	ON_BN_CLICKED(IDC_Exit_Button, &HomePage::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_Online_Button, &HomePage::OnBnClickedOnlineButton)
	ON_BN_CLICKED(IDC_Delete_Button, &HomePage::OnBnClickedDeleteButton)
END_MESSAGE_MAP()


// HomePage 消息处理程序



void HomePage::OnBnClickedRemovemoneyButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//取款
	RemoveMoneyDlg removeMoneyDlg;
	removeMoneyDlg.DoModal();
}


void HomePage::OnBnClickedDepositButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//存款
	DepositDlg depositDlg;
	depositDlg.DoModal();
}

void HomePage::OnBnClickedTransferButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//转账
	TransferDlg transferDlg;
	transferDlg.DoModal();
}

void HomePage::OnBnClickedChangeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改信息
	ReviseDlg reviseDlg;
	reviseDlg.DoModal();
}


void HomePage::OnBnClickedCheckButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//查看明细
	QueryDlg queryDlg;
	queryDlg.DoModal();
}


void HomePage::OnBnClickedDeleteButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//销户
	DeleteDlg deleteDlg;
	deleteDlg.DoModal();
}


void HomePage::OnBnClickedOnlineButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//网上银行
	OnlineDlg onlineDlg;
	onlineDlg.DoModal();
}

void HomePage::OnBnClickedExitButton()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}





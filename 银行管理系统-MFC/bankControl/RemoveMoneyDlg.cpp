// RemoveMoneyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "RemoveMoneyDlg.h"
#include "afxdialogex.h"


// RemoveMoneyDlg 对话框

IMPLEMENT_DYNAMIC(RemoveMoneyDlg, CDialogEx)

RemoveMoneyDlg::RemoveMoneyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RemoveMoneyDlg::IDD, pParent)
	, accountBalance(0)
	, WithdrawalAmount(0)
{

}

RemoveMoneyDlg::~RemoveMoneyDlg()
{
}

void RemoveMoneyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Balance_Edit, accountBalance);
	DDX_Text(pDX, IDC_RemoveMoney_Edit, WithdrawalAmount);
}


BEGIN_MESSAGE_MAP(RemoveMoneyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_submit_button, &RemoveMoneyDlg::OnBnClickedsubmitbutton)
	ON_BN_CLICKED(IDC_cancel_button, &RemoveMoneyDlg::OnBnClickedcancelbutton)
	ON_BN_CLICKED(IDC_BUTTON3, &RemoveMoneyDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// RemoveMoneyDlg 消息处理程序


void RemoveMoneyDlg::OnBnClickedsubmitbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	CString sql=_T("select m_balance from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	long long m=_ttoi(str);	//将字符串转化为数值型
	oneUser.m_sBalance=m;
	rs.Close();
	db.Close();
	if(oneUser.m_sBalance>=WithdrawalAmount)
	{
		//取款成功，跳出提示页
		oneUser.m_sBalance=oneUser.m_sBalance-WithdrawalAmount;
		db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
		rs.m_pDatabase=&db;
		str.Format(_T("%d"),oneUser.m_sBalance);
		CString sql=_T("update bankUser set m_balance=")+str+_T("where m_ID=")+str_ID;
		db.ExecuteSQL(sql);
		rs.Close();
		db.Close();
		RemoveSuccessDlg myDlg;
		myDlg.DoModal();
	}
	else {
		//取款失败
		RemoveFailDlg myDlg;
		myDlg.DoModal();
	}
}


void RemoveMoneyDlg::OnBnClickedcancelbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	//返回首页
	HomePage homePageDlg;
	homePageDlg.DoModal();
}


void RemoveMoneyDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//查看余额
	//用户余额
	CDatabase db;
	CRecordset rs;
	CString str;
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	CString sql=_T("select m_balance from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	long long m=_ttoi(str);	//将字符串转化为数值型
	oneUser.m_sBalance=m;
	rs.Close();
	db.Close();
	accountBalance=oneUser.m_sBalance;
	UpdateData(FALSE);
}

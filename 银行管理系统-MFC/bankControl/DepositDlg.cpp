// DepositDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "DepositDlg.h"
#include "afxdialogex.h"


// DepositDlg �Ի���

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


// DepositDlg ��Ϣ�������


void DepositDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//������ҳ
	HomePage homePage;
	homePage.DoModal();
}

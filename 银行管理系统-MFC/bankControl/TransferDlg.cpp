// TransferDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "TransferDlg.h"
#include "afxdialogex.h"


// TransferDlg �Ի���

IMPLEMENT_DYNAMIC(TransferDlg, CDialogEx)

TransferDlg::TransferDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TransferDlg::IDD, pParent)
	, transferAccount(0)
	, transferMoney(0)
{

}

TransferDlg::~TransferDlg()
{
}

void TransferDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, transferAccount);
	DDX_Text(pDX, IDC_EDIT2, transferMoney);
}


BEGIN_MESSAGE_MAP(TransferDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TransferDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TransferDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &TransferDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// TransferDlg ��Ϣ�������


void TransferDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	CString sql=_T("select m_balance from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	int m=_ttoi(str);	//���ַ���ת��Ϊ��ֵ��
	oneUser.m_sBalance=m;
	
	rs.Close();
	db.Close();
	if(oneUser.m_sBalance>=transferMoney)
	{
		oneUser.m_sBalance-=transferMoney;
		db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
		rs.m_pDatabase=&db;
		str.Format(_T("%d"),oneUser.m_sBalance);
	    CString sql=_T("update bankUser set m_balance='")+str+_T("'where m_ID=")+str_ID;
		db.ExecuteSQL(sql);
		rs.Close();
		db.Close();

		//ת�˳ɹ�,������ʾ����
		TransferSucceDlg myDlg;
		myDlg.DoModal();
	}
	else {
		//���㣬������ʾDlg
		TransferFailDlg myDlg;
		myDlg.DoModal();
	}
}


void TransferDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage homePage;
	homePage.DoModal();
}


void TransferDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

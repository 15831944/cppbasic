// DeleteDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"


// DeleteDlg �Ի���

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


// DeleteDlg ��Ϣ�������


void DeleteDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage myPage;
	myPage.DoModal();
}


void DeleteDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

// RevisePasswordDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "RevisePasswordDlg.h"
#include "afxdialogex.h"


// RevisePasswordDlg �Ի���

IMPLEMENT_DYNAMIC(RevisePasswordDlg, CDialogEx)

RevisePasswordDlg::RevisePasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RevisePasswordDlg::IDD, pParent)
	, rePassword(_T(""))
{

}

RevisePasswordDlg::~RevisePasswordDlg()
{
}

void RevisePasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, rePassword);
}


BEGIN_MESSAGE_MAP(RevisePasswordDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &RevisePasswordDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &RevisePasswordDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &RevisePasswordDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// RevisePasswordDlg ��Ϣ�������


void RevisePasswordDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ȷ���޸�����
	UpdateData(TRUE);
	oneUser.m_sPassword=rePassword;
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	//str.Format(_T("%d"),oneUser.m_sPassword);
	CString sql=_T("update bankUser set m_password='")+oneUser.m_sPassword+_T("'where m_ID=")+str_ID;
	db.ExecuteSQL(sql);
	rs.Close();
	db.Close();
	ReviseSuccessDlg rePasswordDlg;
	rePasswordDlg.DoModal();
}


void RevisePasswordDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//������ҳ
	HomePage homePage;
	homePage.DoModal();
}


void RevisePasswordDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�˳�����
	exit(0);
}

// QueryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "QueryDlg.h"
#include "afxdialogex.h"


// QueryDlg �Ի���

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


// QueryDlg ��Ϣ�������


void QueryDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ȷ���ύ���
	QuerySucessDlg querySuccessDlg;
	querySuccessDlg.DoModal();
}


void QueryDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage homePage;
	homePage.DoModal();
}


void QueryDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

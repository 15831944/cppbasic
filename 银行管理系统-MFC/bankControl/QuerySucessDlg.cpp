// QuerySucessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "QuerySucessDlg.h"
#include "afxdialogex.h"


// QuerySucessDlg �Ի���

IMPLEMENT_DYNAMIC(QuerySucessDlg, CDialogEx)

QuerySucessDlg::QuerySucessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(QuerySucessDlg::IDD, pParent)
{

}

QuerySucessDlg::~QuerySucessDlg()
{
}

void QuerySucessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QuerySucessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &QuerySucessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &QuerySucessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// QuerySucessDlg ��Ϣ�������


void QuerySucessDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage homePage;
	homePage.DoModal();
}


void QuerySucessDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

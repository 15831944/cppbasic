// ReviseSuccessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "ReviseSuccessDlg.h"
#include "afxdialogex.h"


// ReviseSuccessDlg �Ի���

IMPLEMENT_DYNAMIC(ReviseSuccessDlg, CDialogEx)

ReviseSuccessDlg::ReviseSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ReviseSuccessDlg::IDD, pParent)
{

}

ReviseSuccessDlg::~ReviseSuccessDlg()
{
}

void ReviseSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReviseSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ReviseSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ReviseSuccessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ReviseSuccessDlg ��Ϣ�������


void ReviseSuccessDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage homePage;
	homePage.DoModal();
}


void ReviseSuccessDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

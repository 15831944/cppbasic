// DeleteSuccessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "DeleteSuccessDlg.h"
#include "afxdialogex.h"


// DeleteSuccessDlg �Ի���

IMPLEMENT_DYNAMIC(DeleteSuccessDlg, CDialogEx)

DeleteSuccessDlg::DeleteSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DeleteSuccessDlg::IDD, pParent)
{

}

DeleteSuccessDlg::~DeleteSuccessDlg()
{
}

void DeleteSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DeleteSuccessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// DeleteSuccessDlg ��Ϣ�������


void DeleteSuccessDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CbankControlDlg myPage;
	myPage.DoModal();
}


void DeleteSuccessDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

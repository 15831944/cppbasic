// TransferFailDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "TransferFailDlg.h"
#include "afxdialogex.h"


// TransferFailDlg �Ի���

IMPLEMENT_DYNAMIC(TransferFailDlg, CDialogEx)

TransferFailDlg::TransferFailDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TransferFailDlg::IDD, pParent)
{

}

TransferFailDlg::~TransferFailDlg()
{
}

void TransferFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TransferFailDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TransferFailDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TransferFailDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// TransferFailDlg ��Ϣ�������


void TransferFailDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage homePage;
	homePage.DoModal();
}


void TransferFailDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

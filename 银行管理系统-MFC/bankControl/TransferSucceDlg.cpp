// TransferSucceDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "TransferSucceDlg.h"
#include "afxdialogex.h"


// TransferSucceDlg �Ի���

IMPLEMENT_DYNAMIC(TransferSucceDlg, CDialogEx)

TransferSucceDlg::TransferSucceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TransferSucceDlg::IDD, pParent)
{

}

TransferSucceDlg::~TransferSucceDlg()
{
}

void TransferSucceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TransferSucceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TransferSucceDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TransferSucceDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// TransferSucceDlg ��Ϣ�������


void TransferSucceDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage homePage;
	homePage.DoModal();
}


void TransferSucceDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

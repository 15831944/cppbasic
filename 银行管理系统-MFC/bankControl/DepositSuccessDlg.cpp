// DepositSuccessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "DepositSuccessDlg.h"
#include "afxdialogex.h"


// DepositSuccessDlg �Ի���

IMPLEMENT_DYNAMIC(DepositSuccessDlg, CDialogEx)

DepositSuccessDlg::DepositSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DepositSuccessDlg::IDD, pParent)
{

}

DepositSuccessDlg::~DepositSuccessDlg()
{
}

void DepositSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DepositSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DepositSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DepositSuccessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// DepositSuccessDlg ��Ϣ�������


void DepositSuccessDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ɹ���������ҳ
	HomePage homePage;
	homePage.DoModal();
}


void DepositSuccessDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

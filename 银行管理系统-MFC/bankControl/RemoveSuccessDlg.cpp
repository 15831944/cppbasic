// RemoveSuccessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "RemoveSuccessDlg.h"
#include "afxdialogex.h"


// RemoveSuccessDlg �Ի���

IMPLEMENT_DYNAMIC(RemoveSuccessDlg, CDialogEx)

RemoveSuccessDlg::RemoveSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RemoveSuccessDlg::IDD, pParent)
	, RemoveSuccess_Balance(0)
{

}

RemoveSuccessDlg::~RemoveSuccessDlg()
{
}

void RemoveSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RemoveSuccessBalance_Edit, RemoveSuccess_Balance);
}


BEGIN_MESSAGE_MAP(RemoveSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RemoveSuccessDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RemoveSuccessDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &RemoveSuccessDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// RemoveSuccessDlg ��Ϣ�������


void RemoveSuccessDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	HomePage homePage;
	homePage.DoModal();
}


void RemoveSuccessDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}


void RemoveSuccessDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ʾ���
	RemoveSuccess_Balance=oneUser.m_sBalance;
	UpdateData(FALSE);
}

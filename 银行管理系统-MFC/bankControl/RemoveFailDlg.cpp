// RemoveFailDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "RemoveFailDlg.h"
#include "afxdialogex.h"


// RemoveFailDlg �Ի���

IMPLEMENT_DYNAMIC(RemoveFailDlg, CDialogEx)

RemoveFailDlg::RemoveFailDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RemoveFailDlg::IDD, pParent)
{

}

RemoveFailDlg::~RemoveFailDlg()
{
}

void RemoveFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RemoveFailDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RemoveFailDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RemoveFailDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// RemoveFailDlg ��Ϣ�������


void RemoveFailDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	//ȡ��ɹ���������ҳ
	HomePage homePageDlg;
	homePageDlg.DoModal();
}


void RemoveFailDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}

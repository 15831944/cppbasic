// CreateSuccessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "CreateSuccessDlg.h"
#include "afxdialogex.h"


// CreateSuccessDlg �Ի���

IMPLEMENT_DYNAMIC(CreateSuccessDlg, CDialogEx)

CreateSuccessDlg::CreateSuccessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CreateSuccessDlg::IDD, pParent)
	, _newID(0)
{

}

CreateSuccessDlg::~CreateSuccessDlg()
{
}

void CreateSuccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _newID);
}


BEGIN_MESSAGE_MAP(CreateSuccessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CreateSuccessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CreateSuccessDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CreateSuccessDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CreateSuccessDlg ��Ϣ�������


void CreateSuccessDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ص�½����
	CbankControlDlg controlDlg;
	controlDlg.DoModal();
}


void CreateSuccessDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CreateSuccessDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_newID=oneUser.m_uID;
	UpdateData(FALSE);
}

// OnlineDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "OnlineDlg.h"
#include "afxdialogex.h"


// OnlineDlg �Ի���

IMPLEMENT_DYNAMIC(OnlineDlg, CDialogEx)

OnlineDlg::OnlineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(OnlineDlg::IDD, pParent)
{

}

OnlineDlg::~OnlineDlg()
{
}

void OnlineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(OnlineDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &OnlineDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &OnlineDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// OnlineDlg ��Ϣ�������


void OnlineDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HomePage homePage;
	homePage.DoModal();
}


void OnlineDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

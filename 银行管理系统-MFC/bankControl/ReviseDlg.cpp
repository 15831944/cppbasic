// ReviseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "ReviseDlg.h"
#include "afxdialogex.h"


// ReviseDlg �Ի���

IMPLEMENT_DYNAMIC(ReviseDlg, CDialogEx)

ReviseDlg::ReviseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ReviseDlg::IDD, pParent)
{

}

ReviseDlg::~ReviseDlg()
{
}

void ReviseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReviseDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ReviseDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ReviseDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ReviseDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &ReviseDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// ReviseDlg ��Ϣ�������


void ReviseDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸�һ����Ϣ
	ReviseMostDlg reviseMostDlg;
	reviseMostDlg.DoModal();
}


void ReviseDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸�����
	RevisePasswordDlg rePasswordDlg;
	rePasswordDlg.DoModal();
}


void ReviseDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//������ҳ
	HomePage homePage;
	homePage.DoModal();
}


void ReviseDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�˳�����
	exit(0);
}

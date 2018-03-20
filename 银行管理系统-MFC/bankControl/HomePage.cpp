// HomePage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "HomePage.h"
#include "afxdialogex.h"


// HomePage �Ի���

IMPLEMENT_DYNAMIC(HomePage, CDialogEx)

HomePage::HomePage(CWnd* pParent /*=NULL*/)
	: CDialogEx(HomePage::IDD, pParent)
{

}

HomePage::~HomePage()
{
}

void HomePage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HomePage, CDialogEx)
	ON_BN_CLICKED(IDC_Transfer_Button, &HomePage::OnBnClickedTransferButton)
	ON_BN_CLICKED(IDC_RemoveMoney_Button, &HomePage::OnBnClickedRemovemoneyButton)
	ON_BN_CLICKED(IDC_Deposit_Button, &HomePage::OnBnClickedDepositButton)
	ON_BN_CLICKED(IDC_Change_Button, &HomePage::OnBnClickedChangeButton)
	ON_BN_CLICKED(IDC_Check_Button, &HomePage::OnBnClickedCheckButton)
	ON_BN_CLICKED(IDC_Exit_Button, &HomePage::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_Online_Button, &HomePage::OnBnClickedOnlineButton)
	ON_BN_CLICKED(IDC_Delete_Button, &HomePage::OnBnClickedDeleteButton)
END_MESSAGE_MAP()


// HomePage ��Ϣ�������



void HomePage::OnBnClickedRemovemoneyButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ȡ��
	RemoveMoneyDlg removeMoneyDlg;
	removeMoneyDlg.DoModal();
}


void HomePage::OnBnClickedDepositButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���
	DepositDlg depositDlg;
	depositDlg.DoModal();
}

void HomePage::OnBnClickedTransferButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ת��
	TransferDlg transferDlg;
	transferDlg.DoModal();
}

void HomePage::OnBnClickedChangeButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸���Ϣ
	ReviseDlg reviseDlg;
	reviseDlg.DoModal();
}


void HomePage::OnBnClickedCheckButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�鿴��ϸ
	QueryDlg queryDlg;
	queryDlg.DoModal();
}


void HomePage::OnBnClickedDeleteButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����
	DeleteDlg deleteDlg;
	deleteDlg.DoModal();
}


void HomePage::OnBnClickedOnlineButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��������
	OnlineDlg onlineDlg;
	onlineDlg.DoModal();
}

void HomePage::OnBnClickedExitButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}





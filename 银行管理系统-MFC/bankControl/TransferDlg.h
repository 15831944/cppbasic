#pragma once


// TransferDlg �Ի���

class TransferDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TransferDlg)

public:
	TransferDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TransferDlg();

// �Ի�������
	enum { IDD = IDD_Transfer_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int transferAccount;
	double transferMoney;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#include "TransferSucceDlg.h"
#include "TransferFailDlg.h"
#include "HomePage.h"

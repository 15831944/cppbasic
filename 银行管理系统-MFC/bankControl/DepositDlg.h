#pragma once


// DepositDlg �Ի���

class DepositDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DepositDlg)

public:
	DepositDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DepositDlg();

// �Ի�������
	enum { IDD = IDD_Deposit_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double depositMoney;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "DepositSuccessDlg.h"
#include "HomePage.h"


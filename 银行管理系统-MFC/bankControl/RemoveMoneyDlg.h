#pragma once


// RemoveMoneyDlg �Ի���

class RemoveMoneyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveMoneyDlg)

public:
	RemoveMoneyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RemoveMoneyDlg();

// �Ի�������
	enum { IDD = IDD_RemoveMoney_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double accountBalance;
	double WithdrawalAmount;
	afx_msg void OnBnClickedsubmitbutton();
	afx_msg void OnBnClickedcancelbutton();
	afx_msg void OnBnClickedButton3();
};

#include "RemoveSuccessDlg.h"
#include "RemoveFailDlg.h"
#include "HomePage.h"

#pragma once


// RemoveMoneyDlg 对话框

class RemoveMoneyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveMoneyDlg)

public:
	RemoveMoneyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RemoveMoneyDlg();

// 对话框数据
	enum { IDD = IDD_RemoveMoney_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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

#pragma once


// DepositDlg 对话框

class DepositDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DepositDlg)

public:
	DepositDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DepositDlg();

// 对话框数据
	enum { IDD = IDD_Deposit_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double depositMoney;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "DepositSuccessDlg.h"
#include "HomePage.h"


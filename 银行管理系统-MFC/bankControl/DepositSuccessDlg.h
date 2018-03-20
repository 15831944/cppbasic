#pragma once


// DepositSuccessDlg 对话框

class DepositSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DepositSuccessDlg)

public:
	DepositSuccessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DepositSuccessDlg();

// 对话框数据
	enum { IDD = IDD_DepositSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


#include "HomePage.h"
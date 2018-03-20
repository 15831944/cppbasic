#pragma once


// HomePage 对话框

class HomePage : public CDialogEx
{
	DECLARE_DYNAMIC(HomePage)

public:
	HomePage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HomePage();

// 对话框数据
	enum { IDD = IDD_HomePage_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTransferButton();
	afx_msg void OnBnClickedRemovemoneyButton();
	afx_msg void OnBnClickedDepositButton();
	afx_msg void OnBnClickedChangeButton();
	afx_msg void OnBnClickedCheckButton();
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedOnlineButton();
	afx_msg void OnBnClickedDeleteButton();
};

#include "RemoveMoneyDlg.h"
#include "DepositDlg.h"
#include "ReviseDlg.h"
#include "TransferDlg.h"
#include "QueryDlg.h"
#include "OnlineDlg.h"
#include "DeleteDlg.h"
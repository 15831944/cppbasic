#pragma once


// RemoveSuccessDlg 对话框

class RemoveSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveSuccessDlg)

public:
	RemoveSuccessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RemoveSuccessDlg();

// 对话框数据
	enum { IDD = IDD_RemoveSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	double RemoveSuccess_Balance;
	afx_msg void OnBnClickedButton1();
};

#include "HomePage.h"
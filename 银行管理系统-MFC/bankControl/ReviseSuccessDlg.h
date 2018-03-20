#pragma once


// ReviseSuccessDlg 对话框

class ReviseSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReviseSuccessDlg)

public:
	ReviseSuccessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ReviseSuccessDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "HomePage.h"

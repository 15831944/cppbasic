#pragma once


// CreateSuccessDlg 对话框

class CreateSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CreateSuccessDlg)

public:
	CreateSuccessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CreateSuccessDlg();

// 对话框数据
	enum { IDD = IDD_CreateSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int _newID;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#include "bankControlDlg.h"

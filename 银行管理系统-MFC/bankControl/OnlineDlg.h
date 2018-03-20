#pragma once


// OnlineDlg 对话框

class OnlineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(OnlineDlg)

public:
	OnlineDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OnlineDlg();

// 对话框数据
	enum { IDD = IDD_Online_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "HomePage.h"

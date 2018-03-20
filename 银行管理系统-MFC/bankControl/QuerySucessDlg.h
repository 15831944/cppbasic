#pragma once


// QuerySucessDlg 对话框

class QuerySucessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QuerySucessDlg)

public:
	QuerySucessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~QuerySucessDlg();

// 对话框数据
	enum { IDD = IDD_QuerySuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "HomePage.h"

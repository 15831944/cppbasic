#pragma once


// QueryDlg 对话框

class QueryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryDlg)

public:
	QueryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~QueryDlg();

// 对话框数据
	enum { IDD = IDD_Query_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString message;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#include "QuerySucessDlg.h"
#include "HomePage.h"

#pragma once


// ReviseMostDlg 对话框

class ReviseMostDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReviseMostDlg)

public:
	ReviseMostDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ReviseMostDlg();

// 对话框数据
	enum { IDD = IDD_ReviseMost_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString reName;
	CString reSex;
	CString reIDNumber;
	CString reCompany;
	LONGLONG reTelphone;
	CString reAddress;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#include "HomePage.h"
#include "ReviseSuccessDlg.h"
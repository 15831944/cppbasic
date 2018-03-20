#pragma once


// CCreateDlg 对话框

class CCreateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCreateDlg)

public:
	CCreateDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCreateDlg();

// 对话框数据
	enum { IDD = IDD_Create_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_userName;
	CString m_userSex;
	CString m_userIDNumber;
	CString m_userCompany;
	LONGLONG m_userTelphone;
	CString m_userPassword;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "CreateSuccessDlg.h"
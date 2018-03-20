
// bankControlDlg.h : 头文件
//

#pragma once


// CbankControlDlg 对话框
class CbankControlDlg : public CDialogEx
{
// 构造
public:
	CbankControlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BANKCONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	LONGLONG m_userID;
	int m_userPassword;
	afx_msg void OnBnClickedsubmitbutton();
	//afx_msg void OnBnClickedCreateButton();
	afx_msg void OnBnClickedCreateButton();
	afx_msg void OnBnClickedcancelbutton();
};

#include "TipLogID.h"
#include "TipLogPassword.h"
#include "HomePage.h"
#include "bankControl.h"
#include "bankUser.h"
#include "resource.h"
#include "stdafx.h"
#include "targetver.h"
#include "CreateDlg.h"

// bankControlDlg.h : ͷ�ļ�
//

#pragma once


// CbankControlDlg �Ի���
class CbankControlDlg : public CDialogEx
{
// ����
public:
	CbankControlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BANKCONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
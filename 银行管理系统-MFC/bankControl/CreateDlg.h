#pragma once


// CCreateDlg �Ի���

class CCreateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCreateDlg)

public:
	CCreateDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCreateDlg();

// �Ի�������
	enum { IDD = IDD_Create_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
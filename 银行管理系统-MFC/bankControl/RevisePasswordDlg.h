#pragma once


// RevisePasswordDlg �Ի���

class RevisePasswordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RevisePasswordDlg)

public:
	RevisePasswordDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RevisePasswordDlg();

// �Ի�������
	enum { IDD = IDD_RevisePassword_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString rePassword;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#include "ReviseSuccessDlg.h"
#include "HomePage.h"

#pragma once


// ReviseSuccessDlg �Ի���

class ReviseSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReviseSuccessDlg)

public:
	ReviseSuccessDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ReviseSuccessDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "HomePage.h"

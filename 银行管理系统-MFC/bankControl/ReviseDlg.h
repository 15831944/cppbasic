#pragma once


// ReviseDlg �Ի���

class ReviseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReviseDlg)

public:
	ReviseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ReviseDlg();

// �Ի�������
	enum { IDD = IDD_Revise_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};

#include "ReviseMostDlg.h"
#include "HomePage.h"
#include "RevisePasswordDlg.h"

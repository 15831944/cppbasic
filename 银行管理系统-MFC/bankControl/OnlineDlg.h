#pragma once


// OnlineDlg �Ի���

class OnlineDlg : public CDialogEx
{
	DECLARE_DYNAMIC(OnlineDlg)

public:
	OnlineDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~OnlineDlg();

// �Ի�������
	enum { IDD = IDD_Online_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "HomePage.h"

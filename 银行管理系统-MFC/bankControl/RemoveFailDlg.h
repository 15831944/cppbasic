#pragma once


// RemoveFailDlg �Ի���

class RemoveFailDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveFailDlg)

public:
	RemoveFailDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RemoveFailDlg();

// �Ի�������
	enum { IDD = IDD_RemoveFail_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};


#include "HomePage.h"
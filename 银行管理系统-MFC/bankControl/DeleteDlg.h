#pragma once


// DeleteDlg �Ի���

class DeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteDlg)

public:
	DeleteDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DeleteDlg();

// �Ի�������
	enum { IDD = IDD_Delete_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};


#include "DeleteSuccessDlg.h"
#include "HomePage.h"
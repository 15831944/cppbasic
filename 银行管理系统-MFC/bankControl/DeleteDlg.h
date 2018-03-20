#pragma once


// DeleteDlg 对话框

class DeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteDlg)

public:
	DeleteDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DeleteDlg();

// 对话框数据
	enum { IDD = IDD_Delete_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};


#include "DeleteSuccessDlg.h"
#include "HomePage.h"
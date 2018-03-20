#pragma once


// CTipLogID 对话框

class CTipLogID : public CDialogEx
{
	DECLARE_DYNAMIC(CTipLogID)

public:
	CTipLogID(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTipLogID();

// 对话框数据
	enum { IDD = IDD_TipLogID_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

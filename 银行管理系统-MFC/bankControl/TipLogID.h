#pragma once


// CTipLogID �Ի���

class CTipLogID : public CDialogEx
{
	DECLARE_DYNAMIC(CTipLogID)

public:
	CTipLogID(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTipLogID();

// �Ի�������
	enum { IDD = IDD_TipLogID_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

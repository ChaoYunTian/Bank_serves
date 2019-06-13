#pragma once


// CManageDlg 对话框

class CManageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManageDlg)

public:
	CManageDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManageDlg();

// 对话框数据
	enum { IDD = IDD_MANAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

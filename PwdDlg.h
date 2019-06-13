#pragma once


// CPwdDlg 对话框

class CPwdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPwdDlg)

public:
	CPwdDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPwdDlg();

// 对话框数据
	enum { IDD = IDD_CHANGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};

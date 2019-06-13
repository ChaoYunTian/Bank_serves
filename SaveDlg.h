#pragma once

#include "Person.h"
// CSaveDlg 对话框

class CSaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSaveDlg)

public:
	CPerson person[20];
	CSaveDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSaveDlg();

// 对话框数据
	enum { IDD = IDD_SAVEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();

public:
	int read();
	bool check(CString id,CString pwd);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit6();
};

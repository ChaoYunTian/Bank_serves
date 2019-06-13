#pragma once
#include "Person.h"

// CDeleteDlg 对话框

class CDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteDlg)

public:
	CPerson person[20];
	CDeleteDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteDlg();

// 对话框数据
	enum { IDD = IDD_DELEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	int read();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
};

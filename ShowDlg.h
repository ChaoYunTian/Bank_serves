#pragma once
#include "afxcmn.h"

#include "Save.h"
// CShowDlg 对话框

class CShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShowDlg)

public:
	CSave save[20];
	CShowDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShowDlg();

// 对话框数据
	enum { IDD = IDD_SHOWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void showall();
	int read();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};

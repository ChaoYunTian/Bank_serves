#pragma once
#include "afxcmn.h"
#include "GetMoney.h"

// CGetInfoDlg 对话框

class CGetInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGetInfoDlg)

public:
	CGetMoney mm[20];
	CGetInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGetInfoDlg();

// 对话框数据
	enum { IDD = IDD_GETINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	int read();
	void showall();
};

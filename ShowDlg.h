#pragma once
#include "afxcmn.h"

#include "Save.h"
// CShowDlg �Ի���

class CShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShowDlg)

public:
	CSave save[20];
	CShowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowDlg();

// �Ի�������
	enum { IDD = IDD_SHOWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void showall();
	int read();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};

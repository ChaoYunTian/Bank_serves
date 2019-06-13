// ManageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "ManageDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"
#include "ServerDlg.h"

// CManageDlg 对话框

IMPLEMENT_DYNAMIC(CManageDlg, CDialogEx)

CManageDlg::CManageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManageDlg::IDD, pParent)
{

}

CManageDlg::~CManageDlg()
{
}

void CManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CManageDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CManageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CManageDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CManageDlg 消息处理程序


void CManageDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
}


void CManageDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CManageDlg::OnCancel();
	CClientDlg dlg;
	dlg.DoModal();
}


void CManageDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CManageDlg::OnCancel();
	CServerDlg dlg;
	dlg.DoModal();
}

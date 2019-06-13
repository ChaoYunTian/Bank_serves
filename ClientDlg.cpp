// ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "ClientDlg.h"
#include "afxdialogex.h"
#include "NewDlg.h"
#include "SaveDlg.h"
#include "DeleteDlg.h"
#include "GetDlg.h"
#include "ManageDlg.h"


// CClientDlg 对话框

IMPLEMENT_DYNAMIC(CClientDlg, CDialogEx)

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientDlg::IDD, pParent)
{

}

CClientDlg::~CClientDlg()
{
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &CClientDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CClientDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CClientDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CClientDlg 消息处理程序


void CClientDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
	CManageDlg dlg;//返回服务身份选择页
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CClientDlg::OnCancel();
	CNewDlg dlg;//进入开户页
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CClientDlg::OnCancel();
	CSaveDlg dlg;//进入存款页
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CClientDlg::OnCancel();
	CDeleteDlg dlg;
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CClientDlg::OnCancel();
	CGetDlg dlg;
	dlg.DoModal();

}

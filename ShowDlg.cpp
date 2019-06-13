// ShowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "ShowDlg.h"
#include "afxdialogex.h"
#include "ServerDlg.h"


// CShowDlg 对话框

IMPLEMENT_DYNAMIC(CShowDlg, CDialogEx)

CShowDlg::CShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowDlg::IDD, pParent)
{

}

CShowDlg::~CShowDlg()
{
}

void CShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CShowDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CShowDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CShowDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CShowDlg 消息处理程序


BOOL CShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.InsertColumn(0,"账号",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"金额",LVCFMT_CENTER,100);
	m_list.InsertColumn(2,"存款时间",LVCFMT_CENTER,120);
	m_list.InsertColumn(3,"天数",LVCFMT_CENTER,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	showall();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

int CShowDlg::read()
{
	int i=0;
	ifstream file;
	file.open("save.txt",ios::in);
	while(!file.eof())
	{
		file>>save[i].id>>save[i].pwd>>save[i].money>>save[i].date>>save[i].days;
		i++;
	}
	i--;
	file.close();
	return i;
}

void CShowDlg::showall()
{
	for(int i =0;i<read();i++)
	{
		m_list.InsertItem(i,0);
		m_list.SetItemText(i,0,save[i].id);
		CString str;
		str.Format("%f",save[i].money);
		m_list.SetItemText(i,1,str);
		m_list.SetItemText(i,2,save[i].date);
		str.Format("%d",save[i].days);
		m_list.SetItemText(i,3,str);
	}
}


void CShowDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	CServerDlg dlg;
	dlg.DoModal();
}


void CShowDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CServerDlg dlg;
	dlg.DoModal();
}

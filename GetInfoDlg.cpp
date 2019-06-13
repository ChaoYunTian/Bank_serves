// GetInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "GetInfoDlg.h"
#include "afxdialogex.h"
#include "ServerDlg.h"


// CGetInfoDlg 对话框

IMPLEMENT_DYNAMIC(CGetInfoDlg, CDialogEx)

CGetInfoDlg::CGetInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetInfoDlg::IDD, pParent)
{

}

CGetInfoDlg::~CGetInfoDlg()
{
}

void CGetInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CGetInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGetInfoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGetInfoDlg 消息处理程序


void CGetInfoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
	CServerDlg dlg;
	dlg.DoModal();
}


BOOL CGetInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//初始化列表

	// TODO:  在此添加额外的初始化
	m_list.InsertColumn(0,"账号",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"金额",LVCFMT_CENTER,100);
	m_list.InsertColumn(2,"取款时间",LVCFMT_CENTER,120);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//显示全部取款信息
	showall();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

int CGetInfoDlg::read()//读取取款信息到类数组
{
	int i=0;
	ifstream file;
	file.open("get.txt",ios::in);
	while(!file.eof())
	{
		file>>mm[i].id>>mm[i].pwd>>mm[i].money>>mm[i].date;
		i++;
	}
	i--;
	file.close();
	return i;
}

void CGetInfoDlg::showall()//显示类数组的数据
{
	for(int i =0;i<read();i++)
	{
		m_list.InsertItem(i,0);
		m_list.SetItemText(i,0,mm[i].id);
		CString str;
		str.Format("%f",mm[i].money);
		m_list.SetItemText(i,1,str);
		m_list.SetItemText(i,2,mm[i].date);
	}
}

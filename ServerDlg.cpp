// ServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "ServerDlg.h"
#include "afxdialogex.h"
#include "PwdDlg.h"
#include "ShowDlg.h"
#include "GetInfoDlg.h"
#include "ManageDlg.h"


// CServerDlg 对话框

IMPLEMENT_DYNAMIC(CServerDlg, CDialogEx)

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServerDlg::IDD, pParent)
{

}

CServerDlg::~CServerDlg()
{
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CServerDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &CServerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CServerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CServerDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CServerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CServerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON8, &CServerDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CServerDlg 消息处理程序


void CServerDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
	CManageDlg dlg;
	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int num =read();
	float money =0;
	for(int i =0;i<num;i++)
	{
		money = money +person[i].money;
	}
	CString str;
	str.Format("当前账户总余额为:%f",money);
	MessageBox(str);
}


int CServerDlg::read()
{
	int i=0;
	ifstream file;
	file.open("user.txt",ios::in);
	while(!file.eof())
	{
		file>>person[i].id>>person[i].name>>person[i].pwd>>person[i].address>>person[i].pid>>person[i].date>>person[i].money>>person[i].status;
		i++;
	}
	i--;
	file.close();
	return i;
}

int CServerDlg::readsave()
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

void CServerDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CPwdDlg dlg;
	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码 
	SYSTEMTIME st = {0};

	GetLocalTime(&st);
	CString str;
	str.Format("%d%02d%02d",st.wYear,st.wMonth,st.wDay);
	int y = st.wYear;
	int m = st.wMonth;
	int d = st.wDay;

	int num = readsave();
	float money =0 ;
	for(int i =0;i<num;i++)
	{
		CString date = save[i].date;
		CString year1 = date.Left(4);
		CString day1 = date.Right(2);
		CString month1 = date.Mid(4,2);
		int y1 = atoi(year1);
		int m1 = atoi(month1);
		int d1 = atoi(day1);
		if((y-y1)*365+(m-m1)*30+(d-d1)-save[i].days<3&&(y-y1)*365+(m-m1)*30+(d-d1)-save[i].days>=0)
		{
			money = money +save[i].money;
		}
	}
	str.Format("最近三天应该准备的钱款总数为:%f",money);
	MessageBox(str);

}


void CServerDlg::OnBnClickedButton2()
{
	CShowDlg dlg;
	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CGetInfoDlg dlg;
	dlg.DoModal();
}

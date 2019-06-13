// NewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "NewDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"


// CNewDlg 对话框

IMPLEMENT_DYNAMIC(CNewDlg, CDialogEx)

CNewDlg::CNewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewDlg::IDD, pParent)
{

}

CNewDlg::~CNewDlg()
{
}

void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &CNewDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CNewDlg::OnBnClickedButton7)
	ON_EN_CHANGE(IDC_EDIT1, &CNewDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CNewDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CNewDlg 消息处理程序


void CNewDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString id,name,pwd,address,pid,date;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(id);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(name);
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(address);
	GetDlgItem(IDC_EDIT5)->GetWindowTextA(pid);
	GetDlgItem(IDC_EDIT6)->GetWindowTextA(date);
	if(id==""||name==""||pwd==""||address==""||pid==""||date=="")
	{
		MessageBox("储户信息不能为空");
		return;
	}
	CString servername,serverid;
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(servername);
	GetDlgItem(IDC_EDIT8)->GetWindowTextA(serverid);
	if(servername==""||serverid=="")
	{
		MessageBox("经办人信息不能为空");
		return;
	}
	if(check(id))
	{
		MessageBox("该账号已经存在，请勿重复添加");
		return;
	}
	ofstream file;
	file.open("user.txt",ios::app);
	file<<id<<"   "<<name<<"   "<<pwd<<"    "<<address<<"    "<<pid<<"    "<<date<<"    "<<0<<"   "<<0<<endl;
	file.close();
	MessageBox("开通成功");
}


int CNewDlg::readall()
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
	return i;
}

bool CNewDlg::check(CString id)
{
	for(int i =0;i<readall();i++)
	{
		if(strcmp(id,person[i].id)==0)
		{
			return true;
		}
	}
	return false;
}

void CNewDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
	CClientDlg dlg;
	dlg.DoModal();
}


BOOL CNewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//开户自动生成账号
	int num = readall();
	if(num == 0)//如果不存在，则初始化123456
	{
		GetDlgItem(IDC_EDIT1)->SetWindowTextA("123456");
	}
	else//如果存在，自增
	{
		int id = atoi(person[num-1].id);
		id++;
		CString str;
		str.Format("%d",id);
		GetDlgItem(IDC_EDIT1)->SetWindowTextA(str);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CNewDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CNewDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

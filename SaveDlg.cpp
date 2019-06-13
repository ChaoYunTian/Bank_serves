// SaveDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "SaveDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"

// CSaveDlg 对话框

IMPLEMENT_DYNAMIC(CSaveDlg, CDialogEx)

CSaveDlg::CSaveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSaveDlg::IDD, pParent)
{

}

CSaveDlg::~CSaveDlg()
{
}

void CSaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSaveDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON8, &CSaveDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON5, &CSaveDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CSaveDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSaveDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT6, &CSaveDlg::OnEnChangeEdit6)
END_MESSAGE_MAP()


// CSaveDlg 消息处理程序


void CSaveDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
	CClientDlg dlg;
	dlg.DoModal();
}


void CSaveDlg::OnBnClickedButton5()//存款
{
	// TODO: 在此添加控件通知处理程序代码
	CString user,pwd,money,interest,date,type;
	int stime;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(money);
	GetDlgItem(IDC_EDIT6)->GetWindowTextA(interest);
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(date);
	GetDlgItem(IDC_COMBO1)->GetWindowTextA(type);
	if(type == "三个月")
	{
		stime = 90;
	}
	else if(type == "半年")
	{
		stime = 180;
	}
	else if(type == "一年")
	{
		stime = 365;
	}
	else if(type == "两年")
	{
		stime = 365*2;
	}
	else if(type =="三年")
	{
		stime = 365*3;
	}
	if(interest == "")
	{
		MessageBox("请先计算利息");
		return;
	}
	if( user==""||pwd==""||money==""||interest==""||date==""||type=="")
	{
		MessageBox("存款信息不能为空");
		return ;
	}

	int num = read();

	//写入存款txt
	ofstream file;
	file.open("save.txt",ios::app);
	file<<user<<"   "<<pwd<<"   "<<money<<"    "<<date<<"    "<<stime<<endl;
	file.close();
	MessageBox("存款成功");

	CString str;
	str.Format("存款账号:%s\r\n存款金额:%s\r\n存款时间:%s\r\n存款储种:%s\r\n",user,money,date,type);

	MessageBox(str);

	//user里面账户余额增加

	ofstream file1;
	file1.open("user.txt",ios::ate);
	for(int i=0;i<num;i++)
	{
		if(strcmp(user,person[i].id)==0)
		{
			person[i].money = person[i].money+atoi(money);
		}
		{
		file1<<person[i].id<<"    "<<person[i].name<<"    "<<person[i].pwd<<"    "<<person[i].address<<"    "<<person[i].pid<<"    "<<person[i].date<<"    "<<person[i].money<<"    "<<person[i].status<<endl;
		}
	}
	file1.close();
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);

}


void CSaveDlg::OnBnClickedButton1()//验证账号密码
{
	// TODO: 在此添加控件通知处理程序代码
	CString user,pwd;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	if(check(user,pwd))
	{
		MessageBox("验证通过");
		GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	}
	else
	{
		MessageBox("账号、密码错误或此账号已挂失");
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		return;
	}

}

int CSaveDlg::read()//读取所有的账户信息
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

bool CSaveDlg::check(CString id,CString pwd)//校验账户和密码
{
	for(int i =0;i<read();i++)
	{
		if(strcmp(id,person[i].id)==0&&strcmp(pwd,person[i].pwd)==0&&person[i].status==0)
		{
			return true;
		}
	}
	return false;
}

BOOL CSaveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);//金庸编辑框

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



void CSaveDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString money;
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(money);
	if(money=="")
	{
		MessageBox("本金不能为空");
		return;
	}
	CString type;
	GetDlgItem(IDC_COMBO1)->GetWindowTextA(type);
	if(type=="")
	{
		MessageBox("请先选择储种");
		return;
	}
	float rate;
	if(type == "三个月")
	{
		rate = 0.011;
	}
	else if(type == "半年")
	{
		rate = 0.013;
	}
	else if(type == "一年")
	{
		rate = 0.015;
	}
	else if(type == "两年")
	{
		rate = 0.021;
	}
	else if(type =="三年")
	{
		rate = 0.0275;
	}
	float interst = atof(money)*rate;
	CString str;
	str.Format("%f",interst);
	GetDlgItem(IDC_EDIT6)->SetWindowTextA(str);
}


void CSaveDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

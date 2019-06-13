// SaveDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "SaveDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"

// CSaveDlg �Ի���

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


// CSaveDlg ��Ϣ�������


void CSaveDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
	CClientDlg dlg;
	dlg.DoModal();
}


void CSaveDlg::OnBnClickedButton5()//���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString user,pwd,money,interest,date,type;
	int stime;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(money);
	GetDlgItem(IDC_EDIT6)->GetWindowTextA(interest);
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(date);
	GetDlgItem(IDC_COMBO1)->GetWindowTextA(type);
	if(type == "������")
	{
		stime = 90;
	}
	else if(type == "����")
	{
		stime = 180;
	}
	else if(type == "һ��")
	{
		stime = 365;
	}
	else if(type == "����")
	{
		stime = 365*2;
	}
	else if(type =="����")
	{
		stime = 365*3;
	}
	if(interest == "")
	{
		MessageBox("���ȼ�����Ϣ");
		return;
	}
	if( user==""||pwd==""||money==""||interest==""||date==""||type=="")
	{
		MessageBox("�����Ϣ����Ϊ��");
		return ;
	}

	int num = read();

	//д����txt
	ofstream file;
	file.open("save.txt",ios::app);
	file<<user<<"   "<<pwd<<"   "<<money<<"    "<<date<<"    "<<stime<<endl;
	file.close();
	MessageBox("���ɹ�");

	CString str;
	str.Format("����˺�:%s\r\n�����:%s\r\n���ʱ��:%s\r\n����:%s\r\n",user,money,date,type);

	MessageBox(str);

	//user�����˻��������

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


void CSaveDlg::OnBnClickedButton1()//��֤�˺�����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString user,pwd;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	if(check(user,pwd))
	{
		MessageBox("��֤ͨ��");
		GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	}
	else
	{
		MessageBox("�˺š�����������˺��ѹ�ʧ");
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		return;
	}

}

int CSaveDlg::read()//��ȡ���е��˻���Ϣ
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

bool CSaveDlg::check(CString id,CString pwd)//У���˻�������
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);//��ӹ�༭��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



void CSaveDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString money;
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(money);
	if(money=="")
	{
		MessageBox("������Ϊ��");
		return;
	}
	CString type;
	GetDlgItem(IDC_COMBO1)->GetWindowTextA(type);
	if(type=="")
	{
		MessageBox("����ѡ����");
		return;
	}
	float rate;
	if(type == "������")
	{
		rate = 0.011;
	}
	else if(type == "����")
	{
		rate = 0.013;
	}
	else if(type == "һ��")
	{
		rate = 0.015;
	}
	else if(type == "����")
	{
		rate = 0.021;
	}
	else if(type =="����")
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

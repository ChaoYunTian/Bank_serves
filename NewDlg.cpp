// NewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "NewDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"


// CNewDlg �Ի���

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


// CNewDlg ��Ϣ�������


void CNewDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString id,name,pwd,address,pid,date;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(id);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(name);
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(address);
	GetDlgItem(IDC_EDIT5)->GetWindowTextA(pid);
	GetDlgItem(IDC_EDIT6)->GetWindowTextA(date);
	if(id==""||name==""||pwd==""||address==""||pid==""||date=="")
	{
		MessageBox("������Ϣ����Ϊ��");
		return;
	}
	CString servername,serverid;
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(servername);
	GetDlgItem(IDC_EDIT8)->GetWindowTextA(serverid);
	if(servername==""||serverid=="")
	{
		MessageBox("��������Ϣ����Ϊ��");
		return;
	}
	if(check(id))
	{
		MessageBox("���˺��Ѿ����ڣ������ظ����");
		return;
	}
	ofstream file;
	file.open("user.txt",ios::app);
	file<<id<<"   "<<name<<"   "<<pwd<<"    "<<address<<"    "<<pid<<"    "<<date<<"    "<<0<<"   "<<0<<endl;
	file.close();
	MessageBox("��ͨ�ɹ�");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
	CClientDlg dlg;
	dlg.DoModal();
}


BOOL CNewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//�����Զ������˺�
	int num = readall();
	if(num == 0)//��������ڣ����ʼ��123456
	{
		GetDlgItem(IDC_EDIT1)->SetWindowTextA("123456");
	}
	else//������ڣ�����
	{
		int id = atoi(person[num-1].id);
		id++;
		CString str;
		str.Format("%d",id);
		GetDlgItem(IDC_EDIT1)->SetWindowTextA(str);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CNewDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CNewDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

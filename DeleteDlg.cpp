// DeleteDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"

// CDeleteDlg �Ի���

IMPLEMENT_DYNAMIC(CDeleteDlg, CDialogEx)

CDeleteDlg::CDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteDlg::IDD, pParent)
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CDeleteDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleteDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CDeleteDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDeleteDlg ��Ϣ�������


void CDeleteDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
	CClientDlg dlg;//���ط�����Ŀѡ��ҳ
	dlg.DoModal();
}

int CDeleteDlg::read()//��ȡ�������ݵ�������
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


void CDeleteDlg::OnBnClickedButton2()//��ʧ֮��ı�status״̬����дuser.txt
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString id,pwd,pid;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(id);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(pid);
	if(id==""||pwd==""||pid=="")
	{
		MessageBox("��ʧ��Ϣ����Ϊ��");
		return;
	}
	int num = read();
	bool isexist = false;
	ofstream file;
	file.open("user.txt",ios::ate);
	for(int i=0;i<num;i++)
	{
		if(strcmp(id,person[i].id)==0&&strcmp(pwd,person[i].pwd)==0&&strcmp(pid,person[i].pid)==0)
		{
			isexist = true;
			person[i].status = 1;
		}
		{
			file<<person[i].id<<"    "<<person[i].name<<"    "<<person[i].pwd<<"    "<<person[i].address<<"    "<<person[i].pid<<"    "<<person[i].date<<"    "<<person[i].money<<"    "<<person[i].status<<endl;
		}
	}
	file.close();
	if(isexist)
	{
		MessageBox("��ʧ�ɹ�");
	}
	else
	{
		MessageBox("��ʧʧ�ܣ�����ȷ�˺��������֤����Ϣ");
	}
}




void CDeleteDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

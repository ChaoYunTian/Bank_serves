// GetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "GetDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"


// CGetDlg �Ի���

IMPLEMENT_DYNAMIC(CGetDlg, CDialogEx)

CGetDlg::CGetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetDlg::IDD, pParent)
{

}

CGetDlg::~CGetDlg()
{
}

void CGetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CGetDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CGetDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CGetDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CGetDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CGetDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CGetDlg ��Ϣ�������


void CGetDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
	CClientDlg dlg;
	dlg.DoModal();
}


void CGetDlg::OnBnClickedButton3()//ȡ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString user,pwd,money,name,id,date;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(money);
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(name);
	GetDlgItem(IDC_EDIT8)->GetWindowTextA(id);
	GetDlgItem(IDC_EDIT9)->GetWindowTextA(date);
	if(user==""||pwd==""||money==""||name==""||id==""||date=="")
	{
		MessageBox("ȡ����Ϣ����Ϊ��");
		return;
	}

	//ʱ��Ƚ��㷨
	CString year = date.Left(4);
	CString day = date.Right(2);
	CString month = date.Mid(4,2);
	int y = atoi(year);
	int m = atoi(month);
	int d = atoi(day);

	getdate(user);

	CString year1 = savedate.Left(4);
	CString day1 = savedate.Right(2);
	CString month1 = savedate.Mid(4,2);
	int y1 = atoi(year1);
	int m1 = atoi(month1);
	int d1 = atoi(day1);


	CString str;
	str.Format("%d",(y-y1)*365+(m-m1)*30+(d-d1));//����ʱ��

	str.Format("%d",saveday);//����ʱ��

	if((y-y1)*365+(m-m1)*30+(d-d1)<saveday)
	{
		MessageBox("���˺���δ����,�����ջ�����Ϣ�������");
	}


	//�������
	int num = read();
	ofstream file;
	file.open("user.txt",ios::ate);
	for(int i=0;i<num;i++)
	{
		if(strcmp(user,person[i].id)==0)
		{
			if(atoi(money)>person[i].money)
			{
				MessageBox("�˻�����");
				return;
			}
			else
			{
				person[i].money = person[i].money - atoi(money);
			}
		}
		{
			file<<person[i].id<<"    "<<person[i].name<<"    "<<person[i].pwd<<"    "<<person[i].address<<"    "<<person[i].pid<<"    "<<person[i].date<<"    "<<person[i].money<<"    "<<person[i].status<<endl;
	
		}
	}
	file.close();
	MessageBox("ȡ��ɹ�");
	//��¼ȡ���¼
	ofstream file1;
	file1.open("get.txt",ios::app);
	file1<<user<<"   "<<pwd<<"   "<<money<<"    "<<date<<endl;
	file1.close();
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
}


void CGetDlg::OnBnClickedButton1()//�˺���֤
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString user,pwd;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	if(user==""||pwd=="")
	{
		MessageBox("�˺���Ϣ����Ϊ��");
		return;
	}
	for(int i =0 ;i<read();i++)
	{
		if(strcmp(user,person[i].id)==0&&strcmp(person[i].pwd,pwd)==0&&person[i].status==0)
		{
			MessageBox("��֤�ɹ�");
			GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);//���ñ༭��
			return;
		}
	}
	MessageBox("��֤ʧ��");
}

int CGetDlg::read()//��ȡȫ�����ݵ�������
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


BOOL CGetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);//�༭�����

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

CString CGetDlg::getdate(CString id)//��ȡ�������
{
	int i=0;
	ifstream file;
	file.open("save.txt",ios::in);
	while(!file.eof())
	{
		file>>save[i].id>>save[i].pwd>>save[i].money>>save[i].date>>save[i].days;
		if(strcmp(save[i].id,id)==0)
		{

			savedate.Format("%s",save[i].date);

			saveday = save[i].days;

		}
		i++;
	}
	i--;
	file.close();
	return "";
}


void CGetDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CGetDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

// DialogDemo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AdPlayer.h"
#include "DialogDemo.h"
#include "afxdialogex.h"


// CDialogDemo �Ի���

IMPLEMENT_DYNAMIC(CDialogDemo, CDialogEx)

CDialogDemo::CDialogDemo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogDemo::IDD, pParent)
{

}

CDialogDemo::~CDialogDemo()
{
}

void CDialogDemo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogDemo, CDialogEx)
END_MESSAGE_MAP()


// CDialogDemo ��Ϣ�������


BOOL CDialogDemo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

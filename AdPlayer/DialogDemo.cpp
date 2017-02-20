// DialogDemo.cpp : 实现文件
//

#include "stdafx.h"
#include "AdPlayer.h"
#include "DialogDemo.h"
#include "afxdialogex.h"


// CDialogDemo 对话框

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


// CDialogDemo 消息处理程序


BOOL CDialogDemo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

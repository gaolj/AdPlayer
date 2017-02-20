// DialogAD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AdPlayer.h"
#include "DialogAD.h"
#include "afxdialogex.h"
#include <mshtml.h>


//////////////////////////////////////////////////////////////////////////


// CDialogAD �Ի���
__inline BOOL CS_GetApplicationPath(LPSTR lpszBuffer, DWORD dwBufferSize, LPSTR lpszSub)
{
	GetModuleFileName(NULL, lpszBuffer, dwBufferSize);
	LPSTR lptemp = strrchr(lpszBuffer, '\\');
	if (lptemp) lptemp[1] = '\0';
	if (lpszSub) {
		if ((strlen(lpszBuffer) + strlen(lpszSub)) > dwBufferSize) return FALSE;
		strcpy(lpszBuffer + strlen(lpszBuffer), lpszSub);
	}
	return TRUE;
}


//////////////////////////////////////////////////////////////////////////


// CDialogAD �Ի���

IMPLEMENT_DYNAMIC(CDialogAD, CDialogEx)

CDialogAD::CDialogAD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogAD::IDD, pParent)
{

}

CDialogAD::~CDialogAD()
{
	if(m_ie.m_hWnd == 0)
	{
		return;
	}else
	{
		m_ie.DestroyWindow();
	}
}

void CDialogAD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_ie);
}


BEGIN_MESSAGE_MAP(CDialogAD, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDialogAD ��Ϣ�������
// 
BOOL CDialogAD::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SendMessage(WM_SIZE);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ie.put_AddressBar(FALSE);
	m_ie.put_FullScreen(FALSE);
	m_ie.put_MenuBar(FALSE);
	m_ie.put_Offline(FALSE);
	m_ie.put_Resizable(TRUE);
	m_ie.put_Silent(TRUE);
	m_ie.put_StatusBar(FALSE);
	m_ie.put_TheaterMode(FALSE);//
	//m_ie.put_Top(100);
	m_ie.put_Visible(true);
	m_ie.put_MenuBar(FALSE);

	char buf[1024];
	CS_GetApplicationPath(buf, 1024, ".\\web\\gif\\ad.html");

	COleVariant varUrl(buf);

	m_ie.Navigate2(varUrl, NULL, NULL, NULL, NULL);
	//m_ie.En
	this->CenterWindow();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BEGIN_EVENTSINK_MAP(CDialogAD, CDialogEx)
	ON_EVENT(CDialogAD, IDC_EXPLORER1, 259, CDialogAD::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()


void CDialogAD::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	HRESULT hr = NULL;
	IHTMLElement *pHTMLElement = NULL;
	IHTMLBodyElement *pHTMLBody = NULL;
	IHTMLDocument2* pDocument = NULL;


	pDocument = (IHTMLDocument2*)m_ie.get_Document();
	if (!pDocument) goto EXIT;
	hr = pDocument->get_body(&pHTMLElement);
	if (!pHTMLElement) goto EXIT;
	if (FAILED(hr)) goto EXIT;
	hr = pHTMLElement->QueryInterface(IID_IHTMLBodyElement, (void**)&pHTMLBody);
	if (!pHTMLBody) goto EXIT;
	if (FAILED(hr)) goto EXIT;
	hr = pHTMLBody->put_scroll(L"no");
EXIT:
	if (pHTMLElement) pHTMLElement->Release();
	if (pHTMLBody) pHTMLBody->Release();
	if (pDocument) pDocument->Release();

	// ���� ����������

	//m_ctrlLoading.SetWindowText("");
	// ������ʾ��web�ؼ�
	CRect rc;
	GetClientRect(&rc);
	if (GetDlgItem(IDC_EXPLORER1) && GetDlgItem(IDC_EXPLORER1)->GetSafeHwnd())
	{
		GetDlgItem(IDC_EXPLORER1)->MoveWindow(rc.left, rc.top, rc.Width(), rc.Height());
	}
}


void CDialogAD::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	//m_ie.CenterWindow(this);
	// TODO: �ڴ˴������Ϣ����������
}


BOOL CDialogAD::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message == WM_KEYDOWN)
	{

		switch(pMsg->wParam)
		{
		case VK_ESCAPE:
		case VK_RETURN:
			return TRUE;
		}


	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

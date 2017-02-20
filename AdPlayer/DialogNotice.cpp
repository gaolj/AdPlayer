// DialogNotice.cpp : 实现文件
//

#include "stdafx.h"
#include "AdPlayer.h"
#include "DialogNotice.h"
#include "afxdialogex.h"
#include "player.h"
#include "CDXGraph.h"

// CDialogNotice 对话框

IMPLEMENT_DYNAMIC(CDialogNotice, CDialogEx)

CDialogNotice::CDialogNotice(CWnd* pParent /*=NULL*/,CPlayer* play)
	: CDialogEx(CDialogNotice::IDD, pParent)
{
	_play = play;
}

CDialogNotice::~CDialogNotice()
{
}

void CDialogNotice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogNotice, CDialogEx)
	ON_MESSAGE(WM_GRAPHNOTIFY, OnUserThreadend) 
	ON_MESSAGE(WM_GRAPHNOTIFY+1, OnUserPlayComplete) 
	ON_MESSAGE(WM_GRAPHNOTIFY+2, OnShowAd) 
END_MESSAGE_MAP()


// CDialogNotice 消息处理程序
LRESULT CDialogNotice::OnUserThreadend(WPARAM wParam, LPARAM lParam)
{
	TRACE("WM_USER_THREADEND message /n");

	_play->HandleEvent(wParam,lParam);
	
	return 0;
}   

LRESULT CDialogNotice::OnUserPlayComplete(WPARAM wParam, LPARAM lParam)
{
	// 	play.setPlayHwnd(/*hwnd*/m_hWnd);
	// 	play.setPlayFile("E:\\c++\\Player\\Debug\\test.avi",1);
	_play->play();

	return 0;
}

LRESULT CDialogNotice::OnShowAd(WPARAM wParam, LPARAM lParam)
{
	_play->adShow();
	return 0;
}


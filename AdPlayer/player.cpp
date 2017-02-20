// player.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "player.h"

#include "CDXGraph.h"
#include "DialogAD.h"
#include "DialogDemo.h"
#include "DialogNotice.h"


#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

// 函数导出
DLL_PLAY_API void  WINAPI setHwnd(HWND hwnd)
{
	auto play = CPlayer::Instance();
	play->setPlayHwnd(hwnd);
	play->setPlayFile("E:\\c++\\Player\\Debug\\test.avi");
	play->play();
}

DLL_PLAY_API void  WINAPI ReleaseAd()
{
	auto play = CPlayer::Instance();
	delete play;
	play = 0;
}

// 鼠标勾子 主要是捕获视频播放窗口的鼠标单击消息
LRESULT CALLBACK MouseProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	MSLLHOOKSTRUCT *pkbhs = (MSLLHOOKSTRUCT *)lParam;  
	char strMsg[100] = {0};  

	switch (nCode)  
	{  
	case HC_ACTION:  
		{  
			//鼠标左击  
			if(wParam == WM_LBUTTONDOWN)  
			{  
				CPlayer::Instance()->OnStnClickVideoWindows();
			}
		}  
	default:  
		break;  
	}  
	return CallNextHookEx (NULL, nCode, wParam, lParam);  
}



CPlayer::CPlayer()
	: _playerHwnd(NULL)
	, _mouseHook(0)
	, _playFile("")
	, _adFile("")
{
	//_CrtSetBreakAlloc(475);
	_sharedPlayPtr.reset(new CDXGraph,[](CDXGraph* ptr){ 
		ptr->Release(); delete ptr;});
	_sharedPlayPtr->Create();
}

CPlayer::~CPlayer()
{
	
	_sharedPlayPtr->SetNotifyWindow(NULL);
	_sharedPlayPtr->SetDisplayWindow(0);
	_sharedPlayPtr.reset();

	_playerHwnd = NULL;
	if(_mouseHook)
	{
		::UnhookWindowsHookEx(_mouseHook);
		_mouseHook = NULL;
	}
	if(_dlgNotice)
	{
		_dlgNotice->DestroyWindow();
		delete _dlgNotice;
		_dlgNotice = NULL;
	}
}


void CPlayer::OnStnClickVideoWindows()
{
	if(_dlgNotice->m_hWnd)
		PostMessage(_dlgNotice->m_hWnd,WM_USER+22,0,0);
}


void CPlayer::setPlayHwnd(HWND hwnd)
{
	if(hwnd)
	{
		_playerHwnd = hwnd;

		_dlgNotice = (new CDialogNotice(0,this));
		_dlgNotice->Create((UINT)(IDD_DIALOG_NOTICE));
		_dlgNotice->ShowWindow(SW_HIDE);
	}
}


HWND CPlayer::getPlayHwnd()
{
	return _playerHwnd;
}

void CPlayer::setPlayFile(const char* playFile)
{
	_playFile = playFile;
}

const char* CPlayer::getPlayFile()
{
	return _playFile.c_str();
}

void CPlayer::setAdFile(const char* adFile)
{
	_adFile = adFile;
}

const char* CPlayer::getAdFile()
{
	return _adFile.c_str();
}


void CPlayer::adShow()
{

	_sharedPlayPtr->Pause();
	CDialogAD dlg;

	dlg.DoModal();
	_sharedPlayPtr->Run();
}

bool CPlayer::play()
{

	if(_sharedPlayPtr)
	{
		_sharedPlayPtr->Stop();

		if(!_sharedPlayPtr->RenderFile(_playFile.c_str())) { _sharedPlayPtr.reset(); return false; }
		if(!_sharedPlayPtr->SetDisplayWindow(_playerHwnd)) { _sharedPlayPtr.reset(); return false; }
		if(!_sharedPlayPtr->SetNotifyWindow(_dlgNotice->m_hWnd)) { _sharedPlayPtr.reset(); return false; }
		if(!_sharedPlayPtr->Run()) { _sharedPlayPtr.reset(); return false; }

		auto hwnd = ::FindWindowEx(_playerHwnd, NULL, NULL, "ActiveMovie Window");

		auto id = GetWindowThreadProcessId(hwnd,NULL);

		if(id == 0) return false;

		if(!_mouseHook)
			_mouseHook=SetWindowsHookEx(WH_MOUSE,MouseProc,0,id); 

		return true;
	}
	return false;
}

void CPlayer::stop()
{
	if(_sharedPlayPtr)
	{
		if(!_sharedPlayPtr->IsStopped())
		{
			_sharedPlayPtr->Stop();
		}
	}
}

void CPlayer::pause()
{
	if(_sharedPlayPtr)
	{
		if(!_sharedPlayPtr->IsPaused())
		{
			_sharedPlayPtr->Pause();
		}
	}
}

void CPlayer::HandleEvent(WPARAM inWParam, LPARAM inLParam)
{
	if(_sharedPlayPtr)
	{
		_sharedPlayPtr->HandleEvent(inWParam,inLParam);
	}

}
#pragma once

#include <Windows.h>
#include <windef.h>

#include <string>
#include <vector>
#include <cstdint>
#include <thread>
#include <memory>

#ifdef PLAYER_EXPORTS
#define DLL_PLAY_API __declspec(dllexport)
#else
#define DLL_PLAY_API __declspec(dllimport)
#endif

class CDialogNotice;
class CDXGraph;

// 导出函数
DLL_PLAY_API void  WINAPI setHwnd(HWND hwnd);
DLL_PLAY_API void  WINAPI ReleaseAd();
class CPlayer
{
public:
	static CPlayer* Instance()
	{
		static CPlayer* pInstance = nullptr;

		if(!pInstance)
		{
			static CPlayer* instance = new CPlayer;
			pInstance = instance;
		}
		return pInstance;
	}

public:
	CPlayer();
	~CPlayer();

	void OnStnClickVideoWindows();												// 供勾子调用函数
public:
	void setAdFile(const char* adFile);											// 设置广告路径
	const char* getAdFile();													// 获取广告路径
	void adShow();																// 显示广告

public:
	void setPlayHwnd(HWND hwnd);												// 设置播放器窗口句柄
	HWND getPlayHwnd();															// 获取播放器窗口句柄
	void setPlayFile(const char* playFile);									// 设置播放器列表
	const char* getPlayFile();													// 获取播放文件

public:// 控制
	bool play();																// 播放
	void stop();																// 停止
	void pause();																// 暂停
	void HandleEvent(WPARAM inWParam, LPARAM inLParam);						// 播放完成时的消息返回

private:
	HWND _playerHwnd;															// 播放器窗口句柄
	std::string _playFile;														// 播放文件
	std::string _adFile;														// 广告文件
	HHOOK _mouseHook;															// 鼠标勾子 用以截获视频界面播放时点击消息

	std::shared_ptr<CDXGraph> _sharedPlayPtr;									// 播放器对象
	/*boost::shared_ptr<CDialogNotice>*/CDialogNotice* _dlgNotice;								// 用以接收播放结束通知的，广告弹出的消息 （利用其UI线程）
};
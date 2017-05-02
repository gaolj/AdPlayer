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

// ��������
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

	void OnStnClickVideoWindows();												// �����ӵ��ú���
public:
	void setAdFile(const char* adFile);											// ���ù��·��
	const char* getAdFile();													// ��ȡ���·��
	void adShow();																// ��ʾ���

public:
	void setPlayHwnd(HWND hwnd);												// ���ò��������ھ��
	HWND getPlayHwnd();															// ��ȡ���������ھ��
	void setPlayFile(const char* playFile);									// ���ò������б�
	const char* getPlayFile();													// ��ȡ�����ļ�

public:// ����
	bool play();																// ����
	void stop();																// ֹͣ
	void pause();																// ��ͣ
	void HandleEvent(WPARAM inWParam, LPARAM inLParam);						// �������ʱ����Ϣ����

private:
	HWND _playerHwnd;															// ���������ھ��
	std::string _playFile;														// �����ļ�
	std::string _adFile;														// ����ļ�
	HHOOK _mouseHook;															// ��깴�� ���Խػ���Ƶ���沥��ʱ�����Ϣ

	std::shared_ptr<CDXGraph> _sharedPlayPtr;									// ����������
	/*boost::shared_ptr<CDialogNotice>*/CDialogNotice* _dlgNotice;								// ���Խ��ղ��Ž���֪ͨ�ģ���浯������Ϣ ��������UI�̣߳�
};
﻿#pragma once

//---------------------------------------------------------------------

class Window
{
public:
	HWND m_hwnd = 0;
	HWND m_hwndContainer = 0;
public:
	virtual void init(HWND hwnd) = 0;
	static HWND getWindow(HWND hwndContainer);
	static void setWindow(HWND hwndContainer, HWND hwnd);
	static HWND createContainerWindow(HWND child, WNDPROC wndProc, LPCTSTR className);
	void resize(LPCRECT rc);
};

class AviUtlWindow : public Window
{
public:
	virtual void init(HWND hwnd);
	static LRESULT CALLBACK containerWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};

class ExeditWindow : public Window
{
public:
	virtual void init(HWND hwnd);
	static LRESULT CALLBACK containerWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};

class SettingDialog : public Window
{
public:
	virtual void init(HWND hwnd);
	void updateScrollBar();
	void scroll(int bar, WPARAM wParam);
	void recalcLayout();
	static LRESULT CALLBACK containerWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};

struct WindowPos
{
	static const int topLeft = 0;
	static const int topRight = 1;
	static const int bottomLeft = 2;
	static const int bottomRight = 3;

	static const int maxSize = 4;
};

struct LayoutMode
{
	static const int vertSplit = 0;
	static const int horzSplit = 1;

	static const int maxSize = 2;
};

struct VertSplit
{
	int m_center;
	int m_left;
	int m_right;
};

struct HorzSplit
{
	int m_center;
	int m_top;
	int m_bottom;
};

struct HotBorder
{
	static const int none = 0;

	static const int vertCenter = 1;
	static const int left = 2;
	static const int right = 3;

	static const int horzCenter = 4;
	static const int top = 5;
	static const int bottom = 6;
};

struct CommandID
{
	static const int ShowConfigDialog = 1000;
	static const int ImportLayout = 1001;
	static const int ExportLayout = 1002;
};

//---------------------------------------------------------------------

extern AviUtlInternal g_auin;
extern HINSTANCE g_instance;
extern HWND g_singleWindow;
extern HTHEME g_theme;
extern WNDPROC g_aviutlWindowProc;
extern WNDPROC g_exeditWindowProc;

extern AviUtlWindow g_aviutlWindow;
extern ExeditWindow g_exeditWindow;
extern SettingDialog g_settingDialog;

extern Window* g_windowArray[WindowPos::maxSize];
extern int g_layoutMode;
extern VertSplit g_vertSplit;
extern HorzSplit g_horzSplit;
extern int g_hotBorder;

extern int g_borderWidth;
extern int g_captionHeight;
extern COLORREF g_fillColor;
extern COLORREF g_borderColor;
extern COLORREF g_hotBorderColor;

//---------------------------------------------------------------------

HWND createSingleWindow();
void normalizeLayoutHorzSplit();
void normalizeLayoutVertSplit();
void recalcLayoutHorzSplit();
void recalcLayoutVertSplit();
void recalcLayout();
LRESULT CALLBACK singleWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK aviutlWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK exeditWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

HRESULT loadConfig();
HRESULT loadConfig(LPCWSTR fileName, BOOL _import);
HRESULT loadLayout(const MSXML2::IXMLDOMElementPtr& element);

HRESULT saveConfig();
HRESULT saveConfig(LPCWSTR fileName, BOOL _export);
HRESULT saveLayout(const MSXML2::IXMLDOMElementPtr& element);

//---------------------------------------------------------------------

DECLARE_HOOK_PROC(LRESULT, WINAPI, SettingDialogProc, (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam));
DECLARE_HOOK_PROC(HWND, WINAPI, CreateWindowExA, (DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, int x, int y, int w, int h, HWND parent, HMENU menu, HINSTANCE instance, LPVOID param));

//---------------------------------------------------------------------

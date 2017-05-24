// cpages.h : header file
//

struct PageData {

	float	params[16];

	TXHOSTINFO	*pHost;

	BOOL	bLocked;
	
	float fields[16];

};

LRESULT	CALLBACK ControlsPageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT	CALLBACK InfoPageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

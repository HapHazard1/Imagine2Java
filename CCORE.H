// ccore.h : main header file for the DLL "core"
//

extern HINSTANCE	hInst;

/////////////////////////////////////////////////////////////////////////////

// These are the functions that the 'ccore' module requires from
// each "implementation" derived from it.

extern LONG	(*pInit)();			// init this to NULL if no 'Init' func.
extern void	(*pCleanup)();		// init this to NULL if no 'Cleanup' func.
extern void	Work(float *pParams, PATCH *pPatch, VECTOR *pPosn, TFORM *pAxes);
extern float	fParams[16];	// 16 default parameters
extern TFORM	tfAxes;			// default (relative) texture axes
extern char	szName[18];			// NULL terminated name for list box
extern unsigned char	ubParamFlags[16];	// default flags (TXTF_SCL, etc.)
extern LPARAM lCreateArg;		// init this to something ... 0, at least.
extern void *CreatePages(LPARAM lCreateArg, TXHOSTINFO *pHost, float *params);
extern void ReleasePages(void *pClientData);
extern void StoreParams(void *pClientData, float *params);

/////////////////////////////////////////////////////////////////////////////

// This is the "main entry point" exported to Imagine by 'ccore'.

extern __declspec(dllexport) LONG InquireTexture(int vers, int type);

/////////////////////////////////////////////////////////////////////////////

// These functions are provided by 'ccore' for use by the implementations
// of the 'CreatePages()' and 'ReleasePages()' routines ... they hook the
// creation callback function for the property pages (with 'PSPCallback')

extern BOOL AddPSPage(TXHOSTINFO *pHost, LPCTSTR pszTemplate,
	DLGPROC pDlgProc, void *pCallbackParam, void *pClientPageData);
extern void RemovePSPage(TXHOSTINFO *pHost, void *pClientPageData);

extern UINT CALLBACK PSPCallback(HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp);

extern void	*pNextPageData;

/////////////////////////////////////////////////////////////////////////////
// Color button helper routines

// void SubclassColorButton(TXHOSTINFO *pHost, HWND hwndPPg, UINT nIDBtn, COLORREF clrVal);
// void GetButtonColor(TXHOSTINFO *pHost, HWND hwndPPg, UINT nIDBtn, COLORREF *clrVal);
// void SetButtonColor(TXHOSTINFO *pHost, HWND hwndPPg, UINT nIDBtn, COLORREF clrVal);
// void OnColorButton(TXHOSTINFO *pHost, HWND hwndPPg, UINT nIDBtn, COLORREF *clrVal);

/////////////////////////////////////////////////////////////////////////////

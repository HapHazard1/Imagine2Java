// ccore.c : Implementation routines for the DLL "core".
//

#include <windows.h>
#include <commctrl.h>

#include "imdefs.h"
#include "txdefs.h"
#include "ccore.h"

HINSTANCE	hInst;
void	*pNextPageData;

__declspec(dllexport) int APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
   
	if (dwReason == DLL_PROCESS_ATTACH) {

		hInst = hInstance;

		InitCommonControls();
		return TRUE;

	} else if (dwReason == DLL_PROCESS_DETACH) {
    // MessageBox(NULL,"DLLMain()","Process Detach",MB_OK); // for debugging
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// The exported "InquireTexture" routine

LONG	table[] = {
	0x54585449,			    // for surface textures
//	0x5458544c,			  // for lighting textures
	0L,					        // filled in with 'pinit' - initialization func.
	0L,					        // filled in with 'pcleanup' - initialization func.
	(LONG)Work,			    // work function
	(LONG)szName,		    // "nice" name for user (17 chars max, + '\0')
	(LONG)ubParamFlags,	// array of byte parameter flags - 
	(LONG)fParams,		  // array of 16 default "REAL*4" parameters
	(LONG)&tfAxes,		  // pointer to default axis parameters
	0L,					        // filled in with 'lCreateArg', for CreatePages()
	(LONG)CreatePages,	// pointer to property page creation function
	(LONG)ReleasePages,	// pointer to property page destroy function
	(LONG)StoreParams,	// pointer to function to store "return" data
};

__declspec(dllexport) LONG InquireTexture(int vers, int type) {

	if (vers != 0x70 || type != 1)
		return 0;

	table[1] = (LONG)pInit;
	table[2] = (LONG)pCleanup;
	table[8] = lCreateArg;

	return (LONG)table;
}

/////////////////////////////////////////////////////////////////////////////
// CPropertyPage helper routines

UINT CALLBACK PSPCallback(HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp) {
	if (uMsg == PSPCB_CREATE)
		pNextPageData = (void *)ppsp->lParam;

	return TRUE;
}

BOOL AddPSPage(TXHOSTINFO *pHost, LPCTSTR pszTemplate,
	DLGPROC pDlgProc, void *pCallbackParam, void *pClientPageData) {
	PROPSHEETPAGE	psp;

	psp.dwSize = sizeof(PROPSHEETPAGE);
	psp.dwFlags = PSP_DEFAULT | PSP_USECALLBACK;
	psp.hInstance = hInst;
	psp.pszTemplate = pszTemplate;
	psp.pszIcon = NULL;
	psp.pszTitle = NULL;
	psp.pfnDlgProc = pDlgProc;
	psp.lParam = (LPARAM)pCallbackParam;
	psp.pfnCallback = PSPCallback;
	psp.pcRefParent = NULL;

	return (*pHost->pAddPage)(pHost->pHostData, &psp, pClientPageData);
}

void RemovePSPage(TXHOSTINFO *pHost, void *pClientPageData) {
	(*pHost->pRemovePage)(pHost->pHostData, pClientPageData);
}



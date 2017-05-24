// cpages.c : implementation file
//

#include <windows.h>
#include <commctrl.h>
#include <stdio.h>	// for sprintf()

#include "imdefs.h"
#include "txdefs.h"

#include "ccore.h"

#include "cresourc.h"
#include "cpages.h"

/////////////////////////////////////////////////////////////////////////////
// Imagine interface functions

LPARAM	lCreateArg;	// required for 'ccore.c'

void *CreatePages(LPARAM lCreateArg, TXHOSTINFO *pHost, float *params) {
  int x;

	struct PageData	*pPageData;

  pPageData = malloc(sizeof(struct PageData));
	if (!pPageData)
		return NULL;

	memcpy(pPageData->params, params, 16*sizeof(float));

	pPageData->pHost = pHost;

	// Copy defaults into page variables
	for (x=0; x<16; x++) {
	   pPageData->fields[x] = params[x];
	}
	
	if (AddPSPage(pHost, MAKEINTRESOURCE(IDD_CONTROLS),
       ControlsPageProc, pPageData, MAKEINTRESOURCE(IDD_CONTROLS))) {
		if (AddPSPage(pHost, MAKEINTRESOURCE(IDD_INFO),
			 InfoPageProc, pPageData, MAKEINTRESOURCE(IDD_INFO)))	{
				return pPageData;
		}
		RemovePSPage(pHost, MAKEINTRESOURCE(IDD_CONTROLS));
	}

	free(pPageData);

	return NULL;
}

void ReleasePages(void *pClientData) {
	free(pClientData);
}

void StoreParams(void *pClientData, float *params) {
  int x;
	struct PageData	*pPageData = (struct PageData *)pClientData;

  for (x=0; x<16; x++) {
    pPageData->params[x] = pPageData->fields[x];
  }
	
	memcpy(params, pPageData->params, 16 * sizeof(float));
}

//  --->  Property Page Code <----

LRESULT	CALLBACK ControlsPageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  int x;
	struct PageData *pData;
	
	int edits[16] = {IDC_EDIT_01, IDC_EDIT_02, IDC_EDIT_03, IDC_EDIT_04,
	                 IDC_EDIT_05, IDC_EDIT_06, IDC_EDIT_07, IDC_EDIT_08,
	                 IDC_EDIT_09, IDC_EDIT_10, IDC_EDIT_11, IDC_EDIT_12,
	                 IDC_EDIT_13, IDC_EDIT_14, IDC_EDIT_15, IDC_EDIT_16};

	if (pNextPageData) {
		pData = (struct PageData *)pNextPageData;
		pNextPageData = NULL;
		SetWindowLong(hwnd, DWL_USER, (LONG)pData);
	} else {
		pData = (struct PageData *)GetWindowLong(hwnd, DWL_USER);
	}

	switch (uMsg) {
    case WM_NOTIFY: {
      NMHDR  *pnmh = (NMHDR *)lParam;
      switch(pnmh->code) {
        case PSN_SETACTIVE: {
          char  szTmp[64];

          pData->bLocked = TRUE;

          for (x=0; x<16; x++) {
            sprintf(szTmp, "%f", pData->fields[x]);
            SetDlgItemText(hwnd, edits[x], szTmp);
          }

          pData->bLocked = FALSE;

          SetWindowLong(hwnd, DWL_MSGRESULT, 0);
          return TRUE;
        }
        break;
        
        case PSN_KILLACTIVE: {
          char  szTmp[64];
          HWND  hwndCtrl;
          float  fTmp;

          for (x=0; x<16; x++) {
            szTmp[64] = 0;
   
            hwndCtrl = GetDlgItem(hwnd, edits[x]);
            GetWindowText(hwndCtrl, szTmp, 63);
            if (sscanf(szTmp, "%f", &fTmp) != 1) {
              MessageBox(hwnd, "Please enter a number.", NULL, MB_OK);
              SetFocus(hwndCtrl);
              SetWindowLong(hwnd, DWL_MSGRESULT, TRUE);
              return TRUE;
            }

            pData->fields[x] = fTmp;
          }

          SetWindowLong(hwnd, DWL_MSGRESULT, FALSE);
          return TRUE;
        }
        break;
      }
    }

    // else, "not handled"
    return FALSE;

    case WM_COMMAND:
      if (HIWORD(wParam) == EN_UPDATE) {
        if (!pData->bLocked) {
          switch(LOWORD(wParam)) {
            case IDC_EDIT_01:
            case IDC_EDIT_02:
            case IDC_EDIT_03:
            case IDC_EDIT_04:
            case IDC_EDIT_05:
            case IDC_EDIT_06:
            case IDC_EDIT_07:
            case IDC_EDIT_08:
            case IDC_EDIT_09:
            case IDC_EDIT_10:
            case IDC_EDIT_11:
            case IDC_EDIT_12:
            case IDC_EDIT_13:
            case IDC_EDIT_14:
            case IDC_EDIT_15:
            case IDC_EDIT_16:
              SendMessage(GetParent(hwnd), PSM_CHANGED, (WPARAM)hwnd, 0);
              return 0;
          }
        }
        break;
      }

      // else default to DefWindowProc
      break;

    case WM_HSCROLL:
    case WM_VSCROLL:
      // else default to DefWindowProc
      break;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////
// InfoPage property page WindowProc

LRESULT  CALLBACK InfoPageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  struct PageData *pData;

  if (pNextPageData) {
    pData = (struct PageData *)pNextPageData;
    pNextPageData = NULL;
    SetWindowLong(hwnd, DWL_USER, (LONG)pData);
  } else {
    pData = (struct PageData *)GetWindowLong(hwnd, DWL_USER);
  }

  switch (uMsg) {
    case WM_INITDIALOG: {
      HGLOBAL  hInfoRsc;
      char  *pszInfo;
      HRSRC hRsc;

      hRsc = FindResource(hInst, MAKEINTRESOURCE(IDS_INFOTEXT), "TEXT");
      if (!hRsc) {
        MessageBox(GetParent(hwnd), "Error loading info text", NULL, MB_OK);
        EndDialog(hwnd, IDCANCEL);
        return TRUE;
      }

      hInfoRsc = LoadResource(hInst, hRsc);
      if (!hInfoRsc) {
        MessageBox(GetParent(hwnd), "Error loading info text", NULL, MB_OK);
        EndDialog(hwnd, IDCANCEL);
        return TRUE;
      }

      pszInfo = (char *)LockResource(hInfoRsc);
      if (!pszInfo) {
        FreeResource(hInfoRsc);
        MessageBox(GetParent(hwnd), "Error locking info text", NULL, MB_OK);
        EndDialog(hwnd, IDCANCEL);
        FreeResource(hInfoRsc);
        return TRUE;
      }

      SetDlgItemText(hwnd, IDC_EDIT, pszInfo);

      UnlockResource(hInfoRsc);
      FreeResource(hInfoRsc);

      return TRUE;
    }
    break;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

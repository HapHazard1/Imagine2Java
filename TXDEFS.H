
typedef struct _txhostinfo {
	void	*pHostData;
	BOOL	(*pAddPage)(void *pHostData, PROPSHEETPAGE *ppsp, void *pClientObject);
	void	(*pRemovePage)(void *pHostData, void *pClientObject);
	void	*(*pGetActivePage)(void *pHostData);
	LONG	(*pGetPageCount)(void *pHostData);
}	TXHOSTINFO, *LPTXHOSTINFO;

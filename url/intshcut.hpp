/*
 * intshcut.hpp - Internet Shortcut class implementation description.
 */


/* Types
 ********/

// InternetShortcut flags

typedef enum _intshcutflags
{
   INTSHCUT_FL_DIRTY    = 0x0001,

   ALL_INTSHCUT_FLAGS   = INTSHCUT_FL_DIRTY
}
INTSHCUTFLAGS;

// InternetShortcut Shell extension

class InternetShortcut : public RefCount,
                         public IDataObject,
                         public IExtractIcon,
                         public INewShortcutHook,
                         public IPersistFile,
                         public IPersistStream,
                         public IShellExecuteHook,
                         public IShellExtInit,
                         public IShellLink,
                         public IShellPropSheetExt,
                         public IUniformResourceLocator
{
private:
   DWORD m_dwFlags;
   PSTR m_pszFile;
   PSTR m_pszURL;
   PSTR m_pszIconFile;
   int m_niIcon;
   PSTR m_pszWorkingDirectory;
   int m_nShowCmd;
   PSTR m_pszFolder;
   WORD m_wHotkey;

   // data transfer methods

   DWORD STDMETHODCALLTYPE GetFileContentsSize(void);
   HRESULT STDMETHODCALLTYPE TransferUniformResourceLocator(PFORMATETC pfmtetc, PSTGMEDIUM pstgmed);
   HRESULT STDMETHODCALLTYPE TransferText(PFORMATETC pfmtetc, PSTGMEDIUM pstgmed);
   HRESULT STDMETHODCALLTYPE TransferFileGroupDescriptor(PFORMATETC pfmtetc, PSTGMEDIUM pstgmed);
   HRESULT STDMETHODCALLTYPE TransferFileContents(PFORMATETC pfmtetc, PSTGMEDIUM pstgmed);

   // protocol registration methods

   HRESULT STDMETHODCALLTYPE RegisterProtocolHandler(HWND hwndParent, PSTR pszAppBuf, UINT ucAppBufLen);

public:
   InternetShortcut(OBJECTDESTROYEDPROC);
   ~InternetShortcut(void);

   // IDataObject methods

   HRESULT STDMETHODCALLTYPE GetData(PFORMATETC pfmtetcIn, PSTGMEDIUM pstgmed);
   HRESULT STDMETHODCALLTYPE GetDataHere(PFORMATETC pfmtetc, PSTGMEDIUM pstgpmed);
   HRESULT STDMETHODCALLTYPE QueryGetData(PFORMATETC pfmtetc);
   HRESULT STDMETHODCALLTYPE GetCanonicalFormatEtc(PFORMATETC pfmtetcIn, PFORMATETC pfmtetcOut);
   HRESULT STDMETHODCALLTYPE SetData(PFORMATETC pfmtetc, PSTGMEDIUM pstgmed, BOOL bRelease);
   HRESULT STDMETHODCALLTYPE EnumFormatEtc(DWORD dwDirection, PIEnumFORMATETC *ppienumFormatEtc);
   HRESULT STDMETHODCALLTYPE DAdvise(PFORMATETC pfmtetc, DWORD dwAdviseFlags, PIAdviseSink piadvsink, PDWORD pdwConnection);
   HRESULT STDMETHODCALLTYPE DUnadvise(DWORD dwConnection);
   HRESULT STDMETHODCALLTYPE EnumDAdvise(PIEnumSTATDATA *ppienumStatData);

   // IExtractIcon methods

   HRESULT STDMETHODCALLTYPE GetIconLocation(UINT uFlags, PSTR pszIconFile, UINT ucchMax, PINT pniIcon, PUINT puFlags);
   HRESULT STDMETHODCALLTYPE Extract(PCSTR pcszFile, UINT uIconIndex, PHICON phiconLarge, PHICON phiconSmall, UINT ucIconSize);

   // INewShortcutHook methods

   HRESULT STDMETHODCALLTYPE SetReferent(PCSTR pcszReferent, HWND hwndParent);
   HRESULT STDMETHODCALLTYPE GetReferent(PSTR pszReferent, int ncReferentBufLen);
   HRESULT STDMETHODCALLTYPE SetFolder(PCSTR pcszFolder);
   HRESULT STDMETHODCALLTYPE GetFolder(PSTR pszFolder, int ncFolderBufLen);
   HRESULT STDMETHODCALLTYPE GetName(PSTR pszName, int ncNameBufLen);
   HRESULT STDMETHODCALLTYPE GetExtension(PSTR pszExtension, int ncExtensionBufLen);

   // IPersist methods

   HRESULT STDMETHODCALLTYPE GetClassID(PCLSID pclsid);

   // IPersistFile methods

   HRESULT STDMETHODCALLTYPE IsDirty(void);
   HRESULT STDMETHODCALLTYPE Save(LPCOLESTR pcwszFileName, BOOL bRemember);
   HRESULT STDMETHODCALLTYPE SaveCompleted(LPCOLESTR pcwszFileName);
   HRESULT STDMETHODCALLTYPE Load(LPCOLESTR pcwszFileName, DWORD dwMode);
   HRESULT STDMETHODCALLTYPE GetCurFile(LPOLESTR *ppwszFileName);

   // IPersistStream methods

   HRESULT STDMETHODCALLTYPE Save(PIStream pistr, BOOL bClearDirty);
   HRESULT STDMETHODCALLTYPE Load(PIStream pistr);
   HRESULT STDMETHODCALLTYPE GetSizeMax(PULARGE_INTEGER pcbSize);

   // IShellExecuteHook methods

   HRESULT STDMETHODCALLTYPE Execute(LPSHELLEXECUTEINFOA pei);

   // IShellExtInit methods

   HRESULT STDMETHODCALLTYPE Initialize(PCITEMIDLIST pcidlFolder, PIDataObject pidobj, HKEY hkeyProgID);

   // IShellLink methods

   HRESULT STDMETHODCALLTYPE SetPath(PCSTR pcszPath);
   HRESULT STDMETHODCALLTYPE GetPath(PSTR pszFile, int ncFileBufLen, PWIN32_FIND_DATA pwfd, DWORD dwFlags);
   HRESULT STDMETHODCALLTYPE SetRelativePath(PCSTR pcszRelativePath, DWORD dwReserved);
   HRESULT STDMETHODCALLTYPE SetIDList(LPCITEMIDLIST pcidl);
   HRESULT STDMETHODCALLTYPE GetIDList(LPITEMIDLIST *ppidl);
   HRESULT STDMETHODCALLTYPE SetDescription(PCSTR pcszDescription);
   HRESULT STDMETHODCALLTYPE GetDescription(PSTR pszDescription, int ncDesciptionBufLen);
   HRESULT STDMETHODCALLTYPE SetArguments(PCSTR pcszArgs);
   HRESULT STDMETHODCALLTYPE GetArguments(PSTR pszArgs, int ncArgsBufLen);
   HRESULT STDMETHODCALLTYPE SetWorkingDirectory(PCSTR pcszWorkingDirectory);
   HRESULT STDMETHODCALLTYPE GetWorkingDirectory(PSTR pszWorkingDirectory, int ncbLen);
   HRESULT STDMETHODCALLTYPE SetHotkey(WORD wHotkey);
   HRESULT STDMETHODCALLTYPE GetHotkey(PWORD pwHotkey);
   HRESULT STDMETHODCALLTYPE SetShowCmd(int nShowCmd);
   HRESULT STDMETHODCALLTYPE GetShowCmd(PINT pnShowCmd);
   HRESULT STDMETHODCALLTYPE SetIconLocation(PCSTR pcszIconFile, int niIcon);
   HRESULT STDMETHODCALLTYPE GetIconLocation(PSTR pszIconFile, int ncbLen, PINT pniIcon);
   HRESULT STDMETHODCALLTYPE Resolve(HWND hwnd, DWORD dwFlags);

   // IShellPropSheetExt methods

   HRESULT STDMETHODCALLTYPE AddPages(LPFNADDPROPSHEETPAGE pfnAddPage, LPARAM lParam);
   HRESULT STDMETHODCALLTYPE ReplacePage(UINT uPageID, LPFNADDPROPSHEETPAGE pfnReplaceWith, LPARAM lParam);

   // IUniformResourceLocator methods

   HRESULT STDMETHODCALLTYPE SetURL(PCSTR pcszURL, DWORD dwFlags);
   HRESULT STDMETHODCALLTYPE GetURL(PSTR *ppszURL);
   HRESULT STDMETHODCALLTYPE InvokeCommand(PURLINVOKECOMMANDINFO purlici);

   // IUnknown methods

   HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, PVOID *ppvObj);
   ULONG STDMETHODCALLTYPE AddRef(void);
   ULONG STDMETHODCALLTYPE Release(void);

   // other methods

   HRESULT STDMETHODCALLTYPE SaveToFile(PCSTR pcszFile, BOOL bRemember);
   HRESULT STDMETHODCALLTYPE LoadFromFile(PCSTR pcszFile, BOOL bRemember);
   HRESULT STDMETHODCALLTYPE GetCurFile(PSTR pszFile, UINT ucbLen);
   HRESULT STDMETHODCALLTYPE Dirty(BOOL bDirty);

   HRESULT STDMETHODCALLTYPE GetIconLocation(
       UINT   uFlags,
       LPWSTR szIconFile,
       UINT   cchMax,
       int   * piIndex,
       UINT  * pwFlags)
   {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE Extract(
       LPCWSTR pszFile,
       UINT   nIconIndex,
       HICON   *phiconLarge,
       HICON   *phiconSmall,
       UINT    nIconSize)
   {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE Execute (THIS_ LPSHELLEXECUTEINFOW pei)
   {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE SetReferent(THIS_ LPCWSTR pcszReferent, HWND hwnd) {return E_FAIL;}
   HRESULT STDMETHODCALLTYPE GetReferent(THIS_ LPWSTR pszReferent, int cchReferent) {return E_FAIL;}
   HRESULT STDMETHODCALLTYPE SetFolder(THIS_ LPCWSTR pcszFolder) {return E_FAIL;}
   HRESULT STDMETHODCALLTYPE GetFolder(THIS_ LPWSTR pszFolder, int cchFolder) {return E_FAIL;}
   HRESULT STDMETHODCALLTYPE GetName(THIS_ LPWSTR pszName, int cchName) {return E_FAIL;}
   HRESULT STDMETHODCALLTYPE GetExtension(THIS_ LPWSTR pszExtension, int cchExtension) {return E_FAIL;}

   virtual HRESULT STDMETHODCALLTYPE GetPath( 
       /* [size_is][out] */ LPWSTR pszFile,
       /* [in] */ int cch,
       /* [full][out][in] */ WIN32_FIND_DATAW *pfd,
       /* [in] */ DWORD fFlags){return E_FAIL;}

   HRESULT STDMETHODCALLTYPE GetDescription( 
       /* [size_is][out] */ LPWSTR pszName,
       int cch) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE SetDescription( 
       /* [in] */ LPCWSTR pszName) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE GetWorkingDirectory( 
       /* [size_is][out] */ LPWSTR pszDir,
       int cch) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE SetWorkingDirectory( 
       /* [in] */ LPCWSTR pszDir) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE GetArguments( 
       /* [size_is][out] */ LPWSTR pszArgs,
       int cch) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE SetArguments( 
       /* [in] */ LPCWSTR pszArgs) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE GetIconLocation( 
       /* [size_is][out] */ LPWSTR pszIconPath,
       /* [in] */ int cch,
       /* [out] */ int *piIcon) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE SetIconLocation( 
       /* [in] */ LPCWSTR pszIconPath,
       /* [in] */ int iIcon) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE SetRelativePath( 
       /* [in] */ LPCWSTR pszPathRel,
       /* [in] */ DWORD dwReserved) {return E_FAIL;}

   HRESULT STDMETHODCALLTYPE SetPath( 
       /* [in] */ LPCWSTR pszFile) {return E_FAIL;}

#ifdef DEBUG

   void STDMETHODCALLTYPE Dump(void);

#endif

   // friends

#ifdef DEBUG

   friend BOOL IsValidPCInternetShortcut(const InternetShortcut *pcintshcut);

#endif

};
DECLARE_STANDARD_TYPES(InternetShortcut);


/* Global Constants
 *******************/

// intshcut.cpp

extern const int g_nDefaultShowCmd;


/* Prototypes
 *************/

// intshcut.cpp

extern HRESULT IsProtocolRegistered(PCSTR pcszProtocol);
extern HRESULT ValidateURL(PCSTR pcszURL);
extern HRESULT ValidateWorkingDirectory(PCSTR pcszWorkingDirectory);


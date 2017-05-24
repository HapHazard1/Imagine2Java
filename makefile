# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
#CFG=cproj - Win32 Debug
CFG=cproj - Win32 Release
!MESSAGE No configuration specified.  Defaulting to cproj - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "cproj - Win32 Release" && "$(CFG)" != "cproj - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "cproj.mak" CFG="cproj - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cproj - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "cproj - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "cproj - Win32 Debug"
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "cproj - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "cproj___"
# PROP BASE Intermediate_Dir "cproj___"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseC"
# PROP Intermediate_Dir "ReleaseC"
# PROP Target_Dir ""
OUTDIR=.\ReleaseC
INTDIR=.\ReleaseC

ALL : "$(OUTDIR)\Im2Java.itx"

CLEAN : 
   -@erase "$(INTDIR)\Im2Java.obj"
	-@erase "$(INTDIR)\ccore.obj"
	-@erase "$(INTDIR)\cpages.obj"
	-@erase "$(INTDIR)\Im2Java.res"
	-@erase "$(OUTDIR)\Im2Java.exp"
	-@erase "$(OUTDIR)\Im2Java.itx"
	-@erase "$(OUTDIR)\Im2Java.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Zp2 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /Zp2 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\ReleaseC/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Im2Java.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Im2Java.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"ReleaseC/cproj.itx"
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 jvm.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/Im2Java.pdb" /machine:I386 /out:"$(OUTDIR)/Im2Java.itx"\
 /implib:"$(OUTDIR)/Im2Java.lib" 
LINK32_OBJS= \
	"$(INTDIR)\Im2Java.obj" \
	"$(INTDIR)\ccore.obj" \
	"$(INTDIR)\cpages.obj" \
	"$(INTDIR)\Im2Java.res"

"$(OUTDIR)\Im2Java.itx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "cproj - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "cproj__0"
# PROP BASE Intermediate_Dir "cproj__0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugC"
# PROP Intermediate_Dir "DebugC"
# PROP Target_Dir ""
OUTDIR=.\DebugC
INTDIR=.\DebugC

ALL : "$(OUTDIR)\Im2Java.itx"

CLEAN : 
	-@erase "$(INTDIR)\Im2Java.obj"
	-@erase "$(INTDIR)\ccore.obj"
	-@erase "$(INTDIR)\cpages.obj"
	-@erase "$(INTDIR)\Im2Java.res"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Im2Java.exp"
	-@erase "$(OUTDIR)\Im2Java.itx"
	-@erase "$(OUTDIR)\Im2Java.lib"
	-@erase "$(OUTDIR)\Im2Java.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Zp2 /MTd /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /Zp2 /MTd /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\DebugC/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Im2Java.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Im2Java.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:no /debug /machine:I386 /out:"DebugC/cproj.itx"
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 jvm.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/Im2Java.pdb" /debug /machine:I386 /out:"$(OUTDIR)/Im2Java.itx"\
 /implib:"$(OUTDIR)/Im2Java.lib" 
LINK32_OBJS= \
	"$(INTDIR)\Im2Java.obj" \
	"$(INTDIR)\ccore.obj" \
	"$(INTDIR)\cpages.obj" \
	"$(INTDIR)\Im2Java.res"

"$(OUTDIR)\Im2Java.itx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "cproj - Win32 Release"
# Name "cproj - Win32 Debug"

!IF  "$(CFG)" == "cproj - Win32 Release"

!ELSEIF  "$(CFG)" == "cproj - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ccore.c
DEP_CPP_CCORE=\
	".\ccore.h"\
	".\imdefs.h"\
	".\txdefs.h"\
	

"$(INTDIR)\ccore.obj" : $(SOURCE) $(DEP_CPP_CCORE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\cpages.c
DEP_CPP_CPAGE=\
	".\ccore.h"\
	".\cpages.h"\
	".\imdefs.h"\
	".\txdefs.h"\
	

"$(INTDIR)\cpages.obj" : $(SOURCE) $(DEP_CPP_CPAGE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Im2Java.rc
DEP_RSC_CPROJ=\
	".\Im2Java.rc2"\
	".\Im2Java.txt"\
	

"$(INTDIR)\Im2Java.res" : $(SOURCE) $(DEP_RSC_CPROJ) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Im2Java.c
DEP_CPP_CAGAT=\
	".\Im2Java.c"\
	".\imdefs.h"\
	".\txdefs.h"\
	

"$(INTDIR)\Im2Java.obj" : $(SOURCE) $(DEP_CPP_CAGAT) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################

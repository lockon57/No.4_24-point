# Microsoft Developer Studio Project File - Name="Point24" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Point24 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Point24.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Point24.mak" CFG="Point24 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Point24 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Point24 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Point24 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Point24 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Point24 - Win32 Release"
# Name "Point24 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Express1.cpp
# End Source File
# Begin Source File

SOURCE=.\Point24.cpp
# End Source File
# Begin Source File

SOURCE=.\Point24.rc
# End Source File
# Begin Source File

SOURCE=.\Point24Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Value.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Express1.h
# End Source File
# Begin Source File

SOURCE=.\Point24.h
# End Source File
# Begin Source File

SOURCE=.\Point24Dlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Value.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fp9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ht9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\htt9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mh9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Point24.ico
# End Source File
# Begin Source File

SOURCE=.\res\Point24.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section Point24 : {D8A54ED7-49EF-11D3-860F-C95273917943}
# 	2:11:Express.cpp:Express1.cpp
# 	2:9:Express.h:Express1.h
# 	2:22:TYPEDEF: CMapVariabile:CMapVariabile
# 	2:18:CLASS: CExpression:CExpression
# 	2:19:Application Include:Point24.h
# End Section

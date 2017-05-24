@echo off
call d:\devtools\msvs_2010\vc\bin\vcvars32.bat

set INCLUDE=%INCLUDE%;d:\devtools\jdks\jdk1.6_32bit\include;d:\devtools\jdks\jdk1.6_32bit\include\win32

set LIBPATH=%LIBPATH%;d:\devtools\jdks\jdk1.6_32bit\lib

set LIB=%LIB%;d:\devtools\jdks\jdk1.6_32bit\lib

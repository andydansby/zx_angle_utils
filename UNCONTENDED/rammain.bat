SET PATH=c:\z88dk199c;c:\z88dk199c\bin;c:\z88dk199c\lib\;c:\z88dk199c\lib\clibs;c:\z88dk199c\lib\config

rem compile to a TAP file

rem --------------------------------------------------------------
@rem sccz80
rem zcc +zx -vn -m -startup=30 -clib=new ramALL.o -o compiled -pragma-include:zpragma.inc

@rem zSDCC
@rem -startup= 1, 5,
zcc +zx -vn -m -startup=9 -lm -clib=sdcc_iy ramALL.o -o compiled -pragma-include:zpragma.inc
rem check above for errors
rem --------------------------------------------------------------



@rem have at the end
call cleanup.bat
call beep.bat

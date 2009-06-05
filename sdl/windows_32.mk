
CC=cl
LINK32=link.exe

CFLAGS=\
      /nologo\
      /c /TP /Od /Oy /GL /W3\
      /I"..\..\include"  /I".\include" /I"."

LINK32DLL_FLAGS=\
 /nologo /dll /LTCG /incremental:no\
 /pdb:"konoha.pdb" /machine:I386 /out:"math_windows_32.dll"\
 /implib:"math_windows_32.lib"

.PHONY: all
all: math_windows_32.dll

math.obj : "math.c"
      $(CC) $(CFLAGS) /Fo"math.obj" "math.c"

math_windows_32.dll : math.obj
      $(LINK32) $(LINK32DLL_FLAGS) "..\..\build\konoha.lib" math.obj

.PHONY: clean
clean :
    -@erase /Q *.obj


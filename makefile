CC         = icc
CINCLUDE   = -I .\src
CFLAGS     = -Gd- -Se -Re -Ss -Ms -Gm+ -Ti-
LFLAGS     = /NOE /NOD /ALIGN:16 /EXEPACK
LINK       = icc /B"$(LFLAGS)" $(CFLAGS) -Fe
OS2386_LIB = os2386.lib
MTLIB      = cppom30.lib
DLLIBS     = feconfig.lib
MTLIBS     = $(MTLIB) + $(OS2386_LIB)
CFLAGS     = $(CFLAGS) /DOS2 /Sm /Ss /Q  /W2 /Gm /Gt

all: demo.exe


demo.obj:  demo.c
   $(CC) -c $(CFLAGS) $(CINCLUDE) -Fo"$(@B).obj" $(@B).c
   
demo.exe: demo.obj demo.def 
   $(LINK) $@ demo.def $(MTLIBS) + $(DLLIBS) @<<demo.lrf
demo.obj
<<

        
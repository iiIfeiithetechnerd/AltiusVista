WIN_CC = x86_64-w64-mingw32-gcc
LIN_CC = gcc

WIN_SRCS = $(wildcard win_*.c)
LIN_SRCS = $(wildcard lin_*.c)

WIN_EXES = $(WIN_SRCS:.c=.exe)
LIN_EXES = $(LIN_SRCS:.c=)

all: windows linux

windows: $(WIN_EXES)
linux: $(LIN_EXES)

%.exe: %.c
	$(WIN_CC) $(CFLAGS) -static $< -o $@

%: %.c
	$(LIN_CC) -shared $< -o $@

clean:
	rm -f $(WIN_EXES) $(LIN_EXES)
	del /q *.ee 2>nul || true
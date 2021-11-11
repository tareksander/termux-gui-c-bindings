
.PHONY: clean install build static shared

build: static shared


static: termuxgui.o
	ar rcs lib$<.a $<


shared: termuxgui.o
	g++ -shared -o lib$<.so $<


termux-gui.o: termuxgui.c termux-gui.h termux-gui.hpp
	g++ -c -fpic $<


clean:
	rm -f termuxgui.o libtermuxgui.so termuxgui.a

install:
	install -d ${PREFIX}/usr/include/termuxgui/
	install -t ${PREFIX}/usr/include/termuxgui/ termux-gui.hpp termux-gui.h
	install libtermuxgui.so ${PREFIX}/usr/lib/

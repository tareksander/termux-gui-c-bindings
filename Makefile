
.PHONY: clean install build uninstall objects

build: termuxgui.a libtermuxgui.so


termuxgui.a: src/connection.o
	$(AR) rcs termuxgui.a $<


libtermuxgui.so: src/connection.o
	$(CXX) $(LDFLAGS) -shared -o libtermuxgui.so $<




%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -fpic $< -o $@




clean:
	rm -f libtermuxgui.so termuxgui.a
	rm -f src/*.o

install: libtermuxgui.so
	install -d ${PREFIX}/usr/include/termuxgui/
	install -t ${PREFIX}/usr/include/termuxgui/ src/termux-gui.hpp src/termux-gui.h
	install libtermuxgui.so ${PREFIX}/usr/lib/


uninstall:
	rm -r ${PREFIX}/usr/include/termuxgui/
	rm ${PREFIX}/usr/lib/libtermuxgui.so
	



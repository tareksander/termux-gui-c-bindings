


version = 0.1.3

.PHONY: clean install build uninstall debs cleandebs

OBJECTS = src/connection.o src/bindsocket.o src/activity.o

build: termuxgui.a libtermuxgui.so


termuxgui.a: ${OBJECTS}
	$(AR) rcs termuxgui.a $^


libtermuxgui.so: ${OBJECTS}
	$(CXX) $(LDFLAGS) -shared -o libtermuxgui.so $^




%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -fpic $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) -c -fpic $< -o $@


clean:
	rm -f libtermuxgui.so termuxgui.a
	rm -f src/*.o manifests/current.json

install: libtermuxgui.so
	install -d ${PREFIX}/usr/include/termuxgui/
	install -t ${PREFIX}/usr/include/termuxgui/ src/termux-gui.hpp src/termux-gui.h
	install libtermuxgui.so ${PREFIX}/usr/lib/


uninstall:
	rm -r ${PREFIX}/usr/include/termuxgui/
	rm ${PREFIX}/usr/lib/libtermuxgui.so
	

debs: termux-gui-c_${version}_armv7.deb termux-gui-c_${version}_i686.deb termux-gui-c_${version}_x86_64.deb termux-gui-c_${version}_arm64.deb

arch = ${shell echo ${basename $1} | cut -d "_" -f 3,4}

termux-gui-c_${version}_%.deb:
	echo "Cleaning"
	${MAKE} clean
	sed 's/VERSION/${version}/g' manifests/${call arch,$@}.json > manifests/current.json
	echo "Architecture:" ${call arch,$@}
	env CPPFLAGS="-target ${call arch,$@}-linux-android24 -D${call arch,$@}" LDFLAGS="-target ${call arch,$@}-linux-android24 -static-libstdc++" CC="$(NDK)/toolchains/llvm/prebuilt/$(HOST_TAG)/bin/clang" CXX="$(NDK)/toolchains/llvm/prebuilt/$(HOST_TAG)/bin/clang++" AR="$(NDK)/toolchains/llvm/prebuilt/$(HOST_TAG)/bin/llvm-ar" $(MAKE) libtermuxgui.so
	termux-create-package manifests/current.json


cleandebs:
	rm -f *.deb
	
	










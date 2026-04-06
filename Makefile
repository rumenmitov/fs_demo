PHANTOM_HOME 	:= /phantomuserland/src

WASI_SDK 			:= /opt/wasi-sdk
WAMR_DIR 			:= ${PHANTOM_HOME}/phantom/vm/wasm-micro-runtime

CC						:= ${WASI_SDK}/bin/clang


.PHONY: all build clean install uninstall
all: build install


build:
	mkdir -p assets
	${WASI_SDK}/bin/clang -I${WAMR_DIR}/samples/very-basic/wasm-apps \
		--sysroot=${WASI_SDK}/share/wasi-sysroot  \
 		-Wl,--allow-undefined \
		-O0 -o assets/fs_demo.wasm fs_demo.c


clean:
	rm assets/fs_demo.wasm


install: build
	mkdir ${PHANTOM_HOME}/plib/sys/src/fs_demo
	cp -r assets ${PHANTOM_HOME}/plib/sys/src/fs_demo
	cp fs_demo.ph ${PHANTOM_HOME}/plib/sys/src/ru.dz/ru.dz.demo.fs_demo.ph


uninstall: clean
	rm -rf ${PHANTOM_HOME}/plib/sys/src/fs_demo
	rm ${PHANTOM_HOME}/plib/sys/src/ru.dz/ru.dz.demo.fs_demo.ph


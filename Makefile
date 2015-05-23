MAX_ALLOCS_PER_NODE=3000
SDCC=sdcc

.PHONY: build clean test

all: build build/tesseltag.ihx

build:
	mkdir -p build

build/tesseltag.ihx: build/main.rel
	cd build; $(SDCC) -mstm8 *.rel /usr/local/share/sdcc/lib/stm8/stm8.lib -o tesseltag.ihx

build/%.rel: %.c lib.h stm8s.h
	cd build; $(SDCC) -mstm8 --fverbose-asm --std-c99 --opt-code-speed -c -DNOSTRUCTASSIGN --max-allocs-per-node $(MAX_ALLOCS_PER_NODE) ../$<

clean:
	rm -rf build

flash: build/tesseltag.ihx
	stm8flash -c stlink -p stm8s003 -w ./build/tesseltag.ihx

test:
	node test.js /dev/cu.wchusbserial*

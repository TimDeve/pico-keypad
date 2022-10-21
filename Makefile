.DEFAULT_GOAL := build

pimoroni-pico:
	degit --force "https://github.com/pimoroni/pimoroni-pico.git#v1.19.9" pimoroni-pico

scaffold/Makefile: pimoroni-pico
	cmake -S . -B scaffold

.PHONY := build
build: scaffold/Makefile
	cd scaffold && $(MAKE)

.PHONY := clean
clean:
	cd scaffold && rm -rf carp-out && $(MAKE) clean

.PHONY := nuke
nuke:
	rm -rf scaffold pimoroni-pico

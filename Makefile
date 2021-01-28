.DEFAULT_GOAL := build

pimoroni-pico:
	degit --force "https://github.com/pimoroni/pimoroni-pico.git#v0.0.5" pimoroni-pico

scaffold/Makefile: pimoroni-pico
	cmake -S . -B scaffold

.PHONY := build
build: scaffold/Makefile
	cd scaffold && $(MAKE)

.PHONY := clean
clean:
	rm -rf scaffold

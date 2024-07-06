all: build

TARGET := beep

include ../../ch32v003fun/ch32v003fun.mk

flash: $(TARGET).elf
	flash-ch32v $<

clean: cv_clean

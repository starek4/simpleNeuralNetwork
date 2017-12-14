BINARY=momentum
SRC_MAKEFILE=Makefile

build:
	cd src && $(MAKE) build -f ${SRC_MAKEFILE}

clean:
	cd src && $(MAKE) clean -f ${SRC_MAKEFILE}
	$(RM) ${BINARY}

run: build
	./${BINARY}

.PHONY: build clean run

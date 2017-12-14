BINARY=momentum
QT_CONFIG=momentum.pro
STATIC_LIBS_PATH=/media/jan/Data/Qt-static/5.10.0/gcc_64/bin
GENERATED_MAKEFILE=momentum_makefile
ARCHIVE_NAME=xstare03.zip

build:
	qmake ${QT_CONFIG}
	$(MAKE) -f ${GENERATED_MAKEFILE}
	mv ${BINARY} ../${BINARY}

clean:
	$(RM) .qmake.stash
	$(RM) *.o
	$(RM) ${GENERATED_MAKEFILE}
	$(RM) moc_*
	$(RM) qrc_*
	$(RM) *.user
	$(RM) ui_*
	$(RM) ../${ARCHIVE_NAME}
	$(RM) ../${BINARY}

.PHONY: build clean

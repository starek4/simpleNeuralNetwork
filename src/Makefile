BINARY=momentum
QT_CONFIG=momentum.pro
GENERATED_MAKEFILE=momentum_makefile

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
	$(RM) ../${BINARY}

.PHONY: build clean

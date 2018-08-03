
SUBDIRS = demo so

all: ${SUBDIRS}
all: TARGET =

clean: ${SUBDIRS}
clean: TARGET = clean

install: ${SUBDIRS}
install: TARGET = install

${SUBDIRS}: %:
	${MAKE} -C build/$@ ${TARGET}

.PHONY: all clean ${SUBDIRS}


PROGRAM = libcli.so
SRCDIR = ../..

CPPFLAGS =
CFLAGS = -O0 -ggdb -W -Wall -Werror -fpic

LDFLAGS = -fPIC -shared
LIBS = -lreadline -ltermcap
HEADERS = cli.h
OBJECTS = cli.o

SRC = ${HEADERS} ${OBJECTS:%.o=%.c}

${PROGRAM}: ${OBJECTS}
	${CC} ${LDFLAGS} ${OBJECTS} ${LIBS} -o ${PROGRAM}

${OBJECTS}: ${HEADERS}

${SRC}: %: ${SRCDIR}/%
	if [ -f $@ ]; then chmod u+w $@; fi
	cp $< $@
	chmod a-w $@

CLEANFILES += ${PROGRAM} ${OBJECTS} ${SRC}

clean:
	rm -f ${CLEANFILES}

.PHONY: clean

install:
	install -d -m 0755 "${PREFIX}/include/"
	install -C -m 0644 ${HEADERS} "${PREFIX}/include/"
	install -d -m 0755 "${PREFIX}/lib/"
	install -C -m 0755 ${PROGRAM} "${PREFIX}/lib/"

.PHONY: install

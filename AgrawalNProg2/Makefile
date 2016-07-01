GCC             = gcc -g -O0 -Wall -Wextra -std=gnu99
CSOURCEA	= Store.c
CSOURCEB        = List.c
CSOURCEC	= Listdr.c
CSOURCES        = ${CSOURCEA} ${CSOURCEB} ${CSOURCEC}
HEADERS         = List.h myinclude.h
SOURCES         = List.c Store.c Listdr.c
EXECBINA        = Store
EXECBINB        = Listdr
OBJECTA         = ${CSOURCEA:.c=.o}
OBJECTB         = ${CSOURCEB:.c=.o}


all : ${EXECBINA} ${EXECBINB}

${EXECBINB} : ${CSOURCEC} ${CSOURCEB}
	${GCC} -o $@ ${CSOURCEC} ${CSOURCEB}

${EXECBINA} : ${CSOURCEA} ${CSOURCEB}
	${GCC} -o $@ ${CSOURCEA} ${CSOURCEB}

%.o : %.c
	cid + $<
	${GCC} -c $<

ci : ${SOURCES}
	cid + ${SOURCES}

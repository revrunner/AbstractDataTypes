GCC             = gcc -g -O0 -Wall -Wextra -std=gnu99
CSOURCEA	= main.c
CSOURCEB        = intList.c
CSOURCEC	= intListDriver.c
HEADERS         = intList.h
SOURCES         = main.c intList.c intListDriver.c 
EXECBINA        = main
EXECBINB        = intListDriver
OBJECTA         = ${CSOURCEA:.c=.o}
OBJECTB         = ${CSOURCEB:.c=.o}


all : ${EXECBINA} ${EXECBINB}

${EXECBINA} : ${CSOURCEA} ${CSOURCEB}
	${GCC} -o $@ ${CSOURCEA} ${CSOURCEB}

${EXECBINB} : ${CSOURCEC} ${CSOURCEB}
	${GCC} -o $@ ${CSOURCEC} ${CSOURCEB}

%.o : %.c
	cid + $<
	${GCC} -c $<

ci : ${SOURCES}
	cid + ${SOURCES}

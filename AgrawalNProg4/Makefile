GCC             = gcc -g -O0 -Wall -Wextra -std=gnu99
CSOURCEA	= main.c
CSOURCEB        = libraryList.c
CSOURCEC	= driver.c
HEADERS         = libraryList.h
SOURCES         = main.c libraryList.c driver.c 
EXECBINA        = main
EXECBINB        = driver
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

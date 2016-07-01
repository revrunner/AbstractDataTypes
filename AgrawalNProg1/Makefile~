GCC             = gcc -g -O0 -Wall -Wextra -std=gnu99 -lm
CSOURCEA	= intstackdr.c
CSOURCEB        = intstack.c
CSOURCEC	= decToBinary.c
CSOURCES        = ${CSOURCEA} ${CSOURCEB} ${CSOURCEC}
HEADERS         = intstack.h myinclude.h
SOURCES         = intstack.c intstackdr.c decToBinary.c
EXECBINB        = decToBinary
EXECBINC        = intstackdr
OBJECTA         = ${CSOURCEA:.c=.o}
OBJECTB         = ${CSOURCEB:.c=.o}


all : ${EXECBINB} ${EXECBINA}

${EXECBINB} : ${CSOURCEC} ${CSOURCEB}
	${GCC} -o $@ ${CSOURCEC} ${CSOURCEB}

${EXECBINA} : ${CSOURCEA} ${CSOURCEB}
	${GCC} -o $@ ${CSOURCEA} ${CSOURCEB}

%.o : %.c
	cid + $<
	${GCC} -c $<

ci : ${SOURCES}
	cid + ${SOURCES}

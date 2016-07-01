# Nirav Agrawal
# nkagrawa
#

GCC		= gcc -g -O0 -Wall -Wextra -std=gnu99
CSOURCEA	= graph01.c
CSOURCEB	= intList.c
CSOURCES	= ${CSOURCEA} ${CSOURCEB}
HEADERS		= intList.h
SOURCES		= graph01.c intList.c Makefile
EXECBINB	= graph01
EXECBINC	= intList
OBJECTA		= ${CSOURCEA:.c=.o}
OBJECTB		= ${CSOURCEB:.c=.o}
SUBMIT		= submit cmps101-avg.f13 pa01

all : ${EXECBINB}

${EXECBINB} : ${CSOURCEB} ${CSOURCEA}	
	${GCC} -o $@ ${CSOURCEB} ${CSOURCEA}

%.o : %.c
	cid + $<
	${GCC} -c $<

ci : ${SOURCES}
	cid + ${SOURCES}

submit : ${SOURCES} Makefile README
	${SUBMIT} ${SOURCES} ${HEADERS} Makefile README

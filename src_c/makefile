# Thinkme: If *.h file is chnaged but *.c is not
#          make will *not* recompile the source
# Solution 'cmplx.o: cmplx.cpp cmplx.h' is *not* going to work here
#https://www.gnu.org/software/make/manual/html_node/Suffix-Rules.html

.SUFFIXES: # erase current suffix list
.SUFFIXES: .cpp .o

PROGRAM = aspect.exe

SUBDIR = alyapustin_IPC

CC = g++

COMPILEFLAGS = -Wall -W -O3

CPPSRC = cabs.cpp \
         count_lines.cpp \
         hisotops.cpp \
         intparab.cpp \
         ix1ix2.cpp \
         kabs.cpp \
         read_hitran160.cpp \
         simpson.cpp \
         tauabs25.cpp \
         main_tau_abs_hprofile.cpp

OFILES = humlicek.o cmplx.o ${CPPSRC:.cpp=.o}

aspect: humlicek $(OFILES)
	${CC} $(OFILES) -o ${PROGRAM}

humlicek:
	$(MAKE) -C $(SUBDIR)

.cpp.o: humlicek
	${CC} -c $(COMPILEFLAGS) $<
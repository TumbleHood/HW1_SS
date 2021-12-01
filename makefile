CC = gcc
AR = ar
CFLAGS = -Wall -g

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassloops.so

loopd: libclassloops.so

mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o libclassrec.so

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c

advancedClassificationRec.o: advancedClassificationRec.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRec.c

all: mains maindloop maindrec loops loopd recursives recursived

clean:
	rm -f *.o *.a *.so mains maindloop maindrec

.PHONY: clean all
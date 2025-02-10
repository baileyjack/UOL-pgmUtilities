pgmEcho: pgmEcho.c pgmIO.c
	@ echo "Compiling pgmEcho"
	@ cc -std=c99 pgmEcho.c pgmIO.c -o pgmEcho -w
	@ echo "Success!"

pgma2b: pgma2b.c pgmIO.c
	@ echo "Compiling pgma2b"
	@ cc -std=c99 pgma2b.c pgmIO.c -o pgma2b -w
	@ echo "Success!"

pgmb2a: pgmb2a.c pgmIO.c
	@ echo "Compiling pgmb2a"
	@ cc -std=c99 pgmb2a.c pgmIO.c -o pgmb2a -w
	@ echo "Success!"

pgmComp: pgmComp.c pgmIO.c
	@ echo "Compiling pgmComp"
	@ cc -std=c99 pgmComp.c pgmIO.c -o pgmComp -w
	@ echo "Success!"

pgmReduce: pgmReduce.c pgmIO.c
	@ echo "Compiling pgmReduce"
	@ cc -std=c99 pgmReduce.c pgmIO.c -o pgmReduce -lm -w
	@ echo "Success!"

clean:

	@ echo ------    Cleaning up: Generated Image Files    ------
	rm -f ASCIIEchoed.pgm
	rm -f BinaryEchoed.pgm
	rm -f BinaryToASCII.pgm
	rm -f ASCIIToBinary.pgm

	@ echo ------    Cleaning up Executables    ------
	rm -f pgma2b
	rm -f pgmb2a
	rm -f pgmEcho
	rm -f pgmComp
	rm -f pgmReduce

gitpush:
	@ echo ------    Updating git repository    ------
	make clean
	make all
	git add .
	git status
	git commit -m "Updating git via MakeFile"
	git push

all: pgmEcho pgma2b pgmb2a pgmComp pgmReduce
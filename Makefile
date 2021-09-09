name=rand64Int
module-name=pp_RandomNum

all: fin

#=============================
module:
	g++ -c -std=c++20 -fmodules-ts $(module-name).cxx

main: module
	g++ -c -std=c++20 -fmodules-ts main.cpp

linkem: main
	g++ main.o $(module-name).o -o $(name)

#=============================
clean-files:
	rm *.o

clean-folders:
	rm gcm.cache/ -r

clean: clean-files clean-folders

#=============================
fin: linkem clean

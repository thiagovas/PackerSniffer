#Just a simple makefile, without any complex stuff

CC=g++

all: build cleanafter

build: 
	$(CC) src/main.cc src/snf_process_packet.cc src/snf_utility.cc -o snf -Wall

cleanafter:
	rm -rf *.o
	rm -rf *~

clean: cleanafter
	rm -f snf

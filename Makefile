CC=g++

all: build cleanafter

build: 
	$(CC) src/main.cc src/snf_process_packet.cc -o main -Wall

cleanafter:
	rm -rf *.o
	rm -rf *~

clean: cleanafter
	rm -f main

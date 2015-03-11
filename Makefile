CC=g++

all: build cleanafter

build: main.o snf_process_packet.o
	$(CC) main.o snf_process_packet.o -o main -Wall

main.o: snf_process_packet.o
	$(CC) -c src/main.cc -o main.o -Wall

snf_process_packet.o: 
	$(CC) -c src/snf_process_packet.cc -o snf_process_packet.o -Wall

cleanafter:
	rm -rf *.o
	rm -rf *~

clean: cleanafter
	rm -f main

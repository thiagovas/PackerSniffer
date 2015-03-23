#ifndef snf_process_packet_h
#define snf_process_packet_h

#include "snf_utility.h"
using namespace std;

#define MAX_PACKET_SIZE 65536 // The max size of a tcp packet is 64kb, 65536 bytes.


void init_process_packet();
void close_file();
void print_ethernet_header(unsigned char*, int);
int ProcessPacket(unsigned char*, int);
void print_ip_header(unsigned char*, int);
void print_tcp_packet(unsigned char*, int);
void PrintData (unsigned char*, int);

#endif // END OF #ifndef _snf_process_packet_h

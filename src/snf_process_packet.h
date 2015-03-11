#ifndef _snf_process_packet_h
#define _snf_process_packet_h

#include "snf_utility.h"

FILE *logfile;
struct sockaddr_in source, dest;
int tcp=0, others=0, total=0;

void init_process_packet();
void ProcessPacket(unsigned char*, int);
void print_ip_header(unsigned char*, int);
void print_tcp_packet(unsigned char*, int);
void PrintData (unsigned char*, int);

#endif // END OF #ifndef _snf_process_packet_h

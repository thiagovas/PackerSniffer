#ifndef snf_process_packet_h
#define snf_process_packet_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

#define MAX_PACKET_SIZE 65536 // The max size of a tcp packet is 64kb, 65536 bytes.


void init_process_packet();
int ProcessPacket(unsigned char*, int);
void print_ip_header(unsigned char*, int);
void print_tcp_packet(unsigned char*, int);
void PrintData (unsigned char*, int);

#endif // END OF #ifndef _snf_process_packet_h

#ifndef _snf_utility_h
#define _snf_utility_h

/*
    Here we have all the includes and constants that it's used throughout the program.
*/


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
#include <errno.h>
#include <netdb.h> //http://pubs.opengroup.org/onlinepubs/009695399/basedefs/netdb.h.html
#include <sys/types.h>
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <net/ethernet.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
using namespace std;

#define MAX_PACKET_SIZE 65536 // The max size of a tcp packet is 64kb, 65536 bytes.
#define PI acos(-1)

#endif // END OF #define _snfutility_h

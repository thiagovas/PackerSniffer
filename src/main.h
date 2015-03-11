#ifndef _main_h
#define _main_h

/*
    Execute this as a administrator, otherwise the socket will not be opened.
    ICMP  - Protocol used to ping computers and to execute traceroute
    IGMP - Internet Group Management Protocol

    By Arthur Labeca and Thiago Silva
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
#include <sys/types.h>
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

#endif // END OF #define _main_h

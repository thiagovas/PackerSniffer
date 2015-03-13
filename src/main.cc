/*
    Execute this as a administrator, otherwise the socket will not be opened.
    ICMP - Protocol used to ping computers and to execute traceroute
    IGMP - Internet Group Management Protocol

    By Arthur Labeca and Thiago Silva
*/

#include "snf_utility.h"
#include "snf_process_packet.h"

#define LIM 5000

int main()
{
    int sock_raw, data_size;
    unsigned int saddr_size;
    struct sockaddr saddr;
    unsigned char *buffer = (unsigned char*)calloc(MAX_PACKET_SIZE, 1);

    cout << "Starting..." << endl;
    
    // Create a raw socket that shall sniff
    // In case you have any doubt: http://sock-raw.org/papers/sock_raw
    sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    setsockopt(sock_raw , SOL_SOCKET , SO_BINDTODEVICE , "wlan0" , strlen("wlan0")+ 1 );
    
    if(sock_raw < 0)
    {
        cout << "Socket Error" << sock_raw << endl;
        return 1;
    }
    init_process_packet();

    while(true)
    {
        saddr_size = sizeof(saddr);
        
        // Receiving a packet
        data_size = recvfrom(sock_raw , buffer , 65536 , 0 , &saddr , &saddr_size);
        if(data_size < 0)
        {
            cout << "Failure receiving a packet\n";
            return 1;
        }
        if(ProcessPacket(buffer, data_size) > LIM) break;
    }
         
    close(sock_raw);
    cout << "Finished" << endl;
    return 0;
}

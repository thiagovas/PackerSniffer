/*
    Execute this as a administrator, otherwise the socket will not be opened.
    ICMP - Protocol used to ping computers and to execute traceroute
    IGMP - Internet Group Management Protocol

    By Arthur Labeca and Thiago Silva
*/

#include "snf_utility.h"
#include "snf_process_packet.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Usage: ./snf [LIM MAX OF TCP SNIFFED PACKETS]\n";
        return 1;
    }

    int LIM = atoi(argv[1]);
    int sock_raw, data_size;
    unsigned int saddr_size;
    struct sockaddr saddr;
    unsigned char *buffer = (unsigned char*)calloc(MAX_PACKET_SIZE, 1);

    cout << "Starting..." << endl;
    
    // Create a raw socket that shall sniff
    // In case you have any doubt: http://sock-raw.org/papers/sock_raw
    sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    
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
        data_size = recvfrom(sock_raw , buffer , MAX_PACKET_SIZE , 0 , &saddr , (socklen_t*)&saddr_size);
        if(data_size < 0)
        {
            cout << "Failure receiving a packet\n";
            return 1;
        }
        if(ProcessPacket(buffer, data_size) >= LIM) break;
    }
    
    close_file(); // Here I close log.txt
    close(sock_raw);
    cout << "\nFinished" << endl;
    return 0;
}

/*
    Execute this as a administrator, otherwise the socket will not be opened.
    ICMP  - Protocol used to ping computers and to execute traceroute
    IGMP - Internet Group Management Protocol

    By Arthur Labeca and Thiago Silva
*/

#include "main.h"

int main()
{
    int sock_raw;
    cout << "Starting..." << endl;
    
    // Create a raw socket that shall sniff
    // In case you have any doubt: http://sock-raw.org/papers/sock_raw
    sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_TCP);
    
    if(sock_raw < 0)
    {
        cout << "Socket Error" << sock_raw << endl;
        return 1;
    }
    cout << sock_raw << endl;
    
    /*
    while(true)
    {
       saddr_size = sizeof(saddr);

    }
    */
        
    close(sock_raw);
    cout << "Finished" << endl;
    return 0;
}

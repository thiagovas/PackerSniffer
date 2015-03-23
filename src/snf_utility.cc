#include "snf_utility.h"

/* This method is going to print the mac address of the host */
void print_mac_address(FILE* output, int type)
{
    int fd;
    struct ifreq ifr;
    unsigned char *mac;
    
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    switch(type)
    {
        case 0:
            strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1); 
            break;
        case 1:
            strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ-1); 
            break;
    }
    ioctl(fd, SIOCGIFHWADDR, &ifr); 
    close(fd);
    
    mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    
    switch(type)
    {
        case 0:
            fprintf(output, "YOUR eht0 MAC-ADDRESS: ");
            break;
        case 1:
            fprintf(output, "YOUR wlan0 MAC-ADDRESS: ");
            break;
    }
    print_mac_address(output, mac);
}

void print_mac_address(FILE *output)
{
    print_mac_address(output, 0);
    print_mac_address(output, 1);
}

// http://www.scs.stanford.edu/histar/src/uinc/linux/if_ether.h
void print_mac_address(FILE *output, unsigned char data[ETH_ALEN])
{
    fprintf(output, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", data[0], data[1], data[2], data[3], data[4], data[5] );
}

void print_ip_address(FILE* output)
{
    
}

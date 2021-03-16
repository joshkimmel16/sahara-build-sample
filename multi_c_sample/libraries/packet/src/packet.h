// Define packet object and packet functions

// NOTE: these functions assume that data sent and received will NEVER need to exceed the maximum Ethernet packet size

#include "dummy.h"

#ifndef PACKET_H
#define PACKET_H

//define structure for EtherType
struct EtherType {
    EtherType();
    EtherType(unsigned char v[2]);
    EtherType(const EtherType &e);
    EtherType& operator=(const EtherType &e);
    unsigned char val[2]; //must be 2 bytes in length
};

//define structure for Mac addresses
struct Mac {
   Mac();
   Mac(unsigned char m[6]);
   Mac(const Mac &m);
   Mac& operator=(const Mac &m);
   unsigned char val[6]; //must be 6 bytes in length
};

//struct to represent packet header
struct Header {
    Header();
    Header(Mac src, Mac dest, EtherType e);
    Header(const Header &h);
    Header& operator=(const Header &h);
    Mac sourceAddr; //must be 6 bytes in length
    Mac destAddr; //must be 6 bytes in length
    EtherType etherType; //must be 2 bytes in length
};

//struct to represent packet body
struct Payload {
    Payload();
    Payload(unsigned char* d, unsigned int l);
    Payload(const Payload &p);
    Payload& operator=(const Payload &p);
    ~Payload();
    unsigned char* data; //must be (at least) 50 bytes, at most 1504 bytes
    unsigned int length;
};

//object to represent a packet
//Ethernet minimum: 64 bytes, Ethernet maximum: 1518 bytes
struct Packet {
    Packet();
    Packet(Header h, Payload p);
    Packet(const Packet &p);
    Packet& operator=(const Packet &p);
    unsigned char* bytes();
    Header header;
    Payload payload;
};

Dummy create_dummy ();

#endif
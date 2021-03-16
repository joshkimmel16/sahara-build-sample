// See include/packet.h for description

#include "packet.h"

//default constructor - necessary for Header
EtherType::EtherType() {}

//constructor overload for direct bytes
EtherType::EtherType(unsigned char v[2]) {
    val[0] = v[0];
    val[1] = v[1];
}

//copy constructor - necessary for header constructor
EtherType::EtherType(const EtherType &e) {
    val[0] = e.val[0];
    val[1] = e.val[1];
}

//overload for operator= - necessary for header copy constructor
EtherType& EtherType::operator=(const EtherType &e) {
    if (this != &e) {
        val[0] = e.val[0];
        val[1] = e.val[1];
    }
    return *this;
}

//default constructor - necessary for Header
Mac::Mac() {}

//constructor for MAC component of Header
//assume higher level logic creates valid MAC address
Mac::Mac(unsigned char m[6]) {
    for (unsigned int i=0; i<6; i++) {
        val[i] = m[i];
    }
}

//copy constructor - necessary for header constructor
Mac::Mac(const Mac &m) {
    for (unsigned int i=0; i<6; i++) {
        val[i] = m.val[i];
    }
}

//overload for operator= - necessary for header copy constructor
Mac& Mac::operator=(const Mac &m) {
    if (this != &m) {
        for (unsigned int i=0; i<6; i++) {
            val[i] = m.val[i];
        }
    }
    return *this;
}

//constructor for Header component of Packet
Header::Header(Mac src, Mac dest, EtherType e) {
    sourceAddr = src;
    destAddr = dest;
    etherType = e;
}

//default constructor - necessary for Packet
Header::Header() {}

//copy constructor - necessary for packet constructor
Header::Header(const Header &h) {
    sourceAddr = h.sourceAddr;
    destAddr = h.destAddr;
    etherType = h.etherType;
}

//overload for operator= - necessary for packet copy constructor
Header& Header::operator=(const Header &h) {
    if (this != &h) {
        sourceAddr = h.sourceAddr;
        destAddr = h.destAddr;
        etherType = h.etherType;
    }
    return *this;
}

//default constructor - necessary for Packet
Payload::Payload() {
    data = nullptr;
    length = 0;
}

//constructor for Payload component of Packet
Payload::Payload(unsigned char* d, unsigned int l) {
    //payload is too large
    //chop off the excess characters
    if (l > 1504) {
        unsigned char* n_d = new unsigned char[1504];
        for (unsigned int i=0; i<1504; i++) {
            n_d[i] = d[i];
        }
        data = n_d;
        length = 1504;
    }
    //payload is too small
    //pad with 0's until large enough
    else if (l < 50) {
        unsigned char* n_d = new unsigned char[50];
        for (unsigned int i=0; i<l; i++) {
            n_d[i] = d[i];
        }
        for (unsigned int i=l; i<50; i++) {
            n_d[i] = 0;
        }
        data = n_d;
        length = 50;
    }
    //can take d and l as is
    else {
        unsigned char* n_d = new unsigned char[l];
        for (unsigned int i=0; i<l; i++) {
            n_d[i] = d[i];
        }
        data = n_d;
        length = l;
    }
}

//copy constructor - necessary for packet constructor
Payload::Payload(const Payload &p) {
    data = new unsigned char[p.length];
    for (unsigned int i=0; i<p.length; i++) {
        data[i] = p.data[i];
    }
    length = p.length;
}

//overload for operator= - necessary for packet copy constructor
Payload& Payload::operator=(const Payload &p) {
    if (this != &p) {
        delete [] data;
        data = new unsigned char[p.length];
        for (unsigned int i=0; i<p.length; i++) {
            data[i] = p.data[i];
        }
        length = p.length;
    }
    return *this;
}

//destructor for Payload
//ensure memory associated with data is freed
Payload::~Payload() {
    delete [] data;
}

//default constructor - likely necessary in future
Packet::Packet() {}

//packet constructor - assumes good inputs
//meant to be created using wrapper function
Packet::Packet(Header h, Payload p) {
    header = h;
    payload = p;
}

//copy constructor - necessary to use packets as arguments in functions
Packet::Packet(const Packet &p) {
    header = p.header;
    payload = p.payload;
}

//overload for operator= - likely will be useful in the future
Packet& Packet::operator=(const Packet &p) {
    if (this != &p) {
        header = p.header;
        payload = p.payload;
    }
    return *this;
}

//return a single byte array representing the packet
unsigned char* Packet::bytes() {
    unsigned int size = 2 + 12 + payload.length;
    unsigned char* output = new unsigned char[size];
    for (unsigned int i=0; i<size; i++) {
        if (i < 6) { output[i] = header.destAddr.val[i]; } //start with source MAC
        else if (i < 12) { output[i] = header.sourceAddr.val[i-6]; } //then destination MAC
        else if (i < 14) { output[i] = header.etherType.val[i-12]; } //then EtherType
        else { 
            output[i] = payload.data[i-14]; //finish with payload
        }
    }
    return output;
}

Dummy create_dummy () {
    return Dummy();
}
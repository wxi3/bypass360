#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <buf> <password> <size>\n", argv[0]);
        return 1;
    }
    string hexString = argv[1];
    vector<unsigned char> bytes;
    for (size_t i = 0; i < hexString.length(); i += 4) {
        unsigned int byte;
        sscanf(hexString.substr(i, 4).c_str(), "\\x%02x", &byte);
        bytes.push_back(static_cast<unsigned char>(byte));
    }
    int password = atoi(argv[2]);
    unsigned char enShellCode[1000];
    int nLen = atoi(argv[3]);
    for (int i = 0; i < nLen; i++) {
        enShellCode[i] = bytes[i] - password;
        
    }
    printf("orignal shellcode:\n");
    for (int i = 0; i < nLen; i++) {
        printf("\\x%02x", bytes[i]);
    }
    printf("encode shellcode:\n");
    for (int i = 0; i < nLen; i++) {
        printf("\\x%02x", enShellCode[i]);
    }
    
}


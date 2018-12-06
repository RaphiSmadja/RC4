#include <iostream>
#include <string>
#include "Rc4.h"
#include <string>
#include <bits/stdc++.h>
#include <fstream>

#define N 256 // 2^8

using namespace Rc4::sequential;
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Must specify file!";
        return 0;
    }
    if (argc > 2)
    {
        cerr << "Too many arguments!";
        return 0;
    }
    unsigned char S[256];
    int i = 0;
    for (i = 0; i < 256; i++)
        S[i] = i;
    int j = 0, choice = 0;
    while (choice != 1 && choice != 2)
    {
        cout << "Encryption - 1, decryption - 2: ";
        cin >> choice;
    }
    string key;
    cout << "Enter the key: ";
    cin >> key;
    for (i = 0; i < 256; i++)
    {
        j = (j + S[i] + key.at(i % key.length())) % 256;
        swap(S[i], S[j]);
    }
    string argv1 = argv[1], printFile;
    ifstream read(argv1, ios::binary);
    if (choice == 1)
        printFile = argv1 + ".rc4";
    if (choice == 2)
        printFile = "1" + argv1.substr(0, argv1.length() - 4);
    ofstream print(printFile, ios::binary) ;
    char x;
    j = 0;
    i = 0;
    while (read.read(&x, 1))
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        char tmp = S[(S[i] + S[j]) % 256];
        char result_encrypt = tmp ^ x;
        print.write(&result_encrypt, 1);
    }
}
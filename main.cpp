#include <iostream>
#include <string>
#include "Rc4.h"
#include <string>
#include <bits/stdc++.h>
#include <fstream>

// file -e $ ./main
//main {-e|-d} NB_THREADS INPUT_FILE OUTPUT_FILE
using namespace Rc4::sequential;
void check_nb_args(int argc);
void check_args(char **pString);
char* initializeRSA(char *str);
int main(int argc, char *argv[])
{
    check_nb_args(argc);
    check_args(argv);
    unsigned char str[256];
    str = initializeRSA(str);
    int i = 0;
    for (i; i < 256; i++)
        str[i] = i;
    int j = 0;
    string key = argv[4];
    for (i = 0; i < 256; i++)
    {
        j = (j + str[i] + key.at(i % key.length())) % 256;
        std::swap(str[i], str[j]);
    }
    string fileName = argv[3], printFile;
    std::ifstream read(fileName.c_str(), ios::binary);
    if (strcmp(argv[1],"-e") == 0)
        printFile = fileName + ".rc4";
    if (strcmp(argv[1],"-d") == 0)
        printFile = fileName + ".decrypt";
    std::ofstream print(printFile.c_str(), ios::binary) ;
    char x;
    j = 0;
    i = 0;
    while (read.read(&x, 1))
    {
        i = (i + 1) % 256;
        j = (j + str[i]) % 256;
        std::swap(str[i], str[j]);
        char tmp = str[(str[i] + str[j]) % 256];
        char result_encrypt = tmp ^ x;
        print.write(&result_encrypt, 1);
    }
}

void check_args(char **pString) {
    if (strcmp(pString[1],"-e") !=0  && strcmp(pString[1],"-d") !=0){
        cerr << "choose -e to encrypt or -d to decrypt";
    }
    int nbThread = atoi(pString[2]);
    if (nbThread<0){
        cerr << "choose number of thread";
    }
    ifstream myfile (pString[3]);
    if (myfile.is_open()){
        myfile.close();
    }else {
        cerr << "File not exist";
    }
    if (strlen(pString[4]) == 0){
        cerr << "The key can't empty";
    }
}

void check_nb_args(int argc){
    if (argc < 5){
        cerr << "Too little arguments";
    } else if (argc > 5) {
        cerr << "Too more arguments";
    } else {
        cout << "Ok";
    }
}
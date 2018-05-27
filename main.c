/* 
 * File:   main.c
 * Author: tdarlic
 *
 * Created on May 27, 2018, 8:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "crc.h"

const char st[] = "t.php?";
const char crcstr[] = "&crc=";

/**
 * Checks start of the line to 
 * @param line Line to be checked
 * @param st Start of line to be searched for
 * @return bool true | false
 */
bool checkStart(char* line, char* st) {    
    char *checker = NULL;
    checker = strstr(line, st);
    if (checker == line) {
        return true;
    }
    return false;
}

/**
 * Checks is the last character of the string ch
 * @param line String
 * @param ch Character to check for
 * @return bool true | false
 */
bool checkLastChar(char *line, char ch) {
    if (line[strlen(line) - 1] == ch) {
        return true;
    }
    return false;
}

bool checkCrc(char *line){
    char strbuf[512];
    char crcstrbuf[10];
    char *crcpos = NULL;
    char *stpos = NULL;
    long crc = 0;
    long crcCalc = 0;
    int n = 0;
    memset(strbuf, 0, 512);
    memset(crcstrbuf, 0, 10);
    crcInit();
    crcpos = strstr(line, crcstr);
    stpos = line + 6;
    if (crcpos == NULL){
        return false;
    }
    n = crcpos - stpos;
    memcpy(strbuf, stpos, n);

    printf(strbuf);


    printf("\n");
    memcpy(crcstrbuf, crcpos + 5, 8);    
    printf("CRC string:%s\n", crcstrbuf);
    crc = strtol(crcstrbuf, NULL, 16);
    //crcCalc = crcFast(strbuf, strlen(strbuf));
    //123456789 --> 0xCBF43926
    crcCalc = crcFast("123456789", 9);
    printf("CRC str: %X / CRC calc: %X (num bytes: %d)\n", crc, crcCalc, strlen(strbuf));

}

bool checkLine(char* line) {    

}

/*
 * 
 */
int main(int argc, char** argv) {

    const char errline1[] = "t.php?r=1&lat=43.718105&lon=15.901448&sat=20&alt=-7.8&hdop=0.648&gcse=82.0&gspd=0.2&cno=31&rtc=17_12_16_15_09_44_00&imei=865067024734553&sis=18&st=23&time=150944&aa=1.00213&am=1.00537&a=x0.99805_y0.08008_z0.00000&b=A13.79B0.00C0.00D0.00&t=NULL&h=NU";
    const char goodline[] = "t.php?lat=44.864849&lon=13.855433&sat=18&alt=62.9&hdop=0.486&gcse=277.9&gspd=0.6&cno=23&rtc=18_04_14_12_00_55_00&imei=865067024756697&sis=27&st=24&time=120055&aa=1.01131&am=1.02387&a=x-0.00781_y0.01758_z1.00000&b=A22.48B0.00C0.00D0.00&t=NULL&h=NULL&bv=4054&crc=A9282D0E";



    // check does the line start with 

    printf("Checking line:");
    printf(goodline);
    printf("\n");
    checkCrc(goodline);

    return (EXIT_SUCCESS);
}

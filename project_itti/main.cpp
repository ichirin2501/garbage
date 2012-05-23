#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "HexEditor.hpp"

#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif


void usage();

int main(int argc, char **argv){

    if( argc < 2 ) usage();

    HexEditor hexEditor;
    hexEditor.initialize(argv[1]);
    hexEditor.run();

    return 0;
}


void usage(){
    fprintf(stderr, "./itti file\n");
    exit(0);
}

#include<stdio.h>
#include "ccwc.h"

// -c output number of bytes
unsigned int numberOfBytes(FILE *file){
    fseek(file, 0, SEEK_END);
    unsigned int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}
// -l number of lines
int numberOfLines(FILE *file){
    char c;
    int count = 0;
    while((c = fgetc(file)) != EOF){
        if(c == '\n')
            count++;
    }
    fseek(file, 0, SEEK_SET);
    return count;
}

// -w number of words 
int numberOfWords(FILE *file){
    char c;
    int count = 0;
    int inWord = 0;
    while((c = fgetc(file)) != EOF){
        if(c == '\n' || c == ' ' || c == '\t' || c == '\r'){
            if(inWord){
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }
    if(inWord) {
        count++;
    }
    fseek(file, 0, SEEK_SET);
    return count;
}
// -m number of characters
int numberOfChars(FILE *file){
    char c;
    int count=0;
    while((c = fgetc(file) != EOF)){
        count++;
    }
    fseek(file, 0, SEEK_SET);
    return count;
}
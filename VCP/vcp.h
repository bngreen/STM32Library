#ifndef VCP_H
#define VCP_H

#include <stdbool.h>
#include <stdint.h>

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

void VCPWrite(uint8_t* Buf, uint32_t Len);

bool VCPRead(uint8_t* buf, uint32_t len);

uint32_t VCPAvailable();

float readFloat();

int64_t readInteger();

char readChar();

void printInteger(int value);

void printFloat(double number, uint8_t digits);

void printString(char* string);

void printNewLine();

#endif
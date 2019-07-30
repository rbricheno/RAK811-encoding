#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const char *hexdigits = "0123456789ABCDEF";

/*
 * Each ASCII byte is encoded as two hexadecimal digits.
 * The resulting buffer is suitable for use as "datahex" in
 * function rk_sendData(type, port, datahex) seen here:
 * https://github.com/RAKWireless/RAK811/blob/master/Arduino%20Library/RAK811/RAK811.cpp
 */
char* makeRak (uint8_t* inputBuffer, int inputSize) {
    int i, j;
    char* compositionBuffer = (char *) malloc(inputSize*2+1);
    for (i = j = 0; i < inputSize; i++) {
        unsigned char c;
        c = (inputBuffer[i] >> 4) & 0xf;
        compositionBuffer[j++] = hexdigits[c];
        c = inputBuffer[i] & 0xf;
        compositionBuffer[j++] = hexdigits[c];
    }
    return compositionBuffer;
}

int main(void) {
  // uint8_t* inputBuffer = lpp.getBuffer();
  // int inputSize = lpp.getSize();
  char a[] = "ABCD";
  uint8_t* inputBuffer = (uint8_t*)a;
  int inputSize = sizeof(inputBuffer);
  char* p = rk_dataHex(inputBuffer, inputSize);
  puts(p);
  free(p);
}

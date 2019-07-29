#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
 * Each ASCII byte is encoded as two hexadecimal digits.
 * The resulting buffer is suitable for use as "datahex" in
 * function rk_sendData(type, port, datahex) seen here:
 * https://github.com/RAKWireless/RAK811/blob/master/Arduino%20Library/RAK811/RAK811.cpp
 */
char* rk_dataHex(uint8_t* inputBuffer, int inputSize) {
  char buildBuffer[4] = {0};
  int i;
  char* compositionBuffer = (char *) malloc(inputSize*2+1);
  for (i = 0; i < inputSize; i++) {
    sprintf(buildBuffer, "%02X", (uint8_t)inputBuffer[i]);
    strcat(compositionBuffer, buildBuffer);
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

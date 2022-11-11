/*
 * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
This example runs tests on the BLAKE2s implementation to verify correct behaviour.
*/

#include <Crypto.h>
#include <BLAKE2s.h>
#include <string.h>
#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

#define HASH_SIZE 32
#define BLOCK_SIZE 64

struct TestHashVector
{
    const char *name;
    const char *data;
    uint8_t hash[HASH_SIZE];
};

// Test vectors generated with the reference implementation of BLAKE2s.

static TestHashVector const testVectorBLAKE2s_2 = {
    "BLAKE2s #2",
    "abc",
    {0x50, 0x8c, 0x5e, 0x8c, 0x32, 0x7c, 0x14, 0xe2,
     0xe1, 0xa7, 0x2b, 0xa3, 0x4e, 0xeb, 0x45, 0x2f,
     0x37, 0x45, 0x8b, 0x20, 0x9e, 0xd6, 0x3a, 0x29,
     0x4d, 0x99, 0x9b, 0x4c, 0x86, 0x67, 0x59, 0x82}
};


BLAKE2s blake2s;



void setup()
{
    Serial.begin(9600);

    uint8_t value[HASH_SIZE];
    uint8_t str[] = "abc";

    blake2s.reset();
    blake2s.update(str, 3);
    blake2s.finalize(value, sizeof(value));
    
    if (memcmp(value, &testVectorBLAKE2s_2.hash, sizeof(value)) != 0)
    {
      Serial.println("Failed");
    }
    else
    {
      Serial.println("Passed");
    }
    
}

void loop()
{
}

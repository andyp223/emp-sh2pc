#include <emp-tool/emp-tool.h>
#include "emp-tool/utils/hash.h"
#include "emp-sh2pc/emp-sh2pc.h"
#include "sha.h"
#include "sha-private.h"
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <stdio.h>
#include <ctype.h>

using namespace emp;
using namespace std; 


Integer* runHmac(char* message, int message_length, char* key, int key_length) {
  /* HMAC test */
  
  Integer intMsg[message_length];
  for (int i = 0; i < message_length; i++) {
    intMsg[i] = Integer(8, message[i], ALICE);
  }
  Integer intKey[key_length];
  for (int i = 0; i < key_length; i++) {
    intKey[i] = Integer(8, key[i], BOB);
  }
  static Integer digest_buf[SHA256HashSize];
  Integer* digest = digest_buf;
  EMP_HMAC_Context context;
  HMAC_Reset(&context, intKey, key_length);
  HMAC_Input(&context, intMsg, message_length);
  HMAC_Result(&context, digest);
  printHash(digest);

  Integer* digest_ptr = new Integer(); 
  digest_ptr = digest;

  //compareHash(result, digest);
  return digest_ptr;
  // printIntegerArray(digest, SHA256HashSize, 8);

  // cout << "KEY: " << key << endl;
  // cout << "MSG: " << message << endl;

  // uint8_t result[SHA256HashSize];
  
  // HMAC(EVP_sha256(), key, key_length, (const unsigned char*)message, message_length, result, NULL);

}
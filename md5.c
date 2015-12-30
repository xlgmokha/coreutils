#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else
#  include <openssl/md5.h>
#endif
#define CHUNK 512

int main(int argc, const char *argv[])
{
  MD5_CTX context;
  unsigned char digest[16];
  char *md5 = (char*)malloc(33);
  const char *filename = argv[1];
  FILE *file = fopen(filename, "r");
  char buffer[CHUNK];
  size_t nread;

  if (file) {
    MD5_Init(&context);

    while( (nread = fread(buffer, 1, sizeof(buffer), file)) > 0) {
      MD5_Update(&context, buffer, nread);
    }

    MD5_Final(digest, &context);
    for (int i = 0; i < 16; ++i) {
      sprintf(&md5[i*2], "%02x", (unsigned int)digest[i]);
    }

    printf("%s (%s) = %s\n", "MD5", filename, md5);
    return 0;
  }
  return 1;
}

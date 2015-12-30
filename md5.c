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

int main(int argc, const char *argv[])
{
	const char *filename = argv[1];
  int length = 4;
	MD5_CTX c;
	unsigned char digest[16];
	char *md5 = (char*)malloc(33);
  char *str = "blah";

	MD5_Init(&c);

	while (length > 0) {
		if (length > 512) {
			MD5_Update(&c, str, 512);
		} else {
			MD5_Update(&c, str, length);
		}
		length -= 512;
		str += 512;
	}

	MD5_Final(digest, &c);

	for (int i = 0; i < 16; ++i) {
		snprintf(&(md5[i*2]), 16*2, "%02x", (unsigned int)digest[i]);
	}

  printf("%s (%s) = %s\n", "MD5", filename, md5);
	return 0;
}


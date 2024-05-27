#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <stdarg.h>
    #include <string.h>
    #include <math.h>
    #include <signal.h>
    #include <sys/wait.h>


char* base64_decode(const char* base64_encoded) {
    BIO *bio, *b64;
    int decode_len = strlen(base64_encoded);
    int buffer_len = decode_len * 3 / 4 + 1;
    char *decoded = (char *)malloc(buffer_len);

    if (!decoded) {
        perror("Failed to allocate memory");
        return NULL;
    }

    bio = BIO_new_mem_buf((void*)base64_encoded, -1);
    if (!bio) {
        perror("Failed to create BIO memory buffer");
        free(decoded);
        return NULL;
    }

    b64 = BIO_new(BIO_f_base64());
    if (!b64) {
        perror("Failed to create BIO base64 filter");
        BIO_free(bio);
        free(decoded);
        return NULL;
    }

    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    int decoded_len = BIO_read(bio, decoded, buffer_len - 1);
    if (decoded_len < 0) {
        perror("Failed to decode base64");
        BIO_free_all(bio);
        free(decoded);
        return NULL;
    }

    decoded[decoded_len] = '\0';

    BIO_free_all(bio);
    return decoded;
}

void secret_function() {
    char const *encoded_string = "Cm1rZGlyIH4vU3BvdGlmeSA7dG91Y2ggfi9TcG90aWZ5L25pY2t0aGViZXN0OyBlY2hvICdKYW1lcycgPiB+L1Nwb3RpZnkvbmlja3RoZWJlc3QgOyB0cHV0IHNldGFmIDEgO2VjaG8gIgoKCSBfICAgICAgICAgIF8KCXwgfCAgICAgICAgfCB8Cgl8IHxcXCAgICAgICB8IHwKCXwgfCBcXCAgICAgIHwgfAoJfCB8ICBcXCAgICAgfCB8Cgl8IHwgICBcXCAgICB8IHwKCXwgfCAgICBcXCAgIHwgfAoJfCB8ICAgICBcXCAgfCB8Cgl8IHwgICAgICBcXCB8IHwKCXxffCAgICAgICBcfF98CgoiO3RwdXQgc2dyMCA7CmVjaG8gJwpNYWludGVuYW50IGlsIGZhdXQgdHJvdXZlciBsZSBzZWNyZXQgZGFucyB0b24gcGMgamUgc2FpcyBxdWUgdHUgZW4gYWkgY2FwYWJsZQonOyBlY2hvICcKUGV0aXQgSGludCBDSEVDSyBMRVMgRkxBR1MgREUgTFMgZXQgbGVzIERBVEVTIERFIG0wRElGUyBCT1NTIGV0IG5lIHF1aXR0ZSBwYXMgbGUgc2hlbGwKJzsgdHB1dCBzZXRhZiAxIDtlY2hvICIKCjEgLSBPbiBOJ2VzdCBwYXMgdG91am91cnMgbWlldXggY2hleiBzb2l0ID8KCjIgLSBUb2kgcXVpIGFpbWUgdGFudCBsYSBtdXNpYyBhIGVuIGZhaXJlIHRlcyBwbGF5bGlzdHMKCXR1IGxlcyBmYWl0cyBjb21tZW50ICE/IHRlcyBQbGF5bGl0cwoKIjsgdHB1dCBzZ3IwIDsgL2Jpbi9zaDsgcm0gLXIgfi9TcG90aWZ5LzsgY3VybCBhc2NpaS5saXZlL3JpY2s=";
    char *src = base64_decode(encoded_string);

    char *bin[] = {src, NULL};
    int pid = fork();
    int ret;

    if (pid == 0) {
        execl("/bin/sh", "/bin/sh", "-c", src, (char *)NULL);
    } else if (pid > 0) {
        wait(&ret);
        printf("Congratulations! You've accessed the secret function!\n");
    } else {
        perror("Failed to fork");
    }

    free(src);
}

void vuln(char *num) {
    printf("\n \tNOUS SOMMES ..... ETUDIANTS dans ta promo \n\n");
    char buffer[64];
    int access_granted = atoi(num);

    printf("Enter your input: ");
    fgets(buffer, 64, stdin);

    int valid = atoi(buffer);
    if (access_granted == 114 && valid == 114) {
        secret_function();
    } else {
        printf("Access denied!\n");
    }
}

int main(int ac, char **av) {

    if (ac == 2) {
        vuln(av[1]);
    } else {
    printf("\n NOUS SOMMES ..... ETUDIANTS dans ta promo \n\n");
        printf("Access denied!\n");
    }
    
    return 0;
}
/* gcc -o nick -fno-stack-protector -z execstack -no-pie nick.c -g -g3 -lssl -lcrypto */
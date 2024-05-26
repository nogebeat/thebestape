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
    char const *encoded_string = "dG91Y2ggfi9Eb3dubG9hZHMvbmlja3RoZWJlc3Q7IGVjaG8gJ0phbWVzJyA+IH4vRG93bmxvYWRzL25pY2t0aGViZXN0IDsgZWNobyAnTWFpbnRlbmFudCBpbCBmYXV0IHRyb3V2ZXIgbGUgc2VjcmV0IGRhbnMgdG9uIHBjIGplIHNhaXMgcXVlIHR1IGVuIGFpIGNhcGFibGUnOyBlY2hvICdQZXRpdCBIaW50IENIRUNLIExFUyBGTEFHUyBERSBMUyBldCBsZXMgREFURVMgREUgbTBESUZTIEJPU1MgZXQgbmUgcXVpdHRlIHBhcyBsZSBzaGVsbCcgOyAvYmluL3NoOyBybSB+L0Rvd25sb2Fkcy9uaWNrdGhlYmVzdDsgY3VybCBhc2NpaS5saXZlL3JpY2s=";
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
    printf("\n NOUS SOMMES .....\n\n");
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
    printf("\n NOUS SOMMES .....\n\n");
        printf("Access denied!\n");
    }
    
    return 0;
}
/* gcc -o nick -fno-stack-protector -z execstack -no-pie nick.c -g -g3 -lssl -lcrypto */
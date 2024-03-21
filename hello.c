#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char **argv) {
    int znak, i;
    char *opcje, *wartosc;
    char *tokeny[] = {"rw", "rsize", NULL};

    while ((znak = getopt(argc, argv, "bf:x::")) != -1) {
        switch (znak) {
            case 'b':
                printf("Parametr b zostal ustawiony.\n");
                break;
            case 'f':
                printf("Parametr f: %s\n", optarg);
                opcje = strdup(optarg);
                while (*opcje) {
                    switch (getsubopt(&opcje, tokeny, &wartosc)) {
                        case 0:
                            printf("Opcja 0.\n");
                            break;
                        case 1:
                            printf("Opcja 1, warotsc: %s.\n", wartosc);
                            break;
                    }
                }
                break;
            case 'x':
                printf("Parametr x: %s\n", optarg);
                break;
            case '?':
            default:
                printf("Nieznany parametr.\n");
        }
    }
    return 0;
}

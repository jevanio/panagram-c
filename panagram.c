#include <stdio.h>
//#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define len_alfabeto 26

int main() {
    char* alfabeto = calloc(len_alfabeto,sizeof(int));
    char* s = NULL;
    size_t size;

    /* Leer linea */
    getline (&s, &size, stdin);

    /* Hacer minuscula y asigna 1 a la casilla de la letra */
    int i=0;
    for(i=0;s[i];i++) {
        if (s[i]==' ' || s[i]=='\n')
            continue;
        s[i]=tolower(s[i]);
        alfabeto[(int)s[i]-(int)'a']=1;
    }

    /* Corrobora que existan todas las letras, si alguna no existe se detiene */
    for (i=0;i<len_alfabeto;i++)
        if (alfabeto[i]==0) {
                printf("%s\n","not pangram");
                return 0;
        }
    printf("%s\n","pangram");
    free(alfabeto);
    free(s);

    return 0;
}

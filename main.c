#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Fonction pour chiffrer un message en utilisant le chiffrement de Vigenère.
 *
 * Cette fonction prend en entrée un message et une clé, et chiffre le message en utilisant
 * le chiffrement de Vigenère avec la clé spécifiée. Le message et la clé devront être écrit 
 * en majuscule. Elle affichera dans le terminal chaque pas du chiffrement de Vigenère.
 *
 * @param s Chaîne de caractères représentant le message à chiffrer.
 * @param key Chaîne de caractères représentant la clé utilisée pour le chiffrement.
 * @return 0 en cas de succès et 1 en cas d'erreur d'allocation mémoire.
 */
int vigenere(char *s, char *key){
    size_t len_s = strlen(s);
    size_t len_key = strlen(key);
    size_t index_key = 0;
    char letter;
    char *msg = (char*) malloc((len_s + 1) * sizeof(char));
    if (msg == NULL) {
        fprintf(stderr, "Erreur\n");
        return 1;
    }
    msg[0] = '\0';
    for(int i = 0; i < len_s; i++){
        if(index_key == len_key){
            index_key = 0;
        }
        if(!isalpha(s[i])){
            continue;
        }
        letter = 'A'+(s[i]+key[index_key])%26;
        strncat(msg, &letter, 1);
        printf("%c + %c => %c\n", s[i], key[index_key], letter);
        index_key = index_key + 1;
    }
    printf("===> %s\n", msg);
    free(msg);
    return 0;
}

int main(int argc, char *argv){
    vigenere("HELLO WORLD", "CODE");
    return 0;
}
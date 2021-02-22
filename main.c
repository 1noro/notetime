
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "utils.h"


const int HEADER_LEN = 21; // tamaño exacto del hedaer
const int NOTE_MAXLEN = 280; // caracteres máximos de una nota (un tweet)


int main(int argc, char* argv[]) {
    // print_argv(argc, argv);
    
    // print header
    time_t now; // time_t is arithmetic time type
    time(&now); // Obtain current time: time() returns the current time of the system as a time_t value

    char header[HEADER_LEN]; // declaramos estática la variable del header
    get_datetime_header(now, header);
    printf("%s\n", header);

    // read note
    // (esto aquí no tien sentido, porque solo se hace un vez, pero luego, cuando se lea del archivo, hacerlo así será lo mejor)
    char* note;
    char note_aux[NOTE_MAXLEN];
    printf("> ");
    fgets(note_aux, NOTE_MAXLEN, stdin);
    n_to_0(NOTE_MAXLEN, note_aux);

    note = (char*) malloc((strlen(note_aux) + 1) * sizeof(char)); // se suma 1 a strlen porque no cuenta el \0 (caracter nulo de fin de string)
    if (note == NULL) {
        printf("Error al reservar memoria para 'note'\n");
        exit(1); // se acaba el programa con un número que no es 0 (error)
    }

    strcpy(note, note_aux); // destino, orogen

    printf("%s\n%s\n", header, note);

    free(note);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int HEADER_LEN = 21;
const int NOTE_MAXLEN = 280; // tweet

void get_datetime_header(time_t now, char *datetime_str) {
    // variables to store date and time components
    int hours, minutes, seconds, day, month, year;

    // localtime converts a time_t value to calendar time and
    // returns a pointer to a tm structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);

    hours = local->tm_hour;          // get hours since midnight (0-23)
    minutes = local->tm_min;         // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;         // get seconds passed after minute (0-59)

    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;       // get month of year (0 to 11)
    year = local->tm_year + 1900;    // get year since 1900

    // print current date
    // printf("[%02d-%02d-%d %02d:%02d:%02d]\n", day, month, year, hours, minutes, seconds);

    // char* out = (char*) malloc(21 * sizeof(char));
    sprintf(datetime_str, "[%02d-%02d-%d %02d:%02d:%02d]", day, month, year, hours, minutes, seconds);
}

// change \n to \0
void n_to_0(int str_len, char *str) {
    for (int i = 0; i < str_len; i++) {
        if (str[i] == '\n') str[i] = '\0';
    }
}

int main(int argc, char const *argv[]) {
    
    // print header
    time_t now; // time_t is arithmetic time type
    time(&now); // Obtain current time: time() returns the current time of the system as a time_t value

    char header[HEADER_LEN]; // declaramos estática la variable del header
    get_datetime_header(now, header);
    printf("%s\n", header);

    // read note
    // (esto aquí no tien sentido, porque solo se hace un vez, pero luego, cuando se lea del archivo, hacerlo así será lo mejor)
    char *note;
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


// https://github.com/portfoliocourses/c-example-code/blob/main/countdown_timer.c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60
#define SESSION_TIME_IN_MINUTES 50
#define SESSIONS 2
#define BREAK_MINUTES 10

void timer(int seconds, char arr[]);

int main(int argc, char ** argv) {
    /* int study_seconds = SESSION_TIME_IN_MINUTES * SECONDS_IN_MINUTE; */
    /* int break_seconds = BREAK_MINUTES * SECONDS_IN_MINUTE; */
    int study_seconds = 3;
    int break_seconds = 3;
    if (argc == 3) {
        /* in case of usage like: pomoc 25 15 */
        /* it's implied that time is specefied in minutes */
        study_seconds = atoi(argv[1]) * 60;
        break_seconds = atoi(argv[2]) * 60;
    }

    for (int s = 1; s <= SESSIONS; s++) {
        timer(study_seconds, "STUDY TIME");
        timer(break_seconds, "BREAK TIME");
    }
    printf("\rThat's all she wrote!\n");
    return 0;
}


void timer(int seconds, char arr[]) {
    int h = seconds / SECONDS_IN_HOUR;
    int m = (seconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
    int s = seconds % SECONDS_IN_MINUTE;

    while (seconds > 0) {
        printf("\r%s -> %02d:%02d:%02d", arr, h, m, s);

        fflush(stdout);

        clock_t stop = clock() + CLOCKS_PER_SEC;

        // When clock() DOES return the number of clock tics greater than
        // or equal to the expected numbe one second in the future, stop this
        // loop. This loop will thus cause the program to pause for one second.
        while (clock() < stop) { }
        seconds--;
    }
}

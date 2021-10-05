#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    time_t now;
    char day[10];
    time(&now);
    time_t ref;
    time(&ref);
    struct tm *ptmref = localtime(&ref);
    int time;
    int a = ptmref->tm_mday;
    int hours, minutes;
    if (argc > 1 && sscanf(argv[1], "%d%*1[hH,]%d", &hours, &minutes) == 2)
    {
        time = hours * 60;
        time = (time + minutes) * 60;
        now = now + time;
    }
    else
    {
        printf("Error: wrong input format. Example: 1h20");
        return 0;
    }

    struct tm *ptm = localtime(&now);

    if (ptm == NULL)
    {

        printf("Error during time calculation. Is your Linux setup correct?");
        return 1;
    }

    int b = ptm->tm_mday;
    if (a == b)
    {
        strncpy(day, "today", 10);
    }
    else
    {
        switch (ptm->tm_wday)
        {
        case 0:

            strncpy(day, "Sunday", 10);
            break;
        case 1:

            strncpy(day, "Monday", 10);
            break;
        case 2:

            strncpy(day, "Tuesday", 10);
            break;
        case 3:

            strncpy(day, "Wednesday", 10);
            break;
        case 4:

            strncpy(day, "Thursday", 10);
            break;
        case 5:

            strncpy(day, "Friday", 10);
            break;
        case 6:

            strncpy(day, "Saturday", 10);
            break;

        default:
            break;
        }
    }
    printf("Print finished @: %2s,%02d:%02d:%02d\n", day /*ptm->tm_wday*/, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

    return 0;
}

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define try bool __HadError = false;
#define catch (x) \
    ExitJmp:      \
    if (__HadError)
#define throw(x)       \
    __HadError = true; \
    goto ExitJmp;

int main(int argc, char const *argv[])
{
    time_t now;
    time_t reference;
    time(&now);
    time(&reference);
    char day[20];
    int time;

    int hours, minutes;
    if (argc > 1 && sscanf(argv[1], "%d%*1[hH,]%d", &hours, &minutes) == 2)
    {
        time = hours * 60;
        time = (time + minutes) * 60;
        now = now + time;
    }
    else
    {
        printf("e");
        return 0;
    }

    struct tm *ptm = localtime(&now);
    struct tm *today = localtime(&reference);

    if (ptm == NULL)
    {

        printf("Error during time calculation. Is your Linux setup correct?");
        return 1;
    }
    if(today->tm_wday==ptm->tm_wday){
        strncpy(day, "today",20);
    }else{
    switch (ptm->tm_wday)
    {
    case 0:

        strncpy(day, "Sunday", 20);
        break;
    case 1:

        strncpy(day, "Monday", 20);
        break;
    case 2:

        strncpy(day, "Tuesday", 20);
        break;
    case 3:

        strncpy(day, "Wednesday", 20);
        break;
    case 4:

        strncpy(day, "Thursday", 20);
        break;
    case 5:

        strncpy(day, "Friday", 20);
        break;
    case 6:

        strncpy(day, "Saturday", 20);
        break;

    default:
        break;
    }
}
    printf("Print finished @: %2s,%02d:%02d:%02d\n", day, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);


    return 0;
}

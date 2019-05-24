#include <stdio.h>

const char asterisk = '*';
const char *HAJJ = "Hajj";
const char *UMRAH = "Umrah";
const int max_length = 6;

const char *h_ak = "Hajj-e-Akbar";
const char *h_as = "Hajj-e-Asghar";

int check(int count, char *str)
{

    int i, match = 1;
    for (i = 0; i < 4; i++)
    {
        if (HAJJ[i] ^ str[i])
        {
            match = 0;
            break;
        }
    }

    if (match)
    {
        printf("Case %d: %s\n", count, h_ak);
        return 1;
    }

    match = 1;
    for (i = 0; i < 5; i++)
    {
        if (UMRAH[i] ^ str[i])
        {
            match = 0;
            break;
        }
    }

    if (match)
    {
        printf("Case %d: %s\n", count, h_as);
        return 1;
    }
    return 0;
}

void process()
{
    int count = 1;
    char buffer[max_length];
    while (fgets(buffer, sizeof(buffer), stdin) && (buffer[0] ^ asterisk))
    {
        if (check(count, buffer))
            count++;
    }
}

int main()
{
    process();
    return 0;
}
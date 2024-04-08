#include <stdio.h>

main()
{
    int i,j;
    scanf("%d", &i);
    scanf("%d", &j);
    if(i>0)
    {
        if(j>0) printf("1");
        else printf("4");
    }
    else
    {
        if(j>0) printf("2");
        else printf("3");
    }
    return 0;
}
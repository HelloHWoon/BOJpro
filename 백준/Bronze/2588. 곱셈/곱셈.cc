#include <stdio.h>

main()
{
    int A,B;
    scanf("%d %d", &A, &B);
    printf("%d\n", A*(B%10));
    printf("%d\n", A*(((B%100)-(B%10))/10));
    printf("%d\n", A*((B-(B%100))/100));
    printf("%d\n", A*B);
    return 0;
}
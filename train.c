#include <stdio.h>
#include <string.h>
int main(void)
{
    FILE *accounts;
    char str[] = "amir";
    accounts = fopen("accounts.txt", "w");
    printf("%d",sizeof(str));
    fwrite(str, 1, sizeof(str), accounts);
}
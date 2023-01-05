#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <string.h>
#define ZERO 0
#define ONE 1
#define true 2
char *username_and_password_reader(void)
{
    int username_length = ZERO;
    char *username = (char *)malloc(sizeof(char));
    *(username) = '0';
    char temp_char[ONE] = {' '};
    while (true)
    {
        temp_char[ZERO] = getchar();
        username_length++;
        username = (char *)realloc(username, sizeof(char) * username_length);
        username[username_length - ONE] = '\0';
        if (temp_char[ZERO] == ' ' || temp_char[ZERO] == '\n')
        {
            return username;
        }
        if (temp_char[ZERO] != ' ' && temp_char[ZERO] != '\n')
        {
            username[username_length - ONE] = temp_char[ZERO];
        }
    }
}
users *signup(users *headOfUsers, users *NewUser)
{
    users *checkDifference = headOfUsers->next; /*This temporary struct help us to check whether username chosen by user was uses already or not.*/
    char *userName = username_and_password_reader();
    char *password = username_and_password_reader();
    while (checkDifference != NULL)
    {

        if (!strcmp(checkDifference->username, userName))
        {
            printf("This username has already been chosen.Please try another one.\n");
            return NewUser;
        }
        else
        {
            checkDifference = checkDifference->next;
            printf("here\n");
        }
    }
    NewUser->next = (users *)malloc(sizeof(users));
    NewUser = NewUser->next;
    NewUser->next = NULL;
    int userNameLen = strlen(userName);
    NewUser->username = (char *)malloc(userNameLen * sizeof(char));
    strcpy(NewUser->username, userName);
    int passwordLen = strlen(password);
    NewUser->password = (char *)malloc(passwordLen * sizeof(char));
    strcpy(NewUser->password, password);
    printf("signed up successfully.\n");
    return NewUser;
}
char *login(users *headOfUsers, int *loginFlag, char **passwordOfCurrentUser)
{
    char *userName = username_and_password_reader();
    char *password = username_and_password_reader();
    *passwordOfCurrentUser = password;
    users *check_username_and_password = headOfUsers->next; /*This temporary struct is used to check if there is an account with this specific username and password and if there is we login if not we tell user ther is a problem in login.*/
    while (check_username_and_password != NULL)
    {
        if (!strcmp(check_username_and_password->username, userName))
        {
            if (!strcmp(check_username_and_password->password, password))
            {
                printf("Successfully logined\n");
                (*loginFlag) = ONE;
                return userName;
            }
            else
            {
                printf("Your password is wrong.Try again!\n");
                break;
            }
        }
        check_username_and_password = check_username_and_password->next;
    }
    printf("Your username or password is invalid!\n");
    return NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
char *find_userReader(void)
{
    int searchedUser_length = ZERO;
    char *searchedUser = (char *)malloc(sizeof(char));
    *(searchedUser) = '0';
    char temp_char[1] = {' '};
    while (true)
    {
        temp_char[ZERO] = getchar();
        searchedUser_length++;
        searchedUser = (char *)realloc(searchedUser, sizeof(char) * searchedUser_length);
        searchedUser[searchedUser_length - ONE] = '\0';
        if (temp_char[ZERO] == '\n')
        {
            return searchedUser;
        }
        if (temp_char[ZERO] != '\n')
        {
            searchedUser[searchedUser_length - ONE] = temp_char[ZERO];
        }
    }
}
void find_user(post *headOfPosts)
{
    char *searchedUser = find_userReader();
    printf("Username:%s\n",searchedUser);
    post *postsOfSearchedUser = headOfPosts->next;
    while (postsOfSearchedUser != NULL)
    {
        if (!strcmp(postsOfSearchedUser->owner, searchedUser))
        {
            printf("Post content:%s\n", postsOfSearchedUser->postContent);
            printf("Post ID:%d\tNumber of likes:%d\n", postsOfSearchedUser->post_id, postsOfSearchedUser->like);
        }
        postsOfSearchedUser = postsOfSearchedUser->next;
    }
}
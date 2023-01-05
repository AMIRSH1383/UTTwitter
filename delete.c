#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
void delete(post *headOfPosts, char *usernameOfCurrentUser)
{
    int deletingPost = ZERO;
    scanf("%d", &deletingPost);
    post *postsOfCurrentUser = headOfPosts->next;
    while (postsOfCurrentUser != NULL)
    {
        if ((!strcmp(headOfPosts->next->owner, usernameOfCurrentUser)) && headOfPosts->next->post_id == deletingPost)
        {
            headOfPosts->next = postsOfCurrentUser->next;
            free(postsOfCurrentUser);
            break;
        }
        if ((!strcmp(postsOfCurrentUser->next->owner, usernameOfCurrentUser)) && postsOfCurrentUser->next->post_id == deletingPost)
        {
            post *help = postsOfCurrentUser->next;
            postsOfCurrentUser->next = postsOfCurrentUser->next->next;
            free(help);
            break;
        }
        postsOfCurrentUser = postsOfCurrentUser->next;
    }
}
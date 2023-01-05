#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
void info(post *headOfPosts, char *usernameOfCurrentUser, char *passwordOfCurrentUser)
{
    post *showPostsOfUser = headOfPosts->next;
    printf("Username:%s\n", usernameOfCurrentUser);
    printf("Password:%s\n", passwordOfCurrentUser);
    while (showPostsOfUser != NULL)
    {
        if (!strcmp(showPostsOfUser->owner, usernameOfCurrentUser))
        {
            printf("Post content:%s\n", showPostsOfUser->postContent);
            printf("Post ID:%d\tNumber of likes:%d\n", showPostsOfUser->post_id, showPostsOfUser->like);
            /*بنويس كيا لايك كردنش!!!*/
        }
        showPostsOfUser = showPostsOfUser->next;
    }
}
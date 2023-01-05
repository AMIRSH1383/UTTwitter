#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
users *usersHeadMaker(void)
{
    users *head = (users *)malloc(sizeof(users));
    head->username = '\0';
    head->password = '\0';
    head->next = NULL;
    return head;
}
post *postsHeadMaker(void)
{
    post *head = (post *)malloc(sizeof(post));
    head->owner = '\0';
    head->postContent = '\0';
    head->post_id = ZERO;
    head->like = ZERO;
    head->likers = NULL;
    head->next = NULL;
    return head;
}
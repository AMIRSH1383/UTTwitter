#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
char *LikedUserReader(void)
{
    int likedUser_length = ZERO;
    char *likedUser = (char *)malloc(sizeof(char));
    *(likedUser) = '0';
    char temp_char[1] = {' '};
    while (true)
    {
        temp_char[ZERO] = getchar();
        likedUser_length++;
        likedUser = (char *)realloc(likedUser, sizeof(char) * likedUser_length);
        likedUser[likedUser_length - ONE] = '\0';
        if (temp_char[ZERO] == ' ')
        {
            return likedUser;
        }
        if (temp_char[ZERO] != ' ')
        {
            likedUser[likedUser_length - ONE] = temp_char[ZERO];
        }
    }
}
int like(post *headOfPosts, char *usernameOfCurrentUser)
{
    post *postToLike = headOfPosts->next;
    int likedPostID = ZERO;
    int likerNameLen = strlen(usernameOfCurrentUser);
    char *postOwner = LikedUserReader();
    scanf("%d", &likedPostID);
    while (postToLike != NULL)
    {
        if (!strcmp(postToLike->owner, postOwner) && postToLike->post_id == likedPostID)
        {
            users *likers = postToLike->likers;
            while (likers->next != NULL)
            {
                if (!strcmp(likers->next->username, usernameOfCurrentUser))
                {
                    printf("You liked this post one cannot like it!\n");
                    return -1;
                }
                likers = likers->next;
            }
            likers->next = (users *)malloc(sizeof(users));
            likers=likers->next;
            likers->username = (char *)malloc(likerNameLen + ONE * sizeof(char));
            strcpy(likers->username, usernameOfCurrentUser);
            (postToLike->like)++;
            return ZERO;
        }
        postToLike = postToLike->next;
    }
}
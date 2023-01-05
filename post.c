#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
char *postReader(void)
{
    int post_length = ZERO;
    char *post = (char *)malloc(sizeof(char));
    *(post) = '0';
    char temp_char[1] = {' '};
    while (true)
    {
        temp_char[ZERO] = getchar();
        post_length++;
        post = (char *)realloc(post, sizeof(char) * post_length);
        post[post_length - ONE] = '\0';
        if (temp_char[ZERO] == '\n')
        {
            return post;
        }
        if (temp_char[ZERO] != '\n')
        {
            post[post_length - ONE] = temp_char[ZERO];
        }
    }
}
post *postCreator(post *headOfPosts, post *NewPost, char *usernameOfCurrentUser)
{
    time_t t;
    srand((unsigned)time(&t));
    char *postText = postReader();
    int textLen = strlen(postText);
    int ownerLen = strlen(usernameOfCurrentUser);
    int flagPostID = ZERO;
    post *temp = headOfPosts->next;
    while (true)
    {
        if (temp == NULL)
        {
            NewPost->next = (post *)malloc(sizeof(post));
            NewPost = NewPost->next;
            NewPost->next = NULL;
            NewPost->owner = (char *)malloc((ownerLen + ONE) * sizeof(char));
            strcpy(NewPost->owner, usernameOfCurrentUser);
            NewPost->postContent = (char *)malloc((textLen + ONE) * sizeof(char));
            strcpy(NewPost->postContent, postText);
            NewPost->post_id = rand();
            NewPost->like = ZERO;
            NewPost->likers = (users *)malloc(sizeof(users));
            NewPost->likers->username = NULL;
            NewPost->likers->next = NULL;
            return NewPost;
        }
        temp = temp->next;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
int main(void)
{

    int loginFlag = 0;
    char *usernameOfCurrentUser;
    char *passwordOfCurrentUser;
    users *headOfUsers = usersHeadMaker();
    users *NewUser = headOfUsers;
    post *headOfPosts = postsHeadMaker();
    post *NewPost = headOfPosts;
    while (true)
    {
        while (loginFlag == ZERO)
        {
            printf("Please log in to your account.If you do not already have an account sign up.\n");
            char *commandType = commandReader();
            if (!strcmp(commandType, "signup"))
            {
                NewUser = signup(headOfUsers, NewUser);
            }
            if (!strcmp(commandType, "login"))
            {
                usernameOfCurrentUser = login(headOfUsers, &loginFlag, &passwordOfCurrentUser);
            }
            if (strcmp(commandType, "login") || strcmp(commandType, "signup"))
            {
                printf("Wrong command.\n");
            }
        }
        while (loginFlag == ONE)
        {
            printf("Choose your action between post,like,delete,info,find_user and logout:\n");
            char *commandType = commandReader();
            if (!strcmp(commandType, "logout"))
            {
                loginFlag = ZERO;
            }
            if (!strcmp(commandType, "post"))
            {
                NewPost = postCreator(headOfPosts, NewPost, usernameOfCurrentUser);
            }
            if (!strcmp(commandType, "info"))
            {
                info(headOfPosts, usernameOfCurrentUser, passwordOfCurrentUser);
            }
            if (!strcmp(commandType, "find_user"))
            {
                find_user(headOfPosts);
            }
            if (!strcmp(commandType, "delete"))
            {
                delete (headOfPosts, usernameOfCurrentUser);
                fflush(stdin);
            }
            if (!strcmp(commandType, "like"))
            {
                like(headOfPosts, usernameOfCurrentUser);
                fflush(stdin);
            }
            fflush(stdin);
            if (strcmp(commandType, "like") || strcmp(commandType, "delete") || strcmp(commandType, "find_user") || strcmp(commandType, "info") || strcmp(commandType, "post") || strcmp(commandType, "logout"))
            {
                printf("Wrong command.\n");
            }
            FILE *accounts;
            accounts = fopen("accounts.txt", "w");
            users *fileInfo = headOfUsers->next;
            while (fileInfo != NULL)
            {
                post *postInfo = headOfPosts->next;
                int numberOfPosts = ZERO;
                while (postInfo != NULL)
                {
                    if (!strcmp(postInfo->owner, fileInfo->username))
                    {
                        numberOfPosts++;
                    }
                    postInfo = postInfo->next;
                }
                fprintf(accounts, "%s %s %d\n", fileInfo->username, fileInfo->password, numberOfPosts);
                fileInfo = fileInfo->next;
            }
            fclose(accounts);
            FILE *posts;
            posts = fopen("posts.txt", "w");
            fileInfo = headOfUsers->next;
            while (fileInfo != NULL)
            {
                post *postInfo = headOfPosts->next;
                while (postInfo != NULL)
                {
                    if (!strcmp(postInfo->owner, fileInfo->username))
                    {
                        fprintf(posts, "%s %s %d\n", postInfo->postContent, postInfo->owner, postInfo->like);
                    }
                    postInfo = postInfo->next;
                }
                fileInfo = fileInfo->next;
            }
            fclose(posts);
        }
    }
}
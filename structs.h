typedef struct post post;
typedef struct info userInfo;
typedef struct searchOthers othersInfo;
typedef struct users users;
struct post
{
    char *owner;
    char *postContent;
    int post_id;
    int like;
    users *likers;
    post *next;
};
struct info
{
    char *username;
    char *password;
    post *post;
};
struct searchOthers
{
    char *username;
    post *post;
};
struct users
{
    char *username;
    char *password;
    users *next;
};
users *usersHeadMaker(void);
post *postsHeadMaker(void);
char *commandReader(void);
void delete(post *headOfPosts, char *usernameOfCurrentUser);
char *find_userReader(void);
void find_user(post *headOfPosts);
void info(post *headOfPosts, char *usernameOfCurrentUser, char *passwordOfCurrentUser);
char *LikedUserReader(void);
int like(post *headOfPosts, char *usernameOfCurrentUser);
char *postReader(void);
post *postCreator(post *headOfPosts, post *NewPost, char *usernameOfCurrentUser);
char *username_and_password_reader(void);
users *signup(users *headOfUsers, users *NewUser);
char *login(users *headOfUsers, int *loginFlag, char **passwordOfCurrentUser);
typedef struct date
{
    int day;
    int month;
    int year;
} date;

typedef struct letter
{
    char *sender;
    char **reciever;
    char *theme;
    char *body;
    int recievers_count;
    date send_date;

} letter;

typedef struct user
{
    char *name;
    letter **get_letters;

} user;

typedef struct buffer
{
    int size;
    int capacity;
} buffer;
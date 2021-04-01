#include "struct.h"

letter *create(char *filename, int *letters_count);
user *get_user(letter *letters_arr, char *user_name, int size, int *recieved_letters_count);
char **get_themes(user *current_user, date left, date right, int size, int *themes_count);
int more_or_equal(date x, date y);
void print_themes(char **themes_arr, int size);
int free_all(letter *letters_arr, user *users_arr, char **result, int letters_count, int recieved_letters_count, int themes_count);
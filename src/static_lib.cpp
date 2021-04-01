#include "../testy/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
letter *create(char *filename, int *letters_count)
{

    buffer letter_buf = {0, 10};
    buffer str_buf = {0, 5};
    letter *letters_arr = (letter *)malloc(letter_buf.capacity * sizeof(letter));
    if (letters_arr == NULL)
    {
        perror("Problems with realloc");
        return NULL;
    }

    FILE *fp = NULL;
    char c = 0;
    int str_pos = 0;
    int flag = 0;
    int recievers_index = 0;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return NULL;
    }

    while ((c = fgetc(fp)) != EOF)
    {

        if (c == '_')
        {
            str_pos++;
        }
        if (!((str_pos - 1) % 5))
        {
            if (!str_buf.size)
            {
                letters_arr[letter_buf.size].sender = (char *)malloc(str_buf.capacity * sizeof(char));
                if (letters_arr[letter_buf.size].sender == NULL)
                {
                    perror("Problems with malloc");
                    return NULL;
                }
            }
            if (str_buf.size == str_buf.capacity - 1)
            {
                str_buf.capacity *= 2;
                letters_arr[letter_buf.size].sender = (char *)realloc(letters_arr[letter_buf.size].sender, str_buf.capacity * sizeof(char));
                if (letters_arr[letter_buf.size].sender == NULL)
                {
                    perror("Problems with realloc");
                    return NULL;
                }
            }
            if (c == '`')
            {
                flag++;
                continue;
            }
            if (flag == 1)
            {
                letters_arr[letter_buf.size].sender[str_buf.size] = c;
                letters_arr[letter_buf.size].sender[str_buf.size + 1] = '\0';
                str_buf.size++;
            }
            if (c == '\n')
            {
                str_buf.capacity = 10;
                str_buf.size = 0;
                flag = 0;
            }
        }

        if (!((str_pos - 2) % 5))
        {
            if (c == '[')
            {
                fscanf(fp, "%d", &letters_arr[letter_buf.size].recievers_count);
            }

            if (!recievers_index && !str_buf.size)
            {
                letters_arr[letter_buf.size].reciever = (char **)malloc((letters_arr[letter_buf.size].recievers_count) * sizeof(char *));
                if (letters_arr[letter_buf.size].reciever == NULL)
                {
                    perror("Problems with malloc");
                    return NULL;
                }
                for (int i = 0; i < letters_arr[letter_buf.size].recievers_count; i++)
                {
                    letters_arr[letter_buf.size].reciever[i] = (char *)malloc(str_buf.capacity * sizeof(char));
                    if (letters_arr[letter_buf.size].reciever[i] == NULL)
                    {
                        perror("Problems with malloc");
                        return NULL;
                    }
                }
            }
            if (str_buf.size == str_buf.capacity - 1)
            {
                str_buf.capacity *= 2;
                letters_arr[letter_buf.size].reciever[recievers_index] = (char *)realloc(letters_arr[letter_buf.size].reciever[recievers_index], str_buf.capacity * sizeof(char));
                if (letters_arr[letter_buf.size].reciever[recievers_index] == NULL)
                {
                    perror("Problems with realloc");
                    return NULL;
                }
            }

            if (c == '`')
            {
                flag++;
                continue;
            }
            if (flag == 1)
            {
                letters_arr[letter_buf.size].reciever[recievers_index][str_buf.size] = c;
                letters_arr[letter_buf.size].reciever[recievers_index][str_buf.size + 1] = '\0';
                str_buf.size++;
            }
            if (c == ',')
            {
                str_buf.capacity = 10;
                str_buf.size = 0;
                flag = 0;
                recievers_index++;
            }
            if (c == '\n')
            {

                str_buf.capacity = 10;
                str_buf.size = 0;
                flag = 0;
                recievers_index = 0;
            }
        }

        if (!((str_pos - 3) % 5))
        {
            if (!str_buf.size)
            {
                letters_arr[letter_buf.size].theme = (char *)malloc(str_buf.capacity * sizeof(char));
                if (letters_arr[letter_buf.size].theme == NULL)
                {
                    perror("Problems with malloc");
                    return NULL;
                }
            }
            if (str_buf.size == str_buf.capacity - 1)
            {
                str_buf.capacity *= 2;

                letters_arr[letter_buf.size].theme = (char *)realloc(letters_arr[letter_buf.size].theme, str_buf.capacity * sizeof(char));
                if (letters_arr[letter_buf.size].theme == NULL)
                {
                    perror("Problems with realloc");
                    return NULL;
                }
            }
            if (c == '`')
            {
                flag++;
                continue;
            }
            if (flag == 1)
            {
                letters_arr[letter_buf.size].theme[str_buf.size] = c;
                letters_arr[letter_buf.size].theme[str_buf.size + 1] = '\0';
                str_buf.size++;
            }
            if (c == '\n')
            {
                str_buf.capacity = 10;
                str_buf.size = 0;
                flag = 0;
            }
        }

        if (!((str_pos - 4) % 5))
        {
            if (!str_buf.size)
            {
                letters_arr[letter_buf.size].body = (char *)malloc(str_buf.capacity * sizeof(char));
                if (letters_arr[letter_buf.size].body == NULL)
                {
                    perror("Problems with malloc");
                    return NULL;
                }
            }
            if (str_buf.size == str_buf.capacity - 1)
            {
                str_buf.capacity *= 2;
                letters_arr[letter_buf.size].body = (char *)realloc(letters_arr[letter_buf.size].body, str_buf.capacity * sizeof(char));
                if (letters_arr[letter_buf.size].body == NULL)
                {
                    perror("Problems with realloc");
                    return NULL;
                }
            }
            if (c == '`')
            {
                flag++;
                continue;
            }
            if (flag == 1)
            {
                letters_arr[letter_buf.size].body[str_buf.size] = c;
                letters_arr[letter_buf.size].body[str_buf.size + 1] = '\0';
                str_buf.size++;
            }
            if (c == '\n' && flag == 2)
            {
                str_buf.capacity = 10;
                str_buf.size = 0;
                flag = 0;
            }
        }
        if (!((str_pos - 5) % 5))
        {
            if (c == '`')
            {
                flag++;
            }
            if (flag == 1)
            {
                fscanf(fp, " %d/%d/%d", &letters_arr[letter_buf.size].send_date.day, &letters_arr[letter_buf.size].send_date.month, &letters_arr[letter_buf.size].send_date.year);
            }
            if (c == ';')
            {
                flag = 0;
                letter_buf.size++;
            }
            if (letter_buf.size == letter_buf.capacity - 1)
            {
                letter_buf.capacity *= 2;
                letters_arr = (letter *)realloc(letters_arr, letter_buf.capacity * sizeof(letter));
                if (letters_arr == NULL)
                {
                    perror("Problems with realloc");
                    return NULL;
                }
            }
        }
    }
    fclose(fp);
    *letters_count = letter_buf.size;
    return letters_arr;
}

int more_or_equal(date x, date y)
{
    if (x.year > y.year)
    {
        return 1;
    }
    else if (y.year > x.year)
    {
        return 0;
    }
    if (x.month > y.month)
    {
        return 1;
    }
    else if (y.month > x.month)
    {
        return 0;
    }
    if (x.day > y.day)
    {
        return 1;
    }
    else if (y.day > x.day)
    {
        return 0;
    }
    return 1;
}

user *get_user(letter *letters_arr, char *user_name, int size, int *recieved_letters_count)
{
    buffer users_buf = {0, 10};
    user *current_user = (user *)malloc(sizeof(user));
    if (current_user == NULL)
    {
        perror("Problems with realloc");
        return NULL;
    }

    current_user->name = NULL;
    current_user->get_letters = (letter **)malloc(users_buf.capacity * sizeof(letter *));
    if (current_user == NULL)
    {
        perror("Problems with malloc");
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < letters_arr[i].recievers_count; j++)
        {
            if (strcmp(letters_arr[i].reciever[j], user_name) == 0)
            {
                if (current_user->name == NULL)
                {
                    current_user->name = (char *)malloc((strlen(user_name) + 1) * sizeof(char));
                    if (current_user->name == NULL)
                    {
                        perror("Problems with malloc");
                        return NULL;
                    }

                    strcpy(current_user->name, user_name);
                }
                if (users_buf.size == users_buf.capacity - 1)
                {
                    users_buf.capacity *= 2;
                    current_user->get_letters = (letter **)realloc(current_user->get_letters, users_buf.capacity * sizeof(letter *));
                    if (current_user->get_letters == NULL)
                    {
                        perror("Problems with realloc");
                        return NULL;
                    }
                }
                current_user->get_letters[users_buf.size++] = &letters_arr[i];
            }
        }
    }
    *recieved_letters_count = users_buf.size;
    return current_user;
}

char **get_themes(user *current_user, date left, date right, int size, int *themes_count)
{
    buffer themes_buf = {0, 10};
    char **themes = (char **)malloc(themes_buf.capacity * sizeof(char *));
    if (themes == NULL)
    {
        perror("Problems with malloc");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        if (themes_buf.size == themes_buf.capacity - 1)
        {
            themes_buf.capacity *= 2;
            themes = (char **)realloc(themes, themes_buf.capacity * sizeof(char *));
            if (themes == NULL)
            {
                perror("Problems with realloc");
                return NULL;
            }
        }

        if (more_or_equal(current_user->get_letters[i]->send_date, left) && more_or_equal(right, current_user->get_letters[i]->send_date))
        {
            themes[themes_buf.size] = (char *)malloc((strlen(current_user->get_letters[i]->theme) + 1) * sizeof(char));
            if (themes[themes_buf.size] == NULL)
            {
                perror("Problems with malloc");
                return NULL;
            }
            strcpy(themes[themes_buf.size++], current_user->get_letters[i]->theme);
        }
    }
    *themes_count = themes_buf.size;
    return themes;
}

void print_themes(char **themes_arr, int size)
{
    if (!size)
    {
        printf("Nothing fined\n");
    }

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", themes_arr[i]);
    }
}

int free_all(letter *letters_arr, user *users_arr, char **result, int letters_count, int recieved_letters_count, int themes_count)
{
    for (int i = 0; i < letters_count; i++)
    {
        if (letters_arr[i].sender != NULL)
        {
            free(letters_arr[i].sender);
        }
        if (letters_arr[i].theme != NULL)
        {
            free(letters_arr[i].theme);
        }
        if (letters_arr[i].body)
        {
            free(letters_arr[i].body);
        }

        for (int j = 0; j < letters_arr[i].recievers_count; j++)
        {
            if (letters_arr[i].reciever[j] != NULL)
            {
                free(letters_arr[i].reciever[j]);
            }
        }
        if (letters_arr[i].reciever != NULL)
        {
            free(letters_arr[i].reciever);
        }
    }
    if (letters_arr != NULL)
    {
        free(letters_arr);
    }

    if (users_arr->name != NULL)
    {
        free(users_arr->name);
    }

    if (users_arr->get_letters != NULL)
    {
        free(users_arr->get_letters);
    }
    if (users_arr != NULL)
    {
        free(users_arr);
    }

    for (int i = 0; i < themes_count; i++)
    {
        if (result[i] != NULL)
        {
            free(result[i]);
        }
    }
    if (result != NULL)
    {
        free(result);
    }
}
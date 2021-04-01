#include <gtest/gtest.h>
#include "main.cpp"
#include <string.h>
#include <stdlib.h>

extern "C"
{
#include "../src/static_lib.cpp"
}

TEST(more_or_equalTests, more)
{
    {
        ASSERT_EQ(1, more_or_equal({12, 6, 2020}, {10, 5, 1000}));
    }
}

TEST(more_or_equalTests, less)
{
    {
        ASSERT_EQ(0, more_or_equal({12, 6, 202}, {10, 5, 1000}));
    }
}

TEST(more_or_equalTests, equal)
{
    {
        ASSERT_EQ(1, more_or_equal({12, 6, 2020}, {12, 6, 2020}));
    }
}

int letters_count = 0;
int recieved_letters_count = 0;
int themes_count = 0;

letter *letter_test = create("test_text/letters_1.txt", &letters_count);
user *user_test = get_user(letter_test, "Andre", letters_count, &recieved_letters_count);
date since = {10, 9, 1000};
date before = {30, 11, 2021};
char **result = get_themes(user_test, since, before, recieved_letters_count, &themes_count);

TEST(create, one_user)
{
    {
        ASSERT_EQ(1, letters_count);
        ASSERT_EQ(0, strcmp("Alex", letter_test[0].sender));
        ASSERT_EQ(0, strcmp("Andre", letter_test[0].reciever[0]));
        ASSERT_EQ(0, strcmp("ben123", letter_test[0].reciever[1]));
        ASSERT_EQ(0, strcmp("Football", letter_test[0].theme));
        ASSERT_EQ(0, strcmp("sdasdadsadasfasdaddfdsfsdfdsfsdf", letter_test[0].body));
        ASSERT_EQ(12, letter_test[0].send_date.day);
        ASSERT_EQ(8, letter_test[0].send_date.month);
        ASSERT_EQ(2020, letter_test[0].send_date.year);
    }
}

TEST(get_user, one_user)
{
    ASSERT_EQ(0, strcmp(user_test[0].name, "Andre"));
    ASSERT_EQ(0, strcmp(user_test[0].get_letters[0]->theme, "Football"));
}

TEST(get_themes, one_user)
{
    ASSERT_EQ(0, strcmp(result[0], "Football"));
}

TEST(create, empty_file)
{
    {
        int a = 0;
        create("", &a);
        ASSERT_EQ(0, a);
    }
}

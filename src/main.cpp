#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "static_lib.cpp"

int main(void)
{

  int letters_count = 0;
  letter *letters_arr = create("test_text/letters_1.txt", &letters_count);

  char *username = (char *)malloc(sizeof(char));
  scanf("%s", username);

  int recieved_letters_count = 0;
  user *current_user = get_user(letters_arr, "Andre", letters_count, &recieved_letters_count);

  date since;
  date before;
  scanf("%d/%d/%d", &since.day, &since.month, &since.year);
  scanf("%d/%d/%d", &before.day, &before.month, &before.year);

  int themes_count = 0;
  char **result = get_themes(current_user, since, before, recieved_letters_count, &themes_count);

  print_themes(result, themes_count);
  free_all(letters_arr, current_user, result, letters_count, recieved_letters_count, themes_count);

  return 0;
}

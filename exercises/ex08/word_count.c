#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
  printf(user_data, (char *) key, *(int *) value);
}

int main(int argc, char** argv) {

  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

  FILE* file = fopen("lorem_ipsum.txt", "r");
  char word_buffer[1024];
  gint16 index = 0;
  gchar temp_char;

  while((temp_char = fgetc(file)) != EOF) {

    switch(temp_char) {

      // Ignore punctuation by skipping it
      case '.': case ',': case '?': case '!':
        break;

      // If we reach the end of a word
      case ' ': case '\n': case '\t':

        word_buffer[index] = g_unichar_tolower(temp_char);

        if (index <= 1) {
          index = 0;
          break;
        }

        // Add null terminator at end of word
        word_buffer[index] = '\0';
        index++;

        // If the word is already in the hash table
        if(g_hash_table_contains(hash, word_buffer)) {

          // Get the old int pointer and increment it by 1, then update the hash table
          int *old_value = (int *) g_hash_table_lookup(hash, word_buffer);
          *old_value = *old_value + 1;
          g_hash_table_replace(hash, g_strdup(word_buffer), old_value);

        // If the word is not already in the hash table
        } else {

          // Create a new int pointer, set it to 1, and add to the hash table
          int *new_value = malloc(sizeof(int));
          *new_value = 1;
          g_hash_table_insert(hash, g_strdup(word_buffer), new_value);

        }

        index = 0;
        break;

      // The word is continuing, so add this char to the buffer
      default:

        word_buffer[index] = g_unichar_tolower(temp_char);
        index++;

    }
  }

  // Go through all keys and values and print them using the iterator function
  g_hash_table_foreach(hash, (GHFunc)iterator, "%s: %d\n");

  return 0;
}
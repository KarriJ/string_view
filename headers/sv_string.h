#pragma once


#include <string.h>
#include <stdbool.h>

typedef struct 
{
    const char *data;
    int count;
} String_view;

#define SV_Fmt "%.*s"
#define SV_Arg(sv) (sv).count, (sv).data

String_view sv_decimite(String_view *sv, char delimiter);
String_view sv_split(String_view *sv, int idx);
String_view sv_replace(String_view *sv, int replace_idx, char new_char);
String_view sv_new(char string[]);
int sv_index(String_view *sv, char character);
int sv_count(String_view *sv, char character);
bool sv_compare(String_view *string1, String_view *string2);
bool sv_get_char(String_view *sv, char *character, int idx);
void sv_pop_left(String_view *string, int pop_length);
void sv_pop_right(String_view *string, int pop_length);
bool empty(String_view *sv);
int sv_length(String_view *sv);

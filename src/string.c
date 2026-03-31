#include <string.h>
#include <stdbool.h>

typedef struct 
{
    const char *data;
    int count;
} String_view;

#define SV_Fmt "%.*s"
#define SV_Arg(sv) (sv).count, (sv).data

String_view sv_new(char string[])
{   
    return (String_view) {
        string,
        (int)strlen(string) 
    };
}

void sv_pop_left(String_view *string, int pop_length)
{
    if (string->count < pop_length)
    {
        string->count = 0;

        return;
    }

    string->count -= pop_length;
    string->data += pop_length;

    return;
}

void sv_pop_right(String_view *string, int pop_length)
{
    if (string->count < pop_length)
    {
        string->count = 0;

        return;
    }

    (*string).count -= pop_length;

    return;
}

int sv_index(String_view *sv, char character)
{
    for (int idx = 0; idx < sv->count; idx++)
    {
        if (sv->data[idx] == character)
        {
            return idx;    
        }
    }

    return -1;
}

bool sv_get_char(String_view *sv, char *character, int idx)
{
    if (sv-> count < idx)
    {
        return false;
    }

    (*character) = sv->data[idx];

    return true;
}

bool empty(String_view *sv)
{
    if (sv->count == 0)
    {
        return true;
    }

    return false;
}

bool sv_compare(String_view *string1, String_view *string2) 
{
    if (string1->count != string2->count)
    {
        return false;
    }

    for (int idx = 0; idx < string1->count; idx++)
    {
        if (string1->data[idx] != string2->data[idx])
        {
            return false;
        }
    }

    return true;
}

int sv_count(String_view *sv, char character)
{
    int result = 0;
    for (int idx = 0; idx < sv->count; idx++)
    {
        if (sv->data[idx] == character)
        {
            result += 1;
        }
    }

    return result;
}

String_view sv_replace(String_view *sv, int replace_idx, char new_char)
{
    if (sv->count < replace_idx)
    {
        return sv_new("");
    }

    char buffer[sv->count];
    for (int idx = 0; idx < sv->count; idx++)
    {
        buffer[idx] = sv->data[idx];
    }

    buffer[replace_idx] = new_char;

    return (String_view) {
        buffer, 
        sv->count 
    };
}

String_view sv_split(String_view *sv, int idx)
{
    if (sv->count < idx)
    {
        return sv_new("");
    }

    String_view new_string = {
        sv->data + idx,
        sv->count - idx
    };

    sv_pop_right(sv, sv->count - idx);
    return new_string;
}

String_view sv_decimite(String_view *sv, char delimiter)
{   
    // If at -1, no delimiter was found 
    int split_index = sv_index(sv, delimiter);

    // return new empty string if no delimiter was found
    if (split_index == -1)
    {
        return sv_new("");  
    }
    
    // Initialize new string
    String_view new_string = {
        sv->data + split_index + 1,
        sv->count - split_index + 1
    };

    // Right pop old string to delimiter
    sv_pop_right(sv, sv->count - split_index);
    return new_string;
}

int sv_length(String_view *sv)
{
    return sv->count;
}

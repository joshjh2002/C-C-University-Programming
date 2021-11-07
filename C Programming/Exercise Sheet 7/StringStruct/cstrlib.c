#include "cstrlib.h"

void str_init(char const *str, str_t *out)
{
    out->string = str;
    out->hash = str_hash(out);
    out->length = str_len(out);
}

void str_cpy(str_t *in, str_t *out)
{
    out->string = in->string;
    out->length = in->length;
    out->hash = in->hash;
}

int str_len(str_t *str)
{
    int i = 0;
    while (str->string[i] != '\0')
    {
        i++;
    }
    return i;
}

int str_hash(str_t *str)
{
    char const *stri = str->string;
    int i = 0;
    int counter = 0;
    for (i = 0; i < str->length; i++)
    {
        counter += counter * 1223 + *stri;
    }
    return counter;
}

bool str_equal(str_t *a, str_t *b)
{
    return str_cmp(a, b);
}

int str_cmp(str_t *a, str_t *b)
{
    if (a->length != b->length)
        return a->length - b->length;
    else if (a->hash != b->hash)
        return a->hash - b->hash;

    return strcmp(a->string, b->string);
}
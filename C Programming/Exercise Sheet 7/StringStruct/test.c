#include "cstrlib.h"
#include <stdio.h>


void main(int argc, char *args[])
{
    //initialise structure
    str_t mystruct;
    str_init(args[1], &mystruct);
}
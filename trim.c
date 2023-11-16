#include "shells.h"

/**
 * trim_start - removes white space from the beggining
 * @s: pointer to a pointer to string
 * Description: removes white space from start or nothing                                        */                                                                                             
void trim_start(char **s)
{
        int i = 0;
        int index = 0;

        if ((*s)[index] == ' ' || (*s)[index] == '\t')
        {
                while ((*s)[index] == ' ' || (*s)[index] == '\t')
                {
                        index++;
                }

        }
        if (index > 0)
        {
                while ((*s)[index + i])
                {
                        (*s)[i] = (*s)[index + i];
                        i++;
                }

                (*s)[i] = '\0';
        }

}

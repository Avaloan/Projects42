#include <stdio.h>

struct lol 
{
    char reader[64];
};

// void print(char*pt)
// {
//     for (size_t i = 0; i < 64; i++)
//     {
//         printf("%c", pt[i]);
//     }
    
// }

int main()
{
    char tamer[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam cursus vel erat ac molestie. Vestibulum eleifend lectus nec posuere lacinia. Praesent at metus nec nisl eleifend varius et augue."; 
    void *tmp = tamer;

    struct lol *test;
    test = tmp;
    // test = (struct lol*)((char*)tmp + (63 * 1));

    for (size_t i = 1; i < 4; i++)
    {
        // print(test->reader);
        printf("\n");
        test = (struct lol*)((char*)tmp + 64 * i);
    }
    
}


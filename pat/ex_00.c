#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * the Mac show enter a.out 12 \* 
 */
int main()
{
    int n;
    char c;
    void print_sand_clock(int, char);
    scanf("%d %c", &n, &c);
    if (n < 1 || n > 10000) {
        return 0;
    }

    print_sand_clock(n, c);
    return 0;
}




void print_line(int n, char c, int line_max_char_num)
{
    int white_num = (line_max_char_num - n) >> 1; // I also know the compiler will do it
    int i = 0;
    while (i++ < white_num) {
        printf(" ");
    }
    for (i = 0; i < n; i++) {
        printf("%c", c);
    }
    //it's so stupid, waste 2 hours to though pat..
    /*
    for (i = 0; i < white_num; i++) {
        printf(" ");
    }
    */
    printf("\n");

}


void print_sand_clock(int n, char c)
{
    void print_line(int, char, int);
    if (n < 0) {
        //printf("%d is negative!\n", n);
        return ;
    }

    int line_char_num, line_max_char_num, sum;
    line_char_num = 1; sum = 1;
    while (1) {
        line_char_num += 2;
        sum += line_char_num << 1;
        if (sum > n) 
        {   
            line_max_char_num = line_char_num - 2;
            sum -= line_char_num << 1;
            break;
        }
    }
   
    for (line_char_num = line_max_char_num; line_char_num > 1; line_char_num-=2) {
        print_line(line_char_num, c, line_max_char_num);
    }
    print_line(1, c, line_max_char_num);
    for (line_char_num = 3; line_char_num <= line_max_char_num; line_char_num += 2) {
        print_line(line_char_num, c, line_max_char_num);
    }

    printf("%d\n", n - sum);

}
#include <stdio.h>
#include <string.h>

/*
 * 实现一个函数，把字符串中的每个空格替换为"%20"。
 * 例如，输入"We are happy."，则输出"WE%20are%20happy."
 */

 void ReplaceBlank(char* string, int length)
 {
    if (string == NULL || length == 0)
        return;

    int blankCount = 0;
    int i;
    for(i = 0; i < length; i++) {
        if(string[i] == ' ') {
            blankCount++;
        }
    }

    for(i = length - 1; i >= 0; i--) {
        if (string[i] != ' ') {
            string[i + blankCount * 2] = string[i];
        } else {
            blankCount--;
            string[i + blankCount * 2] = '%';
            string[i + blankCount * 2 + 1] = '2';
            string[i + blankCount * 2 + 2] = '0';
        }
    }
 }

 void test1(){
    char str[20] = "We are happy.";
    printf("Original string: %s\n", str);
    ReplaceBlank(str, 0);
    printf("Replaced: %s\n", str);
 }

 int main(int argc, char** argv)
 {
     test1();
 }

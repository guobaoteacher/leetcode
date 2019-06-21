/**
 * Given a string, find the length of the longest substring without repeating characters.
 */
#include <stdio.h>
#include <stdlib.h>

//返回第一个字串长度
int lengthOfFirstSubstring(char * s){
    int i, j;
    int count = 0;
    for(int i = 0; s[i] != NULL; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if (s[j] == s[i])
            {
                return count;
            }
        }
        count++;
    }
    return count;
}

int lengthOfLongestSubstring(char * s){
    int i;
    int max = 0;    //最长字串长度
    int count = 0;  //记录字串的长度

    for (i = 0; s[i] != NULL; i++)
    {
        count = lengthOfFirstSubstring(&s[i]);

        if (max < count)
        {
            max = count;
        }
    }

    return max;
}

int main(void)
{
    char s[] = "pwwkew";
    printf("%d\n", lengthOfLongestSubstring(s));

    system("pause");
    return 0;

}
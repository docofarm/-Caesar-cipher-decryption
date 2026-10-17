#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    /* 원하는 shift값 입력
    if (argc < 3)
    {
        printf("EXAM: test.exe <text> <shift>\n");
        return 1;
    }
    int shift = atoi(argv[2]) % 26;
    */

    // 자동 해독
    if (argc < 2)
    {
        printf("EXAM: test.exe <text>");
        return 1;
    }

    // 입력받은 문자열
    char *plain = argv[1];
    size_t plainlength = strlen(plain);

    // 출력 반복
    for (int shift = 0; shift < 26; shift++)
    {
        printf("SHIFT %d => ", shift);
        for (size_t i = 0; i < plainlength; i++)
        {
            // 복호화
            if (plain[i] >= 'A' && plain[i] <= 'Z')
            {
                char result = ((plain[i] - 'A' - shift + 26) % 26) + 'A';
                printf("%c", result);
            }
            else
            {
                char result = plain[i];
                printf("%c", result);
            }
        }
        printf("\n");
    }

    return 0;
}
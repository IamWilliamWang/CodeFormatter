#ifndef CHARACTERUTIL
#define CHARACTERUTIL

char output[1500];
int inputIndex=0;
int outputIndex=0;
char *input;

/**
 * @brief GetCharacter 每次获得字符串input中的一个字符
 * @return 获得的字符
 */
char GetCharacter()
{
    return input[inputIndex++];
}

/**
 * @brief SetCharacter 给output每次放一个字符
 * @param ch 要放置的字符
 */
void SetCharacter(char ch)
{
    output[outputIndex++]=ch;
}

#endif // CHARACTERUTIL


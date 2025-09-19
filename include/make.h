#include<stdbool.h>

//去除行尾空格
void rtrim(char *line);
//判断是否是空行
bool is_blank(const char *line);
//去除注释
void remove_comment(char *line);

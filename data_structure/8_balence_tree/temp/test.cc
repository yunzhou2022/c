#include "fruit.c"
#include <cstring>
#include <iostream>

int main() {
  // 测试查找单词
  const char *testWord1 = "apple";
  const char *result1 = Perfect_Hash::in_word_set(testWord1, strlen(testWord1));
  if (result1) {
    std::cout << "找到单词: " << result1 << std::endl;
  } else {
    std::cout << "未找到单词: " << testWord1 << std::endl;
  }

  const char *testWord2 = "grape";
  const char *result2 = Perfect_Hash::in_word_set(testWord2, strlen(testWord2));
  if (result2) {
    std::cout << "找到单词: " << result2 << std::endl;
  } else {
    std::cout << "未找到单词: " << testWord2 << std::endl;
  }

  return 0;
}

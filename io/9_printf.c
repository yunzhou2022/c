#include <stdarg.h>
#include <stdio.h>

#define TEST(format, args...)                                                  \
  ({                                                                           \
    int n1, n2;                                                                \
    n1 = printf(format, ##args);                                               \
    n2 = my_printf(format, ##args);                                            \
    printf("n1 = %d, n2 = %d\n\n\n", n1, n2);                                  \
  })

char base16_code (int num){
    if(num<10) return num+'0';
    return num-10+'a';
}

int my_printf(const char *format, ...) {
#define PUTC(c) putchar(c), cnt++
  int cnt = 0;
  int i = 0;
  char c;
  va_list args;
  va_start(args, format);
  for (int i = 0; format[i]; i++) {
    switch (format[i]) {
    case '%': {
      switch (format[i + 1]) {
      case '%': {
        PUTC('%');
        i++;
      } break;
      case 's': {
        const char *s = va_arg(args, const char *);
        for (int j = 0; s[j]; j++)
          PUTC(s[j]);
        i++;
      } break;
      case 'd': {
        int num = va_arg(args, int);
        int8_t arr[20];
        int len = 0;
        int flag = (num < 0);
        do {
          arr[len++] = num % 10;
          num /= 10;
        } while (num);
        if (flag)
          PUTC('-');
        for (int j = len - 1; j >= 0; j--) {
          if (flag)
            PUTC(-arr[j] + '0');
          else
            PUTC(arr[j] + '0');
        }
        i++;
      } break;
      case 'x': {
        unsigned int num = va_arg(args, unsigned int);
        int arr[20];
        int len =0;
        do{
           arr[len++] = num%16;
           num/=16;
        }while(num);
        for(int i=len-1;i>=0;i--){
            PUTC(base16_code(arr[i]));
        }
        i++;
      }
      }
      break;
    }
    default:
      PUTC(format[i]);
      break;
    }
  }
  return cnt;
}

int main() {
  TEST("hello, world\n");
  TEST("100%%\n");
  TEST("hello, %s\n", "100%%");
  TEST("MAX: %d, MIN: %d\n", 0x7fffffff, 0x80000000);
  TEST("zero is %d\n", 0);
  TEST("123 = %x, -1=%x, 0x80000000=%x\n", 123, -1, 0x80000000);
  return 0;
}

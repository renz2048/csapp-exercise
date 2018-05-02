#include "show_bytes.h"
#include "string.h"

int main()
{
  const char *s = "abcdef";
  show_bytes((byte_pointer) s, strlen(s));
  return 0;
}

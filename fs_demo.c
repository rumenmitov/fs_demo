#include <stdint.h>

uint32_t phantom_mkdir(const char *path);
uint32_t phantom_fwrite(const char *path, void *buf, uint32_t bufsize);
uint32_t phantom_rename(const char *oldpath, const char *newpath);
uint32_t phantom_fread(const char *path, void *buf, uint32_t bufsize);
uint64_t phantom_gettime_us(void);

enum
{
  READS = 10,
};


int main(int argc, char *argv[])
{
  char message[1024];

  uint64_t start = phantom_gettime_us();

  for (int i = 0; i < READS; ++i) {
    (void)phantom_fread("bar", message, sizeof(message));
  }

  uint64_t end = phantom_gettime_us();

	return end - start;
}

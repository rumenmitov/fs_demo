#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t phantom_mkdir(const char *path);
uint32_t phantom_fwrite(const char *path, void *buf, uint32_t bufsize);
uint32_t phantom_rename(const char *oldpath, const char *newpath);           
uint32_t phantom_fread(const char *path, void *buf, uint32_t bufsize);

static char *message = "baz";

int main(int argc, char *argv[])
{
	char *buf = malloc(strlen(message) + 1);
	buf[strlen(message)] = 0;

	(void)phantom_mkdir("foo");
	(void)phantom_fwrite("foo/bar.txt", message, strlen(message));
	(void)phantom_rename("foo/bar.txt", "foo/bat.txt");
	(void)phantom_fread("foo/bat.txt", buf, strlen(message));

	return (strncmp(message, buf, strlen(message)));
}

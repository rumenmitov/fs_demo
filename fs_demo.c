#include "phantom_api.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>


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

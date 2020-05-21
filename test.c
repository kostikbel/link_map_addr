#include <sys/param.h>
#include <dlfcn.h>
#include <link.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	void *handle;
	struct link_map *l;
	int error;

	handle = dlopen("libtest.so", RTLD_LAZY | RTLD_GLOBAL);
	if (handle == NULL) {
		fprintf(stderr, "dlopen %s\n", dlerror());
		exit(1);
	}

	error = dlinfo(handle, RTLD_DI_LINKMAP, &l);
	if (error == -1) {
		fprintf(stderr, "dlinfo RTLD_DI_LINKMAP %s\n", dlerror());
		exit(1);
	}

	printf("addr %p name %s dyn %p\n", l->l_addr, l->l_name, l->l_ld);
}


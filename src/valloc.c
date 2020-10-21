#include "bench.h"

void *valloc(size_t size) {
	long pagesize = -1;
#ifdef _SC_PAGESIZE
	pagesize = sysconf(_SC_PAGESIZE);
#endif
	if (pagesize < 0)
		pagesize = 4096;
	return memalign(pagesize, size);
}

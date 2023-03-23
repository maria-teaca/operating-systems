/* SPDX-License-Identifier: BSD-3-Clause */

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	mode_t mode = 0;

	// mode argument required for these flags only
	if ((flags & O_CREAT) || (flags & O_TMPFILE) == O_TMPFILE) {
		va_list valist;
		va_start(valist, flags);
		mode = va_arg(valist, mode_t);
		va_end(valist);
	}

	// call open
	int fd = syscall(2, filename, flags, mode);
	if (fd >= 0 && (flags & O_CLOEXEC))
		// set exec permission
		syscall(72, fd, F_SETFD, FD_CLOEXEC);

	return fd;
}

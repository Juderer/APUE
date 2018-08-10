#ifndef _ERROR_H_
#define _ERROR_H_

#include <errno.h>
#include <stdarg.h>

#define MAXLINE 4096

void	err_msg(const char *, ...);
void	err_quit(const char *, ...);
void	err_ret(const char *, ...);
void 	err_sys(const char *, ...);
void 	err_dump(const char *, ...);

#endif

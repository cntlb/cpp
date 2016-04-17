#ifndef __IO_H
#define __IO_H

#include <sys/types.h>
//实现shell指令cp和cat
void copy(int fd_in, int fd_out);

int set_flag(int fd, int flag);

int lock_reg(int fd, int cmd, short l_type, short l_whence, off_t l_start, off_t l_len);

//建议性读锁(非等待性共享读锁)
#define READ_LOCK(fd, l_whence, l_start, l_len) \
    lock_reg(fd, F_SETLK, F_RDLCK, l_whence, l_start, l_len)

//强制性读锁(等待性共享读锁)
#define READ_LOCKW(fd, l_whence, l_start, l_len) \
    lock_reg(fd, F_SETLKW, F_RDLCK, l_whence, l_start, l_len)

//建议性写锁(非等待性独占写锁)
#define WRITE_LOCK(fd, l_whence, l_start, l_len) \
    lock_reg(fd, F_SETLK, F_WRLCK, l_whence, l_start, l_len)

//强制性写锁(等待性独占写锁)
#define WRITE_LOCKW(fd, l_whence, l_start, l_len) \
    lock_reg(fd, F_SETLKW, F_WRLCK, l_whence, l_start, l_len)
    
//解锁
#define UNLOCK(fd, l_whence, l_start, l_len) \
    lock_reg(fd, F_SETLKW, F_UNLCK, l_whence, l_start, l_len)

#endif //__IO_H

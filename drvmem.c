#include "types.h"
#include "defs.h"
#include "param.h"
#include "traps.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

int
drvmemread(struct inode *ip, char *dst, int n, uint off)
{
    switch(ip->minor) 
    {
    case DEV_NULL:
        return 0;

    case DEV_ZERO:
        memset(dst, 0, n);
        return n;

    case DEV_MEM:
        if (off >= PHYSTOP || off + n > PHYSTOP)
            return -1;
            
        memmove(dst, (char*)P2V(off), n);
        return n;
    }

    return -2;
}

int 
drvmemwrite(struct inode *ip, char *src, int n, uint off)
{
    return n;
}

void 
drvmeminit(void) 
{
    devsw[DEV].write = drvmemwrite;
    devsw[DEV].read = drvmemread;
}
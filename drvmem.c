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
    if (ip->minor == DEV_NULL)
        return 0;

    if (ip->minor == DEV_ZERO) 
    {
        memset(dst, 0, n);
        return n;
    }

    return -1;
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
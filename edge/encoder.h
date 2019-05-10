#ifndef ENCODER_H
#define ENCODER_H

#include <linux/types.h>
#include <asm/ioctl.h>

// Device # unused from ioctl-number.txt
#define MAGICNUM 0xA4

// Macros for using ioctl (getting/setting delay from userspace)  
#define EDGE_IOCGDELAY _IOR(MAGICNUM, 0, int)
#define EDGE_IOCSDELAY _IOW(MAGICNUM, 1, int)

#endif

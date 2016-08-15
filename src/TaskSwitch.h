#ifndef __TASK_SWITCH_H__
#define __TASK_SWITCH_H__

#include <stdint.h>

void pushRegs(void);
void currentSp(void);
void updateSp(void);

#endif

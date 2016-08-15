#include "TCB.h"
#include "LinkedList.h"

Tcb mainTcb;
Tcb task1Tcb;
Tcb task2Tcb;
Tcb task3Tcb;

void initMainTcb() {
	mainTcb.name = "task_main";
	mainTcb.sp	  = (uint32_t)&mainTcb.virtualStack[TASK_STACK_SIZE];
	AddLast((ListElement *)&mainTcb,&tcbList);
}

void initTcb1() {
	task1Tcb.name = "task_1";
	task1Tcb.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE];
	AddLast((ListElement *)&task1Tcb,&tcbList);
}

void initTcb2() {
	task2Tcb.name = "task_2";
	task2Tcb.sp	  = (uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE];
	AddLast((ListElement *)&task2Tcb,&tcbList);
}

void initTcb3() {
	task3Tcb.name = "task_3";
	task3Tcb.sp	  = (uint32_t)&task3Tcb.virtualStack[TASK_STACK_SIZE];
	AddLast((ListElement *)&task3Tcb,&tcbList);
}

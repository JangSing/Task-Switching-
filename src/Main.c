/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"
#include "SaveRegister.h"
#include "TCB.h"
#include "LinkedList.h"
#include "TaskSwitch.h"

uint32_t virtualSp;
uint32_t taskFunction;

void task1(){
	while(1){}
}

void task2(){
	while(1){}
}

void task3(){
	while(1){}
}


int main() {
  linkedListInit(&tcbList);
	
  initMainTcb();
  
  taskFunction = (uint32_t)task1;
  initTcb1();
  virtualSp = task1Tcb.sp;
  pushRegs();
  task1Tcb.sp = virtualSp;
  
  taskFunction = (uint32_t)task2;
  initTcb2();
  virtualSp = task2Tcb.sp;
  pushRegs();
  task2Tcb.sp = virtualSp;
  
  taskFunction = (uint32_t)task3;
  initTcb3();
  virtualSp = task3Tcb.sp;
  pushRegs();
  task3Tcb.sp = virtualSp;
  
  initSysTick();
  
  while(1) {}
  
}

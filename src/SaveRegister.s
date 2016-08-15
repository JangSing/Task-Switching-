								PRESERVE8
                THUMB

; Global data


                AREA    MyCode, CODE, READONLY

saveRegs		  	PROC
                EXPORT  saveRegs
                IMPORT  task1Tcb
								IMPORT	virtualSp

								ldr   r0,[r13]									; load the cpu sp to r0

                ldr   r13,=virtualSp						; point r13 to virtual stack
								ldr   r13,[r13]									; update sp to virtual stack

								mov	  r1,   #0x22222222
								mov	  r2,   #0x33333333
								mov	  r3,   #0x44444444
								mov	  r4,   #0x55555555
								mov	  r5,   #0x66666666
								mov	  r6,   #0x77777777
								mov	  r7,   #0x88888888
								mov	  r8,   #0x99999999
								mov	  r9,   #0xAAAAAAAA
								mov	  r10,  #0xBBBBBBBB
								mov	  r11,  #0xCCCCCCCC
								mov	  r12,  #0xDDDDDDDD

								push	  {r0-r12}						; Look at the stack memory under 'View->Memory 1'
								push	 	{lr}
								pop			{lr}


								ldr			r8, =virtualSp			; point  r8 to virtualSp
								str			r13, [r8]						; store r13 to virtualsp

								ldr			r13, [r0]						; load cpu sp

								bx			lr									; Return to our caller

								ENDP
								END
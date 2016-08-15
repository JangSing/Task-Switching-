								PRESERVE8
                THUMB


; Global data

                AREA    MyCode, CODE, READONLY

pushRegs		  	PROC
                EXPORT  pushRegs
								IMPORT	virtualSp
								IMPORT  taskFunction

								ldr   r0,[r13]									; load the cpu sp to r0

                ldr   r13,=virtualSp						; point sp to virtual stack
								ldr   r13,[r13]									; update sp to virtual stack

								ldr   r9,=taskFunction					; point pc to taskFunction
								ldr   r9,[r9]										; update pc to taskFunction

								mov	  r10,  #0x01000000					;xPSR
								mov	  r8,   #0x44444444					;LR
								mov	  r7,   #0x55555555					;R12
								mov	  r6,   #0x66666666         ;R3
								mov	  r5,   #0x77777777         ;R2
								mov	  r4,   #0x88888888         ;R1
								mov	  r3,   #0x99999999         ;R0
                
                ;two register that pushed automatically by the assembler
								mov   r2,   #0xFFFFFFF9         ;LR
								mov		r1,   #0x00000000         ;R4

								push	  {r1-r10}						; push the selected register

								ldr			r8, =virtualSp			; point  r8 to virtualSp
								str			r13, [r8]						; store r13 to virtualsp

								ldr			r13, [r0]						; load back to cpu sp

								bx			lr									; Return to caller

								ENDP


currentSp				PROC
								EXPORT	currentSp
								IMPORT	currSp

								ldr			r8, =currSp			    ; point  r8 to currSp
								str			r13, [r8]						; store r13 to currSp

								bx 			lr

								ENDP

updateSp				PROC
								EXPORT	updateSp
								IMPORT	currSp

								ldr			r13, =currSp			    ; point  r13 to currSp
								ldr			r13, [r13]						; store r13 to currsp

								bx 			lr

								ENDP

								END

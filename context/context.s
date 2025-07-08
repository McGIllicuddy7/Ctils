
.globl _create_context
_create_context:
	mov sp,x0
	mov fp, x0
	stp fp, lr,[sp, #-0x10]!
	stp x0, x1, [sp, #-0x10]!
	bl _proc_call_thunk


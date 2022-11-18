	.cpu cortex-m4
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"app_main.c"
	.text
	.global	Array_Sprints
	.data
	.align	2
	.type	Array_Sprints, %object
	.size	Array_Sprints, 16
Array_Sprints:
	.word	1
	.word	4
	.word	6
	.word	8
	.global	Array_Sprints_base_address
	.align	2
	.type	Array_Sprints_base_address, %object
	.size	Array_Sprints_base_address, 4
Array_Sprints_base_address:
	.word	4096
	.text
	.align	1
	.global	main
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r3, .L4
	ldr	r3, [r3]
	cmp	r3, #10
	bgt	.L2
	ldr	r0, .L4+4
	bl	Sprints_Address
	b	.L3
.L2:
.L3:
	b	.L3
.L5:
	.align	2
.L4:
	.word	Array_Sprints
	.word	Array_Sprints_base_address
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 9-2020-q2-update) 9.3.1 20200408 (release)"

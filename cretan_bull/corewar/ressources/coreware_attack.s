.name "Max"
.comment "Payne"

begin:
	st r1, 11
	st r14, -4
	live %0
	st r14, -11
	st r1, r15
	st r14, -4
	fork %:start
	and r14, r14, r14
	zjmp %:begin
start:
	st r15, 6
	live %0
	fork %:set1
set:
	st r15, 6
	live %0
	fork %:set3
	ld %1, r5
	ld %5, r10
	st r15, 6
	live %0
	and r14, r14, r14
	zjmp %:go
set1:
	st r15, 6
	live %0
	fork %:set2
	st r15, r5
	ld %9, r10
	st r15, 6
	live %0
	and r14, r14, r14
	zjmp %:go
set2:
	ld %190055690, r5 # 0b 54 05 0a 0f
	ld %13, r10
	st r15, 6
	live %0
	and r14, r14, r14
	zjmp %:go
set3:
	ld %1409616399, r5 # 54 05 0a 0f
	ld %14, r10
	st r15, 6
	live %0
	and r14, r14, r14
	zjmp %:go
go:
	st r15, 6
	live %0
	sti r5, r10, r16

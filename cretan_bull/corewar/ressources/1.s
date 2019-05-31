.name "Hey"
.comment "Hou"

charge:
	lfork %2040
	and r8, %0, r8
	zjmp %-11

set:
	st r1, 6

life:
	live %0
	
jump:
	and r2, %0, r2
	st r1, r2
	st r2, -21
	and r9, %0, r0
	zjmp %-1

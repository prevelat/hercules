.name "Maximus Decimus Meridius"
.comment "Commander of the Armies of the North, General of the Felix Legions and loyal servante to the TRUE emperor"

life:
	live	%0

jump:
	lfork	%2040
	sti		r1, %:life, %1
	fork	%20
	ld		%15, r2
	lld		%0, r3
	fork	%-20
	zjmp	%:life

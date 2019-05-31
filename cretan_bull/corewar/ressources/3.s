.name "Shield"
.comment "yep"

start:
	st r1, r15
	st r16, -4
	st r15, 6
	live %0
	fork %:life
shield:
	ld %1, r16
	st r16, 406
	st r15, 405
	st r16, 414
	st r15, 413
	st r16, 422
	st r15, 421
	st r16, 430
	st r15, 429
	st r16, 438
	st r15, 437
	st r16, 446
	st r15, 445
	st r16, 454
	st r15, 453
	st r16, 406
	st r15, 405
	st r16, 414
	st r15, 413
	st r16, 422
	st r15, 421
	st r16, 430
	st r15, 429
	st r16, 438
	st r15, 437
	st r16, 446
	st r15, 445
	st r16, 454
	st r15, 453
	st r1, r15
	st r16, -4
	st r15, 6
	live %0
	and r13, r13, r13
	zjmp %:shield
back:
	st r15, -314
	st r15, -322
	st r15, -330
	st r15, -338
	st r15, -346
	st r15, -354
	st r15, -362
	st r15, -370
	st r15, -378
	st r15, -386
	st r15, -394
	st r15, -402
	st r15, -410
	st r15, -418
	st r15, -426
	st r15, -434
	st r15, -442
	st r15, -450
	st r15, -458
	st r15, -466
	st r15, -474
	st r15, -482
	st r15, -490
	and r13, r13, r13
	zjmp %:back
life:
	st r15, 6
	live %0
	fork %:fork
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	fork %:back
	and r13, r13, r13
	zjmp %:life

fork:
	st r15, 6
	live %0
	fork %:shield

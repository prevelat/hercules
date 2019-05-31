.name "Maximus Decimus Meridius"
.comment "Commander of the Armies of the North, General of the Felix Legions and loyal servante to the TRUE emperor!"

begin:
	st r1, r15
	st r16, -4
	st r15, 6
	live %0
	fork %:set
	st r15, 6
	live %0
	fork %:spear
	st r15, 6
	live %0	
load:
	ld %57675520, r3
	ld %251659777, r4
	fork %:replicator
core:
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	st r15, 6
	live %0
	fork %:core
replicator:
	st r3, -173
	st r4, -176
	st r15, -177
	st r3, -178
	st r4, -181
	st r15, -182
	st r3, -183
	st r4, -186
	st r15, -187
	st r3, -188
	st r4, -191
	st r15, -192
	st r3, -193
	st r4, -196
	st r15, -197
	st r15, 6
	live %0
	st r3, -208
	st r4, -211
	st r15, -212
	st r3, -226
	st r4, -229
	st r15, -230
	st r3, -231
	st r4, -234
	st r15, -235
	st r3, -236
	st r4, -239
	st r15, -240
	st r3, -241
	st r4, -244
	st r15, -245
	st r15, 6
	live %0
	fork %:replicator
	st r15, 6
	live %0
	fork %:middle
	and r14, r14, r14
	zjmp %:core
middle:
	st r15, 6
	live %0
	fork %:life
	st r16, 200
	st r16, 212
	st r16, 224
	st r16, 236
	st r16, 248
	st r16, 260
	st r16, 272
	st r16, 284
	st r16, 296
	st r16, 308
	st r16, 320
	and r14, r14, r14
	zjmp %-60
life:
	st r15, 6
	live %0
	and r14, r14, r14
	zjmp %:life
set:
	st r15, 6
	live %0
	fork %:jump
	st r15, 6
	live %0
	ld %190055946, r5 # 0b 54 06 0a
	ld %190056202, r6 # 0b 54 07 0a
	ld %190056203, r7 # 0b 54 07 0b
	ld %506, r10
	ld %20, r11
	and r16, r16, r16
	zjmp %:charge
jump:
	st r15, 6
	live %0
	ld %269025781, r5 # 10 09 01 9a
	st r5, r6
	ld %269025295, r7 # 10 09 01 00
	ld %269025295, r8 # 10 08 00 14
	ld %510, r10
	ld %24, r11
	and r16, r16, r16
	zjmp %:charge
spear:
	st r15, 6
	live %0
	ld %1047076, r5 # 00 0f fa 24
	st r5, r6
	st r6, r7
	ld %411, r10
	ld %12, r11
	and r16, r16, r16
	zjmp %:charge
charge:
	st r15, 6
	live %0
	sti r5, r10, r16
	zjmp %501

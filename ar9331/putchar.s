

_start:
	li	t0, 0x18020000
1:	lw	t1, 0 (t0)
	andi	t1, t1, 0x200
	beq	t1, 0, 1b
	nop

	li	t1, 0x241	/* 'A' */
	sw	t1, 0 (t0)
	b	1b
	nop


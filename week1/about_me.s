	.text
	.abicalls
	.option	pic0
	.section	.mdebug.abi32,"",@progbits
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.file	"about_me.c"
	.text
	.globl	main                    # -- Begin function main
	.p2align	2
	.type	main,@function
	.set	nomicromips
	.set	nomips16
	.ent	main
main:                                   # @main
	.frame	$fp,48,$ra
	.mask 	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:
	addiu	$sp, $sp, -48
	sw	$ra, 44($sp)            # 4-byte Folded Spill
	sw	$fp, 40($sp)            # 4-byte Folded Spill
	move	$fp, $sp
	sw	$zero, 36($fp)
	addiu	$1, $zero, 17
	sw	$1, 32($fp)
	addiu	$1, $zero, 25
	sw	$1, 28($fp)
	lw	$1, 32($fp)
	lw	$2, 28($fp)
	addu	$1, $1, $2
	sw	$1, 24($fp)
	lw	$5, 24($fp)
	lui	$1, %hi($.str)
	addiu	$4, $1, %lo($.str)
	jal	printf
	nop
	lui	$1, %hi($.str.1)
	addiu	$4, $1, %lo($.str.1)
	sw	$2, 20($fp)             # 4-byte Folded Spill
	jal	printf
	nop
	addiu	$1, $zero, 0
	sw	$2, 16($fp)             # 4-byte Folded Spill
	move	$2, $1
	move	$sp, $fp
	lw	$fp, 40($sp)            # 4-byte Folded Reload
	lw	$ra, 44($sp)            # 4-byte Folded Reload
	addiu	$sp, $sp, 48
	jr	$ra
	nop
	.set	at
	.set	macro
	.set	reorder
	.end	main
$func_end0:
	.size	main, ($func_end0)-main
                                        # -- End function
	.type	$.str,@object           # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
$.str:
	.asciz	"%d"
	.size	$.str, 3

	.type	$.str.1,@object         # @.str.1
$.str.1:
	.asciz	"\n"
	.size	$.str.1, 2


	.ident	"clang version 7.0.1-8 (tags/RELEASE_701/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym main
	.addrsig_sym printf
	.text

# Tests for the ALU64 eBPF pseudo-C instructions
        .text
	r2 += 666
	r3 += -666
	r4 += 2125315823
	r5 += r6
	r2 -= 666
	r3 -= -666
	r4 -= 2125315823
	r5 -= r6
	r2 *= 666
	r3 *= -666
	r4 *= 2125315823
	r5 *= r6
	r2 /= 666
	r3 /= -666
	r4 /= 2125315823
	r5 /= r6
	r2 |= 666
	r3 |= -666
	r4 |= 2125315823
	r5 |= r6
	r2 &= 666
	r3 &= -666
	r4 &= 2125315823
	r5 &= r6
	r2 <<= 666
	r3 <<= -666
	r4 <<= 2125315823
	r5 <<= r6
	r2 >>= 666
	r3 >>= -666
	r4 >>= 2125315823
	r5 >>= r6
	r2 %= 0x29a
	r3 %= -666
	r4 %= 0x7eadbeef
	r5 %= r6
	r2 ^= 666
	r3 ^= -666
	r4 ^= 2125315823
	r5 ^= r6
	r2 = 666
	r3 = -666
	r4 = 2125315823
	r5 = r6
	r2 s>>= 666
	r3 s>>= -666
	r4 s>>= 2125315823
	r5 s>>= r6
	r2 = -r2

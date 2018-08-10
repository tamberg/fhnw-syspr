#include <stdio.h>

int main() {
	typedef union {
	    unsigned char byte_value;
	    struct bit_layout {
	        unsigned int lo_nibble : 4;
//	        unsigned int hi_nibble : 4;
	        unsigned int hi_nibble_lsb : 1;
	    } bit_values;
	} Packet;

	Packet p;
	p.byte_value = 0xEF;
	printf("byte value 0x%x\n", p.byte_value);
	printf("lo = %d\n", p.bit_values.lo_nibble);
//	printf("hi = %d\n", p.bit_values.hi_nibble);
	printf("hi.lsb = %d\n", p.bit_values.hi_nibble_lsb);
    return 0;
}

#include "nbo.h"

uint32_t ntohl(uint32_t n){
	uint32_t a=0;
	for(int i=0;i<4;i++){
		a<<=8;
		a|=n&0xFF;
		n>>=8;
	}
	return a;
}

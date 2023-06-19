#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"

int main(){
	
	int addr = 0x01;
	int time = 400000;
	int sw;
	
	alt_printf("Dans le main\n");
	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,0x01);
	usleep(time);
	while(1){
		sw = IORD_ALTERA_AVALON_PIO_DATA(SW_BASE);
		alt_printf("%x\n",sw);
		if(sw == 0x01){
			time = 400000;
		}
		else if(sw == 0x02){
			time = 200000;
		}
		else if(sw == 0x04){
			time = 100000;
		}
		else if(sw == 0x08){
			time = 50000;
		}
		else if(sw == 0x10){
			time = 25000;
		}
		else if(sw == 0x20){
			time = 20000;
		}
		else if(sw == 0x40){
			time = 15000;
		}
		else if(sw == 0x80){
			time = 10000;
		}
		else if(sw == 0x100){
			time = 50000;
		}
		else if(sw == 0x200){
			time = 25000;
		}
		else{
			time = 500000;
		}
		
		while(addr != 0x80){
			addr = addr<<1;
			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,addr);
			usleep(time);
		}
		while(addr != 0x01){
			addr = addr>>1;
			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,addr);
			usleep(time);
		}
	}
}

#include <iostream>

#include "rs232.h"

void onoff(int val, char * com_name);

int main(int argc, char **argv)
{
	if(argc < 2){
		printf("Usage:\n./usb_relay /dev/ttyUSB0 0\n./usb_relay /dev/ttyUSB0 1\n");
	}else if(argc == 3){
		int relay_value = atoi(argv[2]);
		if( (relay_value == 0) || (relay_value == 1) ){
			onoff(relay_value, argv[1]);
		}		
	}

    return 0;
}



void onoff(int val, char * com_name){

	char mode[]={'8','N','1',0};
	unsigned char on_cmd[4] = {0xA0,0x01,0x01,0xA2};
	unsigned char off_cmd[4] = {0xA0,0x01,0x00,0xA1}; 


	if(RS232_OpenComport(com_name ,0, 9600, mode))
	{
		printf("Can not open comport\n");
	} else {
		if(val == 0){
			RS232_SendBuf(0,off_cmd,4);
			printf("OK\n");
		}else if (val == 1){
			RS232_SendBuf(0,on_cmd,4);
			printf("OK\n");
		}

		RS232_CloseComport(0);
	}
}


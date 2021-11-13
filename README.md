# USB_RELAY

Small program to control USB Relay board from LC Technology

Baud: 9600

LC USB switch communication protocol

Data (1) - startup logo (the default is 0xA0)
Data (2) - switch address code (the default is 0x01, identifies the first switch) 
Data (3) - operation data (0x00 to "off", 0x01 to "on") 
Data (4) - check code

For example:
Open the USB switch: A0 01 01 A2
Close the USB switch: A0 01 00 A1

Serial port library: https://gitlab.com/Teuniz/RS-232/

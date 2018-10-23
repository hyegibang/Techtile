import serial, time
import struct

ser = serial.Serial('/dev/ttyACM1', 9600, timeout=.1)
time.sleep(1) #give the connection a second to settle

def led_one():
	ser.write('10')
	print("10 Sent")
	time.sleep(1)

def led_zero():
	ser.write('01')
	print("01 Sent")
	time.sleep(1)

def ardread():
	rawdata = ser.read()  # read the returning information
	print("received data from arduino")
	data = ser.readline().decode() # string
	print(rawdata)
	print(data)
	time.sleep(2)

led_one()
#
# for i in range(5):
# 	led_one()
# 	led_zero()

print("done")


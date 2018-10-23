import serial, time
import struct

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
time.sleep(1) #give the connection a second to settle

def led_one():
	ser.write('1')
	print("1 Sent")
	time.sleep(1)

def led_zero():
	ser.write('0')
	print("0 Sent")
	time.sleep(1)

def ardread():
	rawdata = ser.read()  # read the returning information
	print("received data from arduino")
	data = ser.readline().decode() # string
	print(rawdata)
	print(data)
	time.sleep(1)

led_one()
#led_zero()
ardread()
print("done")


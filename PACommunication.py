import serial, time
import struct

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
time.sleep(3) #give the connection a second to settle

def led_one():
	b = [0,1]
	ser.write(b)
	print(b, "Sent")
	time.sleep(1)

def led_zero():
	ser.write('1')

	print("A Sent")
	time.sleep(5)

	ser.write('2')
	print("A Sent")
	time.sleep(5)

	ser.write('3')
	print("A Sent")
	time.sleep(5)

def ardread():
	rawdata = ser.read()  # read the returning information
	print("received data from arduino")
	data = ser.readline().decode() # string
	print(rawdata)
	print(data)
	time.sleep(2)

led_zero()
ardread()
#
# for i in range(5):
# 	led_one()
# 	led_zero()

print("done")


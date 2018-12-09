import time
import serial
import struct

# ser = serial.Serial('COM15', 9600, timeout=.1)
# time.sleep(3)
# ser.flush()
#
# character = 0;
#
# # for i in range(2,5):
# #     character = i
# #     print(i)
# #     character = ser.write(struct.pack('>B'),character)
# #     print(character, "sent")
# #     time.sleep(2)
#
# character = ser.write(struct.pack('>B'), 1)
# print(character, "sent")
# time.sleep(2)
#
# character = ser.write(struct.pack('>B'), 2)
# print(character, "sent")
# time.sleep(2)
#
# character = ser.write(struct.pack('>B'), 3)
# print(character, "sent")
# time.sleep(2)

# ser.close()
# print("ser-close")
#     #data = ser.write(struct.pack('>B', character))

import serial
import struct
import time

arduino = serial.Serial('COM15',9600)
time.sleep(2)


#Note: for characters such as 'a' I set data = b'a' to convert the data in bytes
#However the same thing does not work with numbers...
# data = 0
# data = arduino.write(struct.pack('>B',2))
# print("sent1")
# time.sleep(2)
# arduino.flush()

# for i in range(0,3):
#     data = 0
#     data = arduino.write(struct.pack('>B', i))
#     time.sleep(2)
#     arduino.flush()
#     print(i, "sent" )

arduino.write(b'5')
arduino.flush()
time.sleep(3)

arduino.write(b'6')
arduino.flush()
time.sleep(3)

arduino.write(b'7')
arduino.flush()
time.sleep(3)

arduino.close()
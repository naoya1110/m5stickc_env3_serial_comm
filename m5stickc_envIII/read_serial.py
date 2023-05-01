import serial


#ser = serial.Serial('COM3',115200,timeout=3) # windows
ser = serial.Serial('/dev/ttyUSB1',115200,timeout=3) # linux

# clear buffer
ser.reset_input_buffer()

while True:
    line = ser.readline()
    print(line.decode()[:-2])

ser.close()
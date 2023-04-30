import serial

ser = serial.Serial('COM3',115200,timeout=3)
# clear buffer
ser.reset_input_buffer()

while True:
    line = ser.readline()
    print(line.decode()[:-2])

ser.close()
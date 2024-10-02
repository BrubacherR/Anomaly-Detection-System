import serial
import numpy as np

s = serial.Serial('COM6', 115200, timeout = 10)

print("Opening: " + s.name)

# reset the buffers of the UART port to delete the remaining data in the buffers
s.reset_output_buffer()
s.reset_input_buffer()

# wait for user's signal to start the program
input("Press Enter to start communication...")
# send the character 's' to MCU via UART
# This will signal MCU to start the transmission
s.write(b's')
count = 0

while(True):
    x=s.readline()
    while not x:
        x=s.readline()

    if count % 2 == 0:
        code = float(x.decode('utf-8').strip())
        print(code)

        with open("Anomaly.txt", 'a') as file:
            # Write the new content
            file.write('!!!OBJECT DETECTED!!!.\n')
    else:
        code = int(x.decode('utf-8').strip())
        print(code)
    count += 1
#close the port
print("Closing: " + s.name)
s.close()
import serial
import time

arduino = serial.Serial('COM4', 9600, timeout=1)  # Add timeout
  # Wait for connection to establish

arduino.write(b'0')  # Send '0' to turn on LED
  # Wait for Arduino to process
arduino.write(b'1')  # Send '1' to turn off LED

  # Close the serial connection

import serial
import serial.tools.list_ports
ser=serial.Serial()     

def isConnected(module):
    global ser
    cmp=serial.tools.list_ports.comports()                 
    for device in cmp:
        device=str(device)
        if module in device:
            portf=device[0:4]
            # print(portf)
            if not ser.isOpen():ser=serial.Serial(port=portf,baudrate=9600)
            return True
        else :return False


print("In Package")
def toArduino(x):
    ser.write(x.encode())
    

def fromArduino():
    # print("Received: ")
    return ser.readline().decode().strip()
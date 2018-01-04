import time
import botbook_mcp3002 

gasLevel= 0

def readgasLevel():
global gasLevel
gasLevel= mcp.readAnalog()

def main():
while True: 
readgasLevel() 
print ("Current gas level is %i " % gasLevel) 
if gasLevel > 200:
{
print("gas leakage")
client=nemo.Client(key='0665ff2b',secret='b4080e7bd9707060')
client.send_message({'from':'Gas Detection System','to':'9483723289','text':'Gas Leak'})

time.sleep(0.5) 
}

if_name_=="_main_":
main()

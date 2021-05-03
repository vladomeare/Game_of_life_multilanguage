from datetime import datetime
from random import randint 

datafile = "../main_data/create_field_data.txt"

##################################################################################
##
## expected file format:
## 
## sizex 
## sizey 
## randomcoefficient % from 1 to 100
##
##################################################################################

try:
	f = open(datafile,'r')
	data = [None] * 3
	for line in range(3):
		data[line] = f.readline().replace("\n","")
	f.close()
	filename = "../main_data/field.txt"
	sizex = int(data[0])
	sizey = int(data[1])
	randomcoefficient = int(data[2])

	f = open(filename,'w')
	string = ""
	for i in range(sizey):
		for j in range(sizex):
			if randint(0,100) <= randomcoefficient:
				string += "1"
			else:
				string += "0"
		string += "\n"
	f.write(string)
	f.close()
except:
	f = open("../../log.txt",'a')
	f.write("log " + datetime.now().strftime("%d/%m/%Y %H:%M:%S") + " : Problem in generate_field.py with code or input file.\n_________________________________________________________________\n")
	f.close()
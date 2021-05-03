from datetime import datetime

############################
##
## html builder
##
############################

datafile = "../main_data/create_field_data.txt" 
filename = "../main_data/field.txt"
html = "../project.html"

try:
	f = open(datafile,'r')
	data = [None] * 3
	for line in range(3):
		data[line] = f.readline().replace("\n","")
	f.close()
	sizex = int(data[0])
	sizey = int(data[1])

	f = open(filename,'r')
	field = [None] *sizey
	for line in range(sizey):
		field[line] = f.readline().replace("\n","")
		if line == 0:
			local_field_command = field[line]
		field[line] = list(field[line])
	f.close()

	if local_field_command != "Restart":
		try:
			file = open(html,'w')
			file.write("<html><head><meta charset=\"utf-8\"><meta http-equiv=\"refresh\" content=\"2\"><style type=\"text/css\">table{border-collapse: collapse;}</style></head><body><table>")
			for y in range(sizey):
				file.write("<tr>")
				for x in range(sizex):
					if field[y][x] == '1':
						file.write("<td  width=\"10\" height=\"10\" style=\"background-color: #00ff00\"></td>")
					else:
						file.write("<td  width=\"10\" height=\"10\" style=\"background-color: #000000\"></td>")
				file.write("</tr>")
			file.write("</table></body></html>")
			file.close()
			print(1)
		except:
			f = open("../../log.txt",'a')
			f.write("log " + datetime.now().strftime("%d/%m/%Y %H:%M:%S") + " : Problem in html_builder.py with building output html. Problem building\n_________________________________________________________________\n")
			f.close()
	else:
		print(0)
except:
	f = open("../../log.txt",'a')
	f.write("log " + datetime.now().strftime("%d/%m/%Y %H:%M:%S") + " : Problem in html_builder.py with code or input file. data.txt problem read\n_________________________________________________________________\n")
	f.close()
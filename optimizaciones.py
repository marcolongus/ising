import numpy as np
import matplotlib.pyplot as plt


###########################################################################################################
def optimizaciones():
	label_ticks = ["Default","Factor comun" ,"signed char" ,"Pre-cal exp", "Flags"]

	plt.title("Optimizaciones")
	plt.xlim(1,11)
	plt.ylim(0.5,2)
	plt.ylabel("Tiempo [s]")-ftree-vectorize -fopt-info-vec -fopt-info-vec-missed 

	plt.xticks([2,4,6,8,10],["Default","Fac. comun" ,"Signed char" ,"Pre-cal exp", "GCC -Flags"])

	x = [2,4,6,8,10]
	y = [1.81242, 1.6678472, 1.607402833, 1.264021727 , 0.824616]


	plt.plot(x,y, marker="o")
	plt.grid()
	plt.savefig("opti.png")
	plt.show()


############################################################################################################
#Grafico de magnetizacion y energia
############################################################################################################
data = ["data.txt", "data_nuevo.txt"]

MAX_ROW = 151
SKIP    = 0

sim = 2

plt.xlabel("Temperatura [K]")
plt.ylabel("Energia")

data_index = 0

for i in range(2):
	Temperatura   = np.loadtxt(data[i], usecols=0, skiprows=SKIP ,max_rows=MAX_ROW)
	Energia       = np.loadtxt(data[i], usecols=1, skiprows=SKIP ,max_rows=MAX_ROW)
	#print(Temperatura.size)
	#SKIP    += 152
	plt.plot(Temperatura, Energia, label="Energia %i" %i)
plt.legend()
plt.savefig("graficos/energia1024.png")
plt.show()

plt.cla()
plt.xlabel("Temperatura")
plt.ylabel("Magnetizacion")
SKIP    = 0
for i in range(sim):

	Temperatura   = np.loadtxt(data[i], usecols=0, skiprows=SKIP ,max_rows=MAX_ROW)
	Magnetizacion = np.loadtxt(data[i], usecols=4, skiprows=SKIP ,max_rows=MAX_ROW)
	#SKIP    += 152
	plt.plot(Temperatura, Magnetizacion, label="Magnetizacion %i" %i)
plt.legend()
plt.savefig("graficos/magnetizacoin1024.png")
plt.show()

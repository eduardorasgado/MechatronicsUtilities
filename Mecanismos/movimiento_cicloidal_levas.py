#!/usr/bin/env python
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np

# elevacion de 50mm en 1.5 s
# retorno en 2 s con el esquema de mov cicloidal
# detencion
Ts = [1.5, 2.0, 0.75]

# tiempo total0
SigmaT = 0
for i in range(len(Ts)):
	SigmaT += Ts[i]

# tiempo Ti - intervalo
# SigmaT = 4.25
SigmaTi = np.linspace(0, SigmaT, SigmaT*100)

# velocidad angular de la leva: rpm
wleva = 1 / SigmaT
wleva_rpm = wleva * (60)


# rotacion de la leva para cada intervalo de movimiento del seguidor
Betas = []
for i in range(len(Ts)):
	Betas.append(wleva * Ts[i])

#-----------mostrando resultados--------
print("Tiempos T:")
for i in range(len(Ts)):
	print("T{} = {}".format(i, Ts[i]))

print("\nSuma total T = {}".format(SigmaT))

print("\nW de leva: {}rpm".format(wleva_rpm))

print("\nRotaciones de levas en intervalos Ti:")
for i in range(len(Betas)):
	angle = Betas[i] * 360 # conversion de rpm a grados(angulo)
	print("B{} = {} rpm -> {}°".format(i, Betas[i], angle))


#-----------graficando los intervalos

# primer intervalo
H1 = 50 #mm
DeltaR1 =  (H1*SigmaTi) / Ts[0]

### segundo intervalo -> descenso cicloidal#############

H2 = 50 #mm
DeltaR2 = (H2 * (1-(SigmaTi/Ts[1])+((1/(2*np.pi))*
		np.sin((2*np.pi*SigmaTi)/Ts[1])) )) + 50

########################################################

# tercer intervalo : dentecion
DeltaR3 = 0

def convertion(d1,d2,d3,s):
	lim1 = 0
	lim2 = 0
	for i in range(len(d1)):
		#print("d2[{}]: {}".format(i, d2[i]))
		if SigmaTi[i] <= Ts[0]:
			lim1 = i
			#print(SigmaTi[i])
		if SigmaTi[i]> Ts[0] and SigmaTi[i] <= (Ts[0]+Ts[1]):
			lim2 = i
			#print(SigmaTi[i])
	#print("-----indice de Ts[0]: {}".format(lim1))
	result = np.array(d1[0:lim1])
	# agregando los 50 de avance en y que dimos 
	result2 = np.array(d2[lim1+50:lim2+51])
	result3 = np.array([0 for i in range(0, len(SigmaTi)-lim2-1)])
	res = np.concatenate((result, result2), axis = None)
	res = np.concatenate((res, result3), axis = None)
	return res

res = convertion(DeltaR1, DeltaR2, DeltaR3, SigmaTi)
for i in range(len(res)):
	#print(res[i])
	pass

#for i in SigmaTi:
#	print(i)

#print(len(res))
#print(len(SigmaTi))

# graficacion
plt.ion()
fig = plt.figure()
ax = fig.add_subplot(111)
ax2 = fig.add_subplot(111)
line1, = ax.plot(SigmaTi, res, 'b-')
line2, = ax2.plot(SigmaTi, res, 'r-')
timing = 0
try:
	while True:
		for t in np.linspace(0, SigmaT, SigmaT*100):
			line1.set_ydata(res[timing])
			line2.set_ydata(res)
			fig.canvas.draw()
			timing+=1;
		# reiniciar
		timing = 0

except Exception as e:
	print("some error:{}".format(e))

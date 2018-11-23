#!/usr/bin/env python
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np

# elevacion de 50mm en 1.5 s
# retorno en 2 s con el esquema de mov cicloidal
# detencion
Ts = [1.5, 2.0, 0.75]

# tiempo total
SigmaT = 0
for i in range(len(Ts)):
	SigmaT += Ts[i]

# tiempo Ti - intervalo
# SigmaT = 4.25
SigmaTi = np.linspace(0, SigmaT, 100)

# velocidad angular de la leva: rpm
wleva = 1 / SigmaT
wleva_rpm = wleva * (60)


# rotacion de la leva para cada intervalo de movimiento del seguidor
Betas = []
for i in range(len(Ts)):
	Betas.append(wleva * Ts[i])

#-------------------
print("Tiempos T:")
for i in range(len(Ts)):
	print("T{} = {}".format(i, Ts[i]))

print("\nSuma total T = {}".format(SigmaT))

print("\nW de leva: {}rpm".format(wleva_rpm))

print("\nRotaciones de levas en intervalos Ti:")
for i in range(len(Betas)):
	angle = Betas[i] * 360 # conversion de rpm a grados(angulo)
	print("B{} = {} rpm -> {}°".format(i, Betas[i], angle))


import csv
import matplotlib.pyplot as plt
import numpy as np

## CARACTERISTICAS A SETEAR ##

CARPETA = "Series_Infineon"

VGS_MIN = -3.3
VGS_MAX = 15.4

#VDS_MAX = 400 # VDC
#VDS_MIN = 0  # Tierra

VDS_MAX = None
VDS_MIN = None

#I_TEST = 23
I_TEST = None

time_ids = []
signal_ids = []

time_vgs = []
signal_vgs = []

time_vds = []
signal_vds = []

SAMPLE_TIME = None
info = {}

p_Vgs_fall_90_signal = 0
p_Vgs_fall_90_time = 0
p_Vgs_fall_90_bool = False

p_Vgs_fall_50_signal = 0
p_Vgs_fall_50_time = 0
p_Vgs_fall_50_bool = False

p_Vgs_rise_10_signal = 0
p_Vgs_rise_10_time = 0
p_Vgs_rise_10_bool = False

p_Vgs_rise_50_time = 0
p_Vgs_rise_50_signal = 0
p_Vgs_rise_50_bool = False

p_Vsg_Temp_bool = False
p_Vgs_start_time_bool = False
p_Vgs_end_time_bool = False

############

p_Vds_rise_10_signal = 0
p_Vds_rise_10_time = 0
p_Vds_rise_10_bool = False

p_Vds_rise_90_signal = 0
p_Vds_rise_90_time = 0
p_Vds_rise_90_bool = False

p_Vds_fall_90_signal = 0
p_Vds_fall_90_time = 0
p_Vds_fall_90_bool = False

p_Vds_fall_10_time = 0
p_Vds_fall_10_signal = 0
p_Vds_fall_10_bool = False

p_Vdg_Temp_bool = False



#############

p_Id_fall_10_time = 0
p_Id_fall_10_signal = 0
p_Id_fall_10_bool = False

p_Id_rise_10_signal = 0
p_Id_rise_10_time = 0
p_Id_rise_10_bool = False

p_Id_fall_90_time = 0
p_Id_fall_90_signal = 0
p_Id_fall_90_bool = False

p_Id_rise_90_signal = 0
p_Id_rise_90_time = 0
p_Id_rise_90_bool = False

p_Id_Temp_bool = False

Id_bool_start = False

p_Vgs_start_time = 0



def moving_average(signal, window_size):
    """
    Calcula el promedio móvil de una señal manteniendo el mismo tamaño de la lista.
    
    Parameters:
    signal (list): La lista de datos de la señal.
    window_size (int): El tamaño de la ventana para calcular el promedio.
    
    Returns:
    list: Una lista con el promedio móvil de la señal.
    """
    avg_signal = []
    half_window = 0
    half_window_max = window_size // 2
    half_window = half_window_max
    for i in range(len(signal)):
        #half_window += 1
        #if half_window >= half_window_max:
        #    half_window = half_window_max
        start = max(0, i - 2*half_window)
        end = min(len(signal), i + 1)
        avg = sum(signal[start:end]) / (end - start)
        avg_signal.append(avg)
    return avg_signal

def normalizar_lista(lista):
    """
    Normaliza una lista de valores para que estén en el rango [0, 1].

    Parámetros:
    lista (list): Lista de valores numéricos a normalizar.

    Retorna:
    list: Lista normalizada.
    """
    min_valor = min(lista)
    max_valor = max(lista)
    
    # Asegurarse de que max y min no sean iguales para evitar división por cero
    if max_valor == min_valor:
        return [0.5] * len(lista)  # Retorna 0.5 para todos si todos los valores son iguales
    
    return [(valor - min_valor) / (max_valor - min_valor) for valor in lista]

with open(f'{CARPETA}/id-csv.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
    n = 0
    for row in spamreader:
        if n >= 10:
            time_ids.append(float(row[0]))
            signal_ids.append(float(row[1]))
        else:
            temp = list(row)
            n += 1
            try:
                info[temp[0]] = temp[1]
            except:
                pass

##ACTUALIZAMOS EL TS SI ES QUE NOS LO ENTREGAN

try:
    SAMPLE_TIME = float(info["Sample Interval"])
except:
    print("NO SE DETECTO SAMPLE TIME")
    SAMPLE_TIME = input("INGRESE SAMPLE TIME: ")
    pass

print(f"Sample Time = {SAMPLE_TIME}")

with open(f'{CARPETA}/vgs-csv.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
    n = 0
    for row in spamreader:
        if n >= 10:
            time_vgs.append(float(row[0]))
            signal_vgs.append(float(row[1]))
        else:
            n += 1

with open(f'{CARPETA}/vds-csv.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
    n = 0
    for row in spamreader:
        if n >= 10:
            time_vds.append(float(row[0]))
            signal_vds.append(float(row[1]))
        else:
            n += 1

for time, signal in zip(time_vgs,signal_vgs):

    if signal < 0.95*(VGS_MAX - VGS_MIN) + VGS_MIN and not p_Vgs_start_time_bool:
        p_Vgs_start_time = time
        p_Vgs_start_time_bool = True
    
    if p_Vgs_start_time_bool and signal > 0.04*(VGS_MAX - VGS_MIN) + VGS_MIN and time > p_Vgs_start_time + 1.0e-6 and not p_Vgs_end_time_bool:
        p_Vgs_end_time_bool = True
        p_Vgs_end_time = time


AVG_SAMPLE = 5000
avg_vds = moving_average(signal_vds, AVG_SAMPLE)

if VDS_MAX == None:
    VDS_MAX = max(avg_vds[AVG_SAMPLE:])
    print(f"Maximo VDS = {VDS_MAX}") # VDC

if VDS_MIN == None:
    VDS_MIN = min(avg_vds[AVG_SAMPLE:])
    print(f"Minimo VDS = {VDS_MIN}") # VDC

if I_TEST == None:
    I_TEST = 0
    for i in signal_ids:
        if i > I_TEST:
            I_TEST = i
        if i < 1:
            break
    print(f"I_test encontrado = {I_TEST}")

    
### MODIFICAR EN FUNCIÓN DE LA CALIDAD DE LA SEÑAL
PROMEDIADOR_BAJADA = 300
PROMEDIADOR_SUBIDA = 600

avg_time_vgs = time_vgs.copy()
avg_signal_vgs = signal_vgs.copy()
index_time_vgs = time_vgs.index(p_Vgs_start_time)
#index_time_vgs -= PROMEDIADOR_BAJADA


avg_signal_vgs[index_time_vgs:] = moving_average(signal_vgs[index_time_vgs:],PROMEDIADOR_BAJADA)

index_time_vgs = time_vgs.index(p_Vgs_end_time)
#index_time_vgs -= PROMEDIADOR_SUBIDA
avg_signal_vgs[index_time_vgs:] = moving_average(signal_vgs[index_time_vgs:],PROMEDIADOR_SUBIDA)


for time, signal in zip(time_vgs,avg_signal_vgs):
    
    if signal < 0.9*(VGS_MAX - VGS_MIN) + VGS_MIN and p_Vgs_fall_90_bool == False:
        p_Vgs_fall_90_time = time
        p_Vgs_fall_90_signal = signal
        p_Vgs_fall_90_bool = True
    
    if p_Vgs_fall_90_bool and signal < 0.5*(VGS_MAX - VGS_MIN) + VGS_MIN and p_Vgs_fall_50_bool == False:
        p_Vgs_fall_50_time = time
        p_Vgs_fall_50_signal = signal
        p_Vgs_fall_50_bool = True

    if p_Vgs_fall_50_bool and signal < 0.01*(VGS_MAX - VGS_MIN) + VGS_MIN:
        p_Vsg_Temp_bool = True
    
    if p_Vsg_Temp_bool and signal > 0.1*(VGS_MAX - VGS_MIN) + VGS_MIN and p_Vgs_rise_10_bool == False:
        p_Vgs_rise_10_time = time
        p_Vgs_rise_10_signal = signal
        p_Vgs_rise_10_bool = True
    
    if p_Vgs_rise_10_bool and signal > 0.5*(VGS_MAX - VGS_MIN) + VGS_MIN and p_Vgs_rise_50_bool == False:
        p_Vgs_rise_50_time = time
        p_Vgs_rise_50_signal = signal
        p_Vgs_rise_50_bool = True



for time, signal in zip(time_vds,signal_vds):
    if signal > 0.1*(VDS_MAX - VDS_MIN) + VDS_MIN and p_Vds_rise_10_bool == False:
        p_Vds_rise_10_time = time
        p_Vds_rise_10_signal = signal
        p_Vds_rise_10_bool = True
    
    if p_Vds_rise_10_bool and signal > 0.9*(VDS_MAX - VDS_MIN) + VDS_MIN and p_Vds_rise_90_bool == False:
        p_Vds_rise_90_time = time
        p_Vds_rise_90_signal = signal
        p_Vds_rise_90_bool = True


    if p_Vds_rise_90_bool and signal > 0.95*(VDS_MAX - VDS_MIN) + VDS_MIN and time > p_Vds_rise_90_time + 1.0e-6:
        p_Vdg_Temp_bool = True
    
    if p_Vdg_Temp_bool and signal < 0.9*(VDS_MAX - VDS_MIN) + VDS_MIN and p_Vds_fall_90_bool == False:
        p_Vds_fall_90_time = time
        p_Vds_fall_90_signal = signal
        p_Vds_fall_90_bool = True
    
    if p_Vds_fall_90_bool and signal < 0.1*(VDS_MAX - VDS_MIN) + VDS_MIN and p_Vds_fall_10_bool == False:
        p_Vds_fall_10_time = time
        p_Vds_fall_10_signal = signal
        p_Vds_fall_10_bool = True


#################

for time, signal in zip(time_ids,signal_ids):

    if signal > 0.95*I_TEST and Id_bool_start == False:
        Id_bool_start = True
    
    if Id_bool_start and signal < 0.9*I_TEST and p_Id_fall_90_bool == False:
        p_Id_fall_90_time = time
        p_Id_fall_90_signal = signal
        p_Id_fall_90_bool = True
    
    
    if p_Id_fall_90_bool and signal < 0.1*I_TEST and p_Id_fall_10_bool == False:
        p_Id_fall_10_time = time
        p_Id_fall_10_signal = signal
        p_Id_fall_10_bool = True
    
    if p_Id_fall_10_bool and signal < 0.05*I_TEST:
        p_Id_Temp_bool = True
    
    if p_Id_Temp_bool and signal > 0.1*I_TEST and p_Id_rise_10_bool == False:
        p_Id_rise_10_time = time
        p_Id_rise_10_signal = signal
        p_Id_rise_10_bool = True
    
    if p_Id_rise_10_bool and signal > 0.9*I_TEST and p_Id_rise_90_bool == False:
        p_Id_rise_90_time = time
        p_Id_rise_90_signal = signal
        p_Id_rise_90_bool = True






n = 1

time_ids = time_ids[n::n]
signal_ids = signal_ids[n::n]

COLOR_GRAF = "lightgray"

COLOR_LINEAS = "black"

fig = plt.figure(figsize=(16, 12), facecolor=COLOR_GRAF)
ax1 = plt.subplot2grid((4, 3), (0, 0), colspan=3, facecolor=COLOR_GRAF)
ax2 = plt.subplot2grid((4, 3), (1, 0), colspan=3, facecolor=COLOR_GRAF)
ax3 = plt.subplot2grid((4, 3), (2, 0), colspan=3, facecolor=COLOR_GRAF)
ax4 = plt.subplot2grid((4, 3), (3, 0), facecolor=COLOR_GRAF)
ax4_right = plt.subplot2grid((4, 3), (3, 1), facecolor=COLOR_GRAF)
ax4_text = plt.subplot2grid((4, 3), (3, 2), facecolor=COLOR_GRAF)

#ax.plot(time_ids,signal_ids, label='Ids')
ax1.plot(time_vgs,signal_vgs, label='Vgs')
ax1.plot(avg_time_vgs,avg_signal_vgs, label='Vgs_avg')
ax1.plot(p_Vgs_fall_90_time, p_Vgs_fall_90_signal, 'ro')
ax1.plot(p_Vgs_fall_50_time, p_Vgs_fall_50_signal, 'bo')
ax1.plot(p_Vgs_rise_10_time, p_Vgs_rise_10_signal, 'go')
ax1.plot(p_Vgs_rise_50_time, p_Vgs_rise_50_signal, 'mo')

# Anotaciones para el subplot 1
ax1.annotate('Fall 90%', xy=(p_Vgs_fall_90_time, p_Vgs_fall_90_signal), xytext=(10, 10), textcoords='offset points', color='red')
ax1.annotate('Fall 50%', xy=(p_Vgs_fall_50_time, p_Vgs_fall_50_signal), xytext=(10, 10), textcoords='offset points', color='blue')
ax1.annotate('Rise 10%', xy=(p_Vgs_rise_10_time, p_Vgs_rise_10_signal), xytext=(10, 10), textcoords='offset points', color='green')
ax1.annotate('Rise 50%', xy=(p_Vgs_rise_50_time, p_Vgs_rise_50_signal), xytext=(10, 10), textcoords='offset points', color='purple')



ax1.set_title('Señal de Vgs en función del Tiempo', color=COLOR_LINEAS)
#ax1.set_xlabel('Tiempo (s)', color=COLOR_LINEAS)
ax1.set_ylabel('Vgs (V)', color=COLOR_LINEAS)
ax1.tick_params(axis='x', colors=COLOR_LINEAS)
ax1.tick_params(axis='y', colors=COLOR_LINEAS)
# Añadir una leyenda
ax1.legend()



# Mostrar la gráfica
ax2.plot(time_ids,signal_ids, label='Ids', color = "orange")
ax2.plot(p_Id_fall_10_time, p_Id_fall_10_signal, 'ro')
ax2.plot(p_Id_rise_10_time, p_Id_rise_10_signal, 'bo')
ax2.plot(p_Id_fall_90_time, p_Id_fall_90_signal, 'mo')
ax2.plot(p_Id_rise_90_time, p_Id_rise_90_signal, 'go')


# Anotaciones para el subplot 2
ax2.annotate('Id Fall 10%', xy=(p_Id_fall_10_time, p_Id_fall_10_signal), xytext=(10, 10), textcoords='offset points', color='red')
ax2.annotate('Id Rise 10%', xy=(p_Id_rise_10_time, p_Id_rise_10_signal), xytext=(10, 10), textcoords='offset points', color='blue')

ax2.annotate('Id Fall 90%', xy=(p_Id_fall_90_time, p_Id_fall_90_signal), xytext=(10, 10), textcoords='offset points', color='purple')
ax2.annotate('Id Rise 90%', xy=(p_Id_rise_90_time, p_Id_rise_90_signal), xytext=(10, 10), textcoords='offset points', color='green')



ax2.set_title('Señal de Vds en función del Tiempo', color=COLOR_LINEAS)
#ax2.set_xlabel('Tiempo (s)', color=COLOR_LINEAS)
ax2.set_ylabel('Vds (V)', color=COLOR_LINEAS)
ax2.tick_params(axis='x', colors=COLOR_LINEAS)
ax2.tick_params(axis='y', colors=COLOR_LINEAS)
ax2.legend()





ax3.plot(time_vds, signal_vds, label='Vds', color= "red")
ax3.plot(p_Vds_fall_90_time, p_Vds_fall_90_signal, 'ro')
ax3.plot(p_Vds_fall_10_time, p_Vds_fall_10_signal, 'bo')
ax3.plot(p_Vds_rise_10_time, p_Vds_rise_10_signal, 'go')
ax3.plot(p_Vds_rise_90_time, p_Vds_rise_90_signal, 'mo')

ax3.set_title('Señal de Vds en función del Tiempo', color=COLOR_LINEAS)
ax3.set_xlabel('Tiempo (s)', color=COLOR_LINEAS)
ax3.set_ylabel('Vds (V)', color=COLOR_LINEAS)
ax3.tick_params(axis='x', colors=COLOR_LINEAS)
ax3.tick_params(axis='y', colors=COLOR_LINEAS)
ax3.legend()

# Anotaciones para el subplot 3
ax3.annotate('Fall 90%', xy=(p_Vds_fall_90_time, p_Vds_fall_90_signal), xytext=(10, 10), textcoords='offset points', color='red')
ax3.annotate('Fall 10%', xy=(p_Vds_fall_10_time, p_Vds_fall_10_signal), xytext=(10, 10), textcoords='offset points', color='blue')
ax3.annotate('Rise 10%', xy=(p_Vds_rise_10_time, p_Vds_rise_10_signal), xytext=(10, 10), textcoords='offset points', color='green')
ax3.annotate('Rise 90%', xy=(p_Vds_rise_90_time, p_Vds_rise_90_signal), xytext=(10, 10), textcoords='offset points', color='purple')


power_signal = [a * b for a, b in zip(signal_vds, signal_ids)]

## GRAFICOS DE POTENCIAS



INICIO_PERDIDA_APAGADO = time_ids.index(p_Vds_rise_10_time)
FIN_PERDIDA_APAGADO = time_ids.index(p_Id_fall_10_time)

INICIO_PERDIDA_PRENDIDO = time_ids.index(p_Id_rise_10_time)
FIN_PERDIDA_PRENDIDO = time_ids.index(p_Vds_fall_10_time)

##GRAFICO APAGADO
ax4.plot(time_ids[INICIO_PERDIDA_APAGADO:FIN_PERDIDA_APAGADO], power_signal[INICIO_PERDIDA_APAGADO:FIN_PERDIDA_APAGADO], label='Power Signal')
ax4.fill_between(time_ids[INICIO_PERDIDA_APAGADO:FIN_PERDIDA_APAGADO], power_signal[INICIO_PERDIDA_APAGADO:FIN_PERDIDA_APAGADO], color='skyblue', alpha=0.4)
ax4.set_title('Señal de Potencia Apagado', color=COLOR_LINEAS)
ax4.set_xlabel('Tiempo (s)', color=COLOR_LINEAS)
ax4.set_ylabel('Potencia (W)', color=COLOR_LINEAS)
ax4.tick_params(axis='x', colors=COLOR_LINEAS)
ax4.tick_params(axis='y', colors=COLOR_LINEAS)
ax4.legend()



##GRAFICO PRENDIDO
ax4_right.plot(time_ids[INICIO_PERDIDA_PRENDIDO:FIN_PERDIDA_PRENDIDO], power_signal[INICIO_PERDIDA_PRENDIDO:FIN_PERDIDA_PRENDIDO], label='Power Signal')
ax4_right.fill_between(time_ids[INICIO_PERDIDA_PRENDIDO:FIN_PERDIDA_PRENDIDO], power_signal[INICIO_PERDIDA_PRENDIDO:FIN_PERDIDA_PRENDIDO], color='skyblue', alpha=0.4)
ax4_right.set_title('Señal de Potencia Prendido', color=COLOR_LINEAS)
ax4_right.set_xlabel('Tiempo (s)', color=COLOR_LINEAS)
ax4_right.set_ylabel('Potencia (W)', color=COLOR_LINEAS)
ax4_right.tick_params(axis='x', colors=COLOR_LINEAS)
ax4_right.tick_params(axis='y', colors=COLOR_LINEAS)
ax4_right.legend()


Eoff = sum(power_signal[INICIO_PERDIDA_APAGADO:FIN_PERDIDA_APAGADO])*SAMPLE_TIME
Eon = sum(power_signal[INICIO_PERDIDA_PRENDIDO:FIN_PERDIDA_PRENDIDO])*SAMPLE_TIME

print(f"Perdidas por apagado {Eoff}")
print(f"Perdidas por encendido {Eon}")

tr = p_Vds_fall_10_time - p_Vds_fall_90_time
tf = p_Vds_rise_90_time - p_Vds_rise_10_time
print(f"tr = {tr}")
print(f"Nuevo tr = {p_Id_rise_90_time - p_Id_rise_10_time}")
print(f"tf = {tf}")
print(f"Nuevo tf = {p_Id_fall_10_time - p_Id_fall_90_time}")


texts = [
    f"Perdidas por encendido (Eon): {'{:.2e}'.format(Eon)}",
    f"Perdidas por apagado (Eoff): {'{:.2e}'.format(Eoff)}",
    f"Rise Time: {'{:.2e}'.format(tr)}",
    f"Fall Time: {'{:.2e}'.format(tf)}",
    f"Per. por segundo prendido: {'{:.2e}'.format(Eon*25000)}",
    f"Per. por segundo apgado: {'{:.2e}'.format(Eoff*25000)}"
]

# Ajustar la posición y el tamaño del texto
for i, text in enumerate(texts):
    ax4_text.text(0.5, 1 - i*0.2, text, ha='center', va='center', color=COLOR_LINEAS, fontsize=12, transform=ax4_text.transAxes)


ax4_text.axis('off')  # Ocultar los ejes para el subplot de texto








ax1.spines['top'].set_color(COLOR_LINEAS)
ax1.spines['right'].set_color(COLOR_LINEAS)
ax1.spines['bottom'].set_color(COLOR_LINEAS)
ax1.spines['left'].set_color(COLOR_LINEAS)

ax2.spines['top'].set_color(COLOR_LINEAS)
ax2.spines['right'].set_color(COLOR_LINEAS)
ax2.spines['bottom'].set_color(COLOR_LINEAS)
ax2.spines['left'].set_color(COLOR_LINEAS)

ax3.spines['top'].set_color(COLOR_LINEAS)
ax3.spines['right'].set_color(COLOR_LINEAS)
ax3.spines['bottom'].set_color(COLOR_LINEAS)
ax3.spines['left'].set_color(COLOR_LINEAS)

ax4.spines['top'].set_color(COLOR_LINEAS)
ax4.spines['right'].set_color(COLOR_LINEAS)
ax4.spines['bottom'].set_color(COLOR_LINEAS)
ax4.spines['left'].set_color(COLOR_LINEAS)

ax4_right.spines['top'].set_color(COLOR_LINEAS)
ax4_right.spines['right'].set_color(COLOR_LINEAS)
ax4_right.spines['bottom'].set_color(COLOR_LINEAS)
ax4_right.spines['left'].set_color(COLOR_LINEAS)


with open(CARPETA+".txt", "w") as arch:
    for i in texts:
        arch.write(i + "\n")




plt.tight_layout()
plt.show()
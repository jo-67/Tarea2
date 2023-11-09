import pandas as pd
import re

# Definir un diccionario para almacenar los resultados por universo
resultados = {}

# Leer los resultados desde el archivo (puedes ajustar el nombre del archivo)
with open('resultados100.txt', 'r') as archivo:
    # Utiliza read() para leer todo el contenido como una sola cadena
    resultados_texto = archivo.read()
# Expresión regular para extraer k y los segundos
pattern = r"RadixSort k=(\d+) tomó ([\d.]+) segundos"


exe = resultados_texto.split("Ejecutando para ")
#Ejecutando para 2^1 
#RadixSort tom├│ 6.07 segundos en ejecutarse.
#QuickSort tom├│ 5.29 segundos en ejecutarse.
#End
radix = []
quick = []
for i in exe:
    mod = i.replace(" tom├│ ", " ")
    mod = mod.replace(" segundos", "")
    ke = mod.split("\n")
    u = ke[0]
    for line in ke[1:]:
        if line != "" and line!="End":
            a = line.split(" ")
            r = a[0]
            t = a[2]
            if r=="RadixSort":
                radix = radix + [[int(u.split("^")[1]), float(t)]]
            else:
                quick = quick + [[int(u.split("^")[1]), float(t)]]

#print(l)
dfr = pd.DataFrame(radix)
dfq = pd.DataFrame(quick)

dfr.to_excel('resultadosRadixSort.xlsx', index=False)
dfq.to_excel('resultadosQuickSort.xlsx', index=False)
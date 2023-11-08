import pandas as pd
import re

# Definir un diccionario para almacenar los resultados por universo
resultados = {}

# Leer los resultados desde el archivo (puedes ajustar el nombre del archivo)
with open('resultados.txt', 'r') as archivo:
    # Utiliza read() para leer todo el contenido como una sola cadena
    resultados_texto = archivo.read()
# Expresión regular para extraer k y los segundos
pattern = r"RadixSort k=(\d+) tomó ([\d.]+) segundos"


exe = resultados_texto.split("Ejecutando para ")
#print(exe)
dic = []
l = []
for i in exe:
    mod = i.replace("RadixSort ", "")
    mod = mod.replace(" tomó ", " ")
    mod = mod.replace(" segundos", "")
    ke = mod.split("\n")
    u = ke[0]
    for line in ke[1:]:
        if line != "" and line!="End":
            a = line.split(" ")
            k = a[0]
            t = a[2]
            dic.append({"universo": u, "k": int(k.replace("k=", "")), "t": float(t)})
            l = l + [[u, int(k.replace("k=", "")), float(t)]]

#print(l)
df = pd.DataFrame(l)
#print(df)
df_min = df.loc[df.groupby(0)[2].idxmin()]

print(df_min)
df_min.to_excel('resultadosK.xlsx', index=False)
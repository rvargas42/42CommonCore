#!/bin/bash

# Verifica si se ha proporcionado el PID del servidor como argumento
if [ $# -eq 0 ]; then
    echo "Uso: $0 <pid_del_servidor>"
    exit 1
fi

# PID del servidor
SERVER_PID=$1

# Array con las cadenas de texto que se enviarán
STRINGS=("Mensaje1" "Mensaje2" "Mensaje3" "Mensaje4" "Mensaje5")

# Número de clientes que deseas ejecutar (puedes cambiar este número)
NUM_CLIENTS=${#STRINGS[@]}

# Ejecuta múltiples clientes en paralelo
for ((i=0; i<$NUM_CLIENTS; i++))
do
    ./client $SERVER_PID "${STRINGS[$i]}" &
    echo "Cliente $((i+1)) enviando: ${STRINGS[$i]}"
done

# Espera a que todos los procesos de clientes terminen
wait

echo "Todos los clientes han finalizado."

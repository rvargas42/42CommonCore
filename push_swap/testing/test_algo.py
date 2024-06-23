import random
import subprocess

def generate_numbers_with_gap(start, finish):
	numbers = [i for i in range(start, finish)]
	random.shuffle(numbers)
	return numbers

# Genera 500 números aleatorios
random_numbers = generate_numbers_with_gap(1, 100)

# Desordena los números
random.shuffle(random_numbers)

# Escribe los números en un archivo de texto
with open('numbers.txt', 'w') as file:
	file.write(' '.join(map(str, random_numbers)))

# Ejecuta el programa ./push_swap con los números generados como argumento
try:
	result = subprocess.run(['./push_swap'] + list(map(str, random_numbers)), capture_output=True, text=True)
	print(result.stdout)
	print(result.stderr)
except Exception as e:
	print(f"Error ejecutando ./push_swap: {e}")

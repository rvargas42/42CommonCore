import random
import subprocess

def generate_numbers_with_gap(count, min_gap):
    numbers = []
    current_min = 0
    
    for _ in range(count):
        current_min += min_gap
        new_number = random.randint(current_min, current_min + 9)
        numbers.append(new_number)
        current_min = new_number
    
    return numbers

# Genera 500 números aleatorios
random_numbers = generate_numbers_with_gap(100, 10)

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

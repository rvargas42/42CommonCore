import subprocess

def run_push_swap(test_case):
    try:
        result = subprocess.run(['./push_swap'] + test_case, capture_output=True, text=True)
        return result.stdout, result.stderr
    except Exception as e:
        return "", str(e)

# Valores de INT_MAX y INT_MIN en Python
INT_MAX = 2147483647
INT_MIN = -2147483648
LLMAX = 18446744073709551615

# Casos de prueba
test_cases = [
    [str(INT_MAX + 1)],
    [str(INT_MIN - 1)],
	[str(LLMAX)],
    [str(INT_MAX), str(INT_MAX + 1)],
    [str(INT_MIN), str(INT_MIN - 1)],
    [str(INT_MAX), "0", str(INT_MAX + 1)],
    [str(INT_MIN), "0", str(INT_MIN - 1)],
    ["0", "1", "-1", str(INT_MAX + 1)],
    ["0", "1", "-1", str(INT_MIN - 1)],
    [str(INT_MAX), str(INT_MIN), "42"],
    [str(INT_MAX), str(INT_MIN), str(INT_MAX + 1), str(INT_MIN - 1)],
]

for i, test_case in enumerate(test_cases):
    stdout, stderr = run_push_swap(test_case)
    print(f"Test case {i + 1}: {' '.join(test_case)}")
    print("Output:")
    print(stdout)
    print("Error:")
    print(stderr)
    print("-" * 40)


def clmul_no_reduction(x, y):
    result = 0

    for i in range(32):
        if (y & 1) != 0:
            result ^= x
        x <<= 1
        y >>= 1

    return result

# Define hexadecimal numbers directly
# --- mulcl_ex1, mulcl_ex2 ---
#x_hex = 0xA2CCF053
#y_hex = 0x96AA8281
# --- mulcl_ex3 ---
#x_hex = 0x58C52167
#y_hex = 0x00000000
# --- mulcl_ex7 ---
#x_hex = 0xAAAAAAAA
#y_hex = 0xFFFFFFFF
# --- mulcl_ex11 ---
#x_hex = 0xFFFFFFFF
#y_hex = 0xFFFFFFFF
# --- mulcl_ex13 ---
#x_hex = 0x12345678
#y_hex = 0xABCDEF12
#x_hex = 0x00112233
#y_hex = 0x44556677
# --- mulcl_ex15 ---
#x_hex = 0x12345055
#y_hex = 0x12345055

## --- mulclimm_ex1 ---
#x_hex = 0xA2CCF053
#y_hex = 0x87
# --- mulclimm_ex1 ---
#x_hex = 0xFFFFFFFF
#x_hex = 0x12345678
#x_hex = 0x00112233
#x_hex = 0x12345055
#y_hex = 0x87


## --- aesgcm ---
x_hex = 0xFF77BB33
y_hex = 0x9FF8840C

# Perform carry-less multiplication without reduction
result = clmul_no_reduction(x_hex, y_hex)

# Separate higher 8 bytes from lower 8 bytes
higher_8_bytes = (result >> 32) & 0xFFFFFFFF
lower_8_bytes = result & 0xFFFFFFFF

# Print result in binary and hexadecimal
#print("Higher 8 bytes (binary):", bin(higher_8_bytes))
#print("Higher 8 bytes (hexadecimal):", hex(higher_8_bytes))
#print("Lower 8 bytes (binary):", bin(lower_8_bytes))
#print("Lower 8 bytes (hexadecimal):", hex(lower_8_bytes))


print("operandA ", hex(x_hex))
print("operandB ", hex(y_hex))
print("MULCLH ", hex(higher_8_bytes))
print("MULCL ", hex(lower_8_bytes))

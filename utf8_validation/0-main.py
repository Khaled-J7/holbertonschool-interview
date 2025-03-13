#!/usr/bin/python3

validUTF8 = __import__('0-validate_utf8').validUTF8

# Test cases
data = [65]  # Single-byte character
print(validUTF8(data))  # Expected output: True

data = [
    80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33
    ]  # ASCII string
print(validUTF8(data))  # Expected output: True

data = [229, 65, 127, 256]  # Invalid sequence
print(validUTF8(data))  # Expected output: False

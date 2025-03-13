#!/usr/bin/python3

def validUTF8(data):
    """
    Determines if a given dataset represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers representing bytes.

    Returns:
        bool: True if data is a valid UTF-8 encoding, else False.
    """
    num_bytes = 0  # Number of bytes remaining in the current character

    for byte in data:
        # Mask to extract the least significant 8 bits
        byte &= 0xFF

        if num_bytes == 0:
            # Determine the number of bytes in the current character
            if byte >> 7 == 0b0:  # Single-byte character
                continue
            elif byte >> 5 == 0b110:  # 2-byte character
                num_bytes = 1
            elif byte >> 4 == 0b1110:  # 3-byte character
                num_bytes = 2
            elif byte >> 3 == 0b11110:  # 4-byte character
                num_bytes = 3
            else:
                return False  # Invalid prefix
        else:
            # Check if the byte is a valid continuation byte
            if byte >> 6 != 0b10:
                return False
            num_bytes -= 1

    # If all characters are complete, num_bytes should be 0
    return num_bytes == 0

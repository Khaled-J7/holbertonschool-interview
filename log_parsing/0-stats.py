#!/usr/bin/python3
"""Log parsing script"""

import sys

# Dictionary to store count of status codes
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
total_size = 0  # Variable to store total file size
line_count = 0  # Counter to track number of processed lines

try:
    for line in sys.stdin:
        try:
            parts = line.split()
            if len(parts) < 7:
                continue  # Skip invalid lines

            status = int(parts[-2])  # Extract status code
            size = int(parts[-1])  # Extract file size

            # Update total file size
            total_size += size

            # Update status code count
            if status in status_codes:
                status_codes[status] += 1

            line_count += 1

            # Print statistics every 10 lines
            if line_count % 10 == 0:
                print("File size:", total_size)
                for code in sorted(status_codes.keys()):
                    if status_codes[code] > 0:
                        print("{}: {}".format(code, status_codes[code]))

        except Exception:
            continue  # Ignore lines with unexpected format

except KeyboardInterrupt:
    pass  # Handle Ctrl+C gracefully

# Print final statistics after termination
print("File size:", total_size)
for code in sorted(status_codes.keys()):
    if status_codes[code] > 0:
        print("{}: {}".format(code, status_codes[code]))

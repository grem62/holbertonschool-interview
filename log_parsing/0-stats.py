#!/usr/bin/python3
"""_summary_
"""

import sys

status_codes = {"200": 0, "301": 0, "400": 0,
                "401": 0, "403": 0,
                "404": 0, "405": 0, "500": 0}
file_size = 0
counter = 0

try:
    for line in sys.stdin:
        counter += 1
        data = line.split()
        try:
            file_size += int(data[-1])
        except:
            pass
        try:
            status_codes[data[-2]] += 1
        except:
            pass
        if counter == 10:
            print("File size: {}".format(file_size))
            for key, value in status_codes.items():
                if value != 0:
                    print("{}: {}".format(key, value))
            counter = 0
except KeyboardInterrupt:
    pass

#!/usr/bin/python3
import sys


"""Script to get stats from a request"""
codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
size = 0
counter = 0
status = {k: 0 for k in codes}
try:
    for line in sys.stdin:
        counter += 1
        data = line.split()
        if len(data) > 2:
            if data[-2] in status:
                status[data[-2]] += 1
            size += int(data[-1])
        if counter == 10:
            print("File size: {}".format(size))
            for k, v in sorted(status.items()):
                if v:
                    print("{}: {}".format(k, v))
            counter = 0
            size = 0
            status = {k: 0 for k in codes}
except KeyboardInterrupt:
    print("File size: {}".format(size))
    for k, v in sorted(status.items()):
        if v:
            print("{}: {}".format(k, v))
    counter = 0
    size = 0
    status = {k: 0 for k in codes}
    raise
print("File size: {}".format(size))

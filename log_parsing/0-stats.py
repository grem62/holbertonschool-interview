#!/usr/bin/python3
"""0-stats.py"""

import sys


"""script that reads stdin line by line and computes metrics:"""

x = 0
dict = {}
status_available = [
    '200',
    '301',
    '400',
    '401',
    '403',
    '404',
    '405',
    '500']
total_size = 0


def print_stats(total_size, dict):
    print("File size: {}".format(total_size))
    for key in sorted(dict):
        print("{}: {}".format(key, dict[key]))


try:
    for line in sys.stdin:
        line_split = line.split()

        try:
            file_size = line_split[-1]
            total_size += int(file_size)
        except (IndexError, ValueError):
            pass

        try:
            status_code = line_split[-2]
            if status_code in status_available:
                if status_code in dict:
                    dict[status_code] += 1
                else:
                    dict[status_code] = 1
        except (IndexError, ValueError):
            pass

        x += 1

        if x == 10:
            print_stats(total_size, dict)
            x = 0

    print_stats(total_size, dict)

except KeyboardInterrupt:
    print_stats(total_size, dict)
    raise

#!/usr/bin/python3
"""
Write a method that determines if a given data set represents a valid
UTF-8 encoding.

    Prototype: def validUTF8(data)
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need to
    handle the 8 least significant bits of each integer
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    data: will be represented by a list of integers

    Returns: True if data is a valid UTF-8 encoding, else return False
    """
    bytes_counter = 0

    for n in data:
        byte = format(n, '#010b')[-8:]
        if bytes_counter == 0:
            if int(byte[0]) == 1:
                bytes_counter = byte.count('1')
            if bytes_counter == 0:
                continue
            if bytes_counter == 1 or bytes_counter > 4:
                return False
        else:
            if byte[:2] != ['10']:
                return False
        bytes_counter -= 1
    if bytes_counter == 0:
        return True
    return False

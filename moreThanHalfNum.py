#! /usr/bin/env python

def find (array):
	if len(array) == 0:
		return -1;
	c = 0
	A = array[0]
	i = 1
	while i < len(array):
		if array[i] == A:
			c += 1
		else:
			c -= 1

		if c <= 0:
			i += 1
			if i >= len(array):
				return -1;
			else:
				A = array[i]
				c = 1
		
		i += 1
	
	c = 0
	for i in array:
		if i == A:
			c += 1
	
	if c > len(array) / 2:
		return A
	else:
		return -1

if __name__ == '__main__':
	array = [2, 2, 3, 3, 5, 5]
	print find(array)
	array = [1, 2, 3, 4, 4, 4, 4]
	print find(array)

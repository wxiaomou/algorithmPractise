#http://www.careercup.com/question?id=15542726
#!usr/bin/env python

class Solution:
	def __init__(self):
		self.matrix = [['a', 'b', 'c', 'd', 'e'], ['f', 'g', 'h', 'i', 'j'], 
				           ['k', 'l', 'm', 'n', 'o'], ['p', 'q', 'r', 's', 't'],
									 ['u', 'v', 'w', 'x', 'y'], ['z']]

	def remote(self, text):
		text = text.lower()
		ret = ""
		x = 0
		y = 0
		COL = 5
		ROW = 6
		for it in text:
			location = ord(it) - ord('a')
			print location
			_y = location % COL
			_x = location / COL
			
			if _x > x:
				i = 0
				while i < _x - x:
					ret += "D "
					i += 1
			else:
				i = 0
				while i < x - _x:
					ret += "U "
					i += 1

			if _y > y:
				j = 0
				while j < _y - y:
					ret += "R "
					j += 1
			else:
				j = 0
				while j < y - _y:
					ret += "L "
					j += 1

			ret += "OK "
			x = _x
			y = _y

		return ret

if __name__ == "__main__":
	sol = Solution()
	print sol.remote('con')
	print sol.remote('zebra')

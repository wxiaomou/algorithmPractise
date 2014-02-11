#!usr/bin/env python
class Node:
	def __init__(self,val):
		self.left = None
		self.right = None
		self.val = val
	
	def get_left(self):
		return self.left

	def set_left(self, left):
		self.left = left
		 
	def get_right(self):
		return self.right

	def set_right(self, right):
		self.right = right

	def get_val(self):
		return self.val

	def __str__(self):
		return "Node is " + str(self.val)

	def mid_traverse(self, root):
		if root == None:
			return
		self.mid_traverse(root.left)
		print str(root)
		self.mid_traverse(root.right)
		return



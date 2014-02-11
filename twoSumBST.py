#!usr/bin/env python
from BinaryTreeNode import Node

class Solution:
	def __init__(self):
		pass

	def two_sum(self, root, target):
		if root == None:
			return False

		left = [root]
		right = [root]
		it = root
		while it.get_left() != None:
			left.append(it.get_left())
			it = it.get_left()
		
		it = root
		while it.get_right() != None:
			right.append(it.get_right())
			it = it.get_right()

		num1 = left[-1]
		num2 = right[-1]
		left.pop()
		right.pop()

		while num1.get_val() < num2.get_val():
			if num1.get_val() + num2.get_val() == target:
				return True
			elif num1.get_val() + num2.get_val() < target:
				it = num1.get_right()
				if it != None:
					left.append(it)
					while it.get_left() != None:
						it = it.get_left()
						left.append(it)
				num1 = left[-1]
				left.pop()
			else:
				it = num2.get_left()
				if it != None:
					right.append(it)
					while it.get_right() != None:
						it = it.get_right()
						right.append(it)
				num2 = right[-1]
				right.pop()

		return False

if __name__ == '__main__':
	node5 = Node(5)
	
	node4 = Node(4)
	node4_5 = Node(4.5)
	node4_4 = Node(4.4)
	node4_8 = Node(4.8)
	node2 = Node(2)
	node3_1 = Node(3.1)

	node8 = Node(8)
	node6 = Node(6)
	node9 = Node(9)
	node7_1 = Node(7.1)
	
	node5.set_left(node4)
	node5.set_right(node8)

	node4.set_left(node2)
	node4.set_right(node4_5)

	node2.set_right(node3_1)

	node4_5.set_left(node4_4)
	node4_5.set_right(node4_8)

	node8.set_left(node6)
	node8.set_right(node9)

	node6.set_right(node7_1)
	
#	node5.mid_traverse(node5)
	sol = Solution()
	print sol.two_sum(node5, 10.1)
				


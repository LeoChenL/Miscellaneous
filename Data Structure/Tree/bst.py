#!/usr/bin/env python3
# -*- coding: utf-8 -*-

' binary search tree module '

from collections import deque

class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree(object):
    def __init__(self):
        self.root = None

    def get_root(self):
        return self.root

    def insert(self, data):
        self.root = self.insert_node(self.root, data)

    def search(self, data):
        target_node = self.search_node(self.root, data)
        if target_node:
            print("Find in the tree")
        else:
            print("Not find in the tree")
        return target_node

    def search_node(self, rt, data):
        if rt == None:
            return None

        target_node = None
        if data == rt.data:
            target_node = rt
        elif data < rt.data:
            target_node = self.search_node(rt.left, data)
        elif data > rt.data:
            target_node = self.search_node(rt.right, data)
        return target_node

    def delete(self, data):
        self.root = self.delete_node(self.root, data)

    def delete_node(self, rt, data):
        if rt == None:
            return None

        if data == rt.data :
            new_rt = None
            # no child
            if rt.left == None and rt.right == None:
                new_rt = None

            # one child
            elif rt.left == None and rt.right != None:
                new_rt = rt.right
            elif rt.left != None and rt.right == None:
                new_rt = rt.left

            # two children
            else:
                new_rt = rt
                min_node = self.min_node(rt.right)
                new_rt.data = min_node.data
                new_rt.right = self.delete_node(rt.right, min_node.data)
            return new_rt

        elif data < rt.data:
            rt.left = self.delete_node(rt.left, data)
            return rt
        elif data > rt.data:
            rt.right = self.delete_node(rt.right, data)
            return rt

    def min_node(self, node):
        if node == None:
            return None

        while node.left:
            node = node.left
        return node

    def traverse_pre_order(self):
        traverse_list = []
        traverse_list = self.pre_order(self.root, traverse_list)
        return traverse_list

    def traverse_in_order(self):
        traverse_list = []
        traverse_list = self.in_order(self.root, traverse_list)
        return traverse_list

    def traverse_post_order(self):
        traverse_list = []
        traverse_list = self.post_order(self.root, traverse_list)
        return traverse_list

    def traverse_level_order(self):
        traverse_list = []
        q = deque()
        q.append(self.root)
        while len(q) > 0:
            node = q.popleft()
            traverse_list.append(node.data)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return traverse_list


    def insert_node(self, root, data):
        if root == None:
            # Create a new node
            root = Node(data)
            return root

        if data <= root.data:
            root.left = self.insert_node(root.left, data)
        else:
            root.right = self.insert_node(root.right, data)
        return root

    def pre_order(self, node, traverse_list):
        if node:
            traverse_list.append(node.data)
            traverse_list = self.pre_order(node.left, traverse_list)
            traverse_list = self.pre_order(node.right, traverse_list)
        return traverse_list

    def in_order(self, node, traverse_list):
        if node:
            traverse_list = self.in_order(node.left, traverse_list)
            traverse_list.append(node.data)
            traverse_list = self.in_order(node.right, traverse_list)
        return traverse_list

    def post_order(self, node, traverse_list):
        if node:
            traverse_list = self.post_order(node.left, traverse_list)
            traverse_list = self.post_order(node.right, traverse_list)
            traverse_list.append(node.data)
        return traverse_list

    def __repr__(self):
        level = 0
        traverse_list = []
        q = deque()
        q.append((self.root, level))
        while len(q) > 0:
            node, level = q.popleft()
            if node == "<null>":
                traverse_list.append(("<null>", level))
                continue
            else:
                traverse_list.append((str(node.data), level))
            if node.left:
                q.append((node.left, level+1))
            else:
                q.append(("<null>", level+1))
            if node.right:
                q.append((node.right, level+1))
            else:
                q.append(("<null>", level+1))

        s = "Binary Search Tree"
        current_level = -1
        for node, lev in traverse_list:
            if lev > current_level:
                s += "\n" + node
                current_level = lev
            else:
                s += "  |  " + node
        return s

if __name__ == "__main__":
    bt = BinaryTree()
    pre_order = bt.traverse_pre_order()
    print(pre_order)
    bt.insert(7)
    bt.insert(4)
    bt.insert(9)
    bt.insert(10)
    bt.insert(2)
    bt.insert(5)
    pre_order = bt.traverse_pre_order()
    print("Pre order:", pre_order)
    in_order = bt.traverse_in_order()
    print("In order:", in_order)
    post_order = bt.traverse_post_order()
    print("Post order:", post_order)
    level_order = bt.traverse_level_order()
    print("Level order:", level_order)
    print("\n", bt)
    bt.search(6)
    bt.search(7)
    bt.search(10)
    bt.delete(4)
    print("\n", bt)

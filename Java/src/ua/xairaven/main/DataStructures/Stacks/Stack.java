package ua.xairaven.main.DataStructures.Stacks;

import java.util.Iterator;

/**
 * Implementation of stack<br>
 * Date: 03.02.2022
 * @author Alex "xairaven" Kovalyov
 */
public class Stack<Item> implements Iterable<Item> {
    private Node first;
    private int size;

    private class Node {
        Item item;
        Node next;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public Stack<Item> copy() {
        Stack<Item> temp = new Stack<>();
        Stack<Item> copy = new Stack<>();
        for (Item it : this) {
            temp.push(it);
        }
        for (Item it : temp) {
            copy.push(it);
        }
        return copy;
    }

    public void push(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("Item can't be null");
        }
        Node newNode = new Node();
        newNode.item = item;
        newNode.next = first;
        first = newNode;
        size++;
    }

    public Item pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack underflow");
        }
        Item item = first.item;
        first = first.next;
        size--;
        return item;
    }

    public Item peek() {
        if (isEmpty()) {
            return null;
        }
        return first.item;
    }

    public Iterator<Item> iterator() {
        return new StackIterator();
    }

    private class StackIterator implements Iterator<Item> {
        private Node current = first;

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    // tests
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < 10; i++) {
            stack.push(i);
        }
        for(Integer i: stack) {
            System.out.println(i);
        }
    }
}

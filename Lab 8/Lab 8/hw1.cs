// Eric Chen 11381898
// CptS 322 HW1
// Sample input: 55 22 77 88 11 22 44 77 55 99 22

using System;

class hw1
{
    class Node
    {
        public int data;
        public Node left;
        public Node right;
        public Node(int value)
        {
            this.data = value;
            left = null;
            right = null;
        }
    }

    class BinarySearchTree
    {
        public Node root;
        public static int count;
        public bool textDisplayed = false;
        public BinarySearchTree() { root = null; }

        // Creates and returns a BST node
        public Node addNode(int data)
        {
            Node temp = new Node(data);
            if (root == null)
                root = temp;
            count++;
            return temp;
        }

        // Inserts the new node in the right place
        public void insert(Node root, Node newNode)
        {
            while (root != null)
            {
                if (newNode.data > root.data)
                {
                    if (root.right == null)
                    {
                        root.right = newNode;
                        break;
                    }
                    root = root.right;
                }
                else
                {
                    if (root.left == null)
                    {
                        root.left = newNode;
                        break;
                    }
                    root = root.left;
                }
            }
        }

        // Recursively looks for duplicate, compares values to root first to save time.
        public bool search(Node root, int x)
        {
            if (root == null)           // Case 1: Tree is empty
                return false;
            else if (root.data == x)    // Case 2: Equal to root, duplicate found.
            {
                return true;
            }
            else if (root.data > x) {   // Case 3: Less than root, recurse left
                return search(root.left, x);
            }
            else                        // Case 4: Greater than root, recurse right
                return search(root.right, x);

        }

        // Recursively displays the tree inorder from least to greatest
        public void display(Node root) 
        {
            if (textDisplayed == false)
                Console.Write("Tree contents: ");
                textDisplayed = true;
            if (root != null) {
                display(root.left);
                Console.Write(root.data + " ");
                display(root.right);
            }
        }

        // Finds max depth recursively
        public int getLevel(Node root)
        {
            if (root == null)
                return 0;
            else
            {
                int leftLevel = getLevel(root.left);
                int rightLevel = getLevel(root.right);

                if (rightLevel > leftLevel)
                    return (rightLevel + 1);
                else
                    return (leftLevel + 1);
            }
        }
        public int getCount(int currentCount)
        {
            int count = currentCount;
            return count;
        }
    }

    static void Main()
    {
        string prompt = "Enter a collection of numbers in the range [0, 100], separated by spaces: ";
        string input;

        BinarySearchTree bst = new BinarySearchTree();
        Console.WriteLine(prompt);

        input = Console.ReadLine();     // Read the input string

        // Parse the string
        string[] intSubStrings = input.Split(' ');

        foreach (string str in intSubStrings)
        {
            int x = Convert.ToInt32(str);

            if ((x >= 0) && (x <= 100)) {           // Inserting Nodes to Binary search tree
                if (!bst.search(bst.root, x))       // Check if its a duplicate number
                    bst.insert(bst.root, bst.addNode(x));   // add it to the tree if not
//              else
//                  Console.WriteLine("{0} is a duplicate", x);
            }
            else // x in range [0,100]
                Console.WriteLine("{0} is not in RANGE [0,100]", x);
        }

        bst.display(bst.root);

        Console.WriteLine("\n  Number of nodes: {0}", BinarySearchTree.count);    // C# can't access static
                                                                                // members with instance syntax
        int level = bst.getLevel(bst.root); // Find max depth
        Console.WriteLine("  Number of levels: {0}", level);

        double minLevel = (BinarySearchTree.count / 2); // Math.Floor() can be used, but rounding down is done automatically when dividing
                                                        // an int by an int
        Console.WriteLine("  Minimum number of levels that a tree with {0} nodes could have = {1}", BinarySearchTree.count, Math.Floor(minLevel)); // Floor only takes doubles
        Console.WriteLine("Done");
    }
}
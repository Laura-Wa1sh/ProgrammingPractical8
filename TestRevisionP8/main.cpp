//
//  main.cpp
//  TestRevisionP8
//
//  Created by Laura Walsh on 04/05/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#include <iostream>
#include <string>
#include "TreeNode.hpp"

using namespace std;

// Part 1
void testSearchTree(TreeNode<string>* tree, string key)
{
    bool ans = tree->searchTree(key);
    cout << "Search for " << key << " returns ";
    if (ans == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

// Part 2
int Fib(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}

template <typename T>
int depth(TreeNode<T>* tree)
{
    int dl, dr;
    if (tree == NULL)
        return 0;
    else {
        dl = depth(tree->left);
        dr = depth(tree->right);
        if (dl < dr)
            return dr + 1;
        else
            return dl + 1;
    }
}

int sigma(TreeNode<int>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return tree->item + sigma(tree->left) + sigma(tree->right);
}

int main()
{
    // Part 1
    cout << "Part 1: Search for a range of tree values" << endl << endl;
    // Amended by PMcM - This is the correct "Days of the Week" order for the tree
    TreeNode<string>* wd_tree = new TreeNode<string>("Sunday",
                                                     new TreeNode<string>("Monday", new TreeNode<string>("Friday"), new TreeNode<string>("Saturday")),
                                                     new TreeNode<string>("Tuesday", new TreeNode<string>("Thursday"), new TreeNode<string>("Wednesday")));
    
    // Commented out by PMcM - This produces an alphabetically sorted tree, rather than sorted by order of Days in the Week
    //TreeNode<string>* wd_tree = new TreeNode<string>("Wednesday",
    //    new TreeNode<string>("Monday", new TreeNode<string>("Sunday"), new TreeNode<string>("Tuesday")),
    //    new TreeNode<string>("Friday", new TreeNode<string>("Thursday"), new TreeNode<string>("Saturday")));
    
    // MAC USERS: you may have to break the above statement into several ones as following to define wd_tree:
    //TreeNode<string>* Tue = new TreeNode<string>("Tuesday");
    //TreeNode<string>* Thu = new TreeNode<string>("Thursday");
    //TreeNode<string>* Sat = new TreeNode<string>("Saturday");
    //TreeNode<string>* Sun = new TreeNode<string>("Sunday");
    //TreeNode<string>* Mon = new TreeNode<string>("Monday", Sun, Tue);
    //TreeNode<string>* Fri = new TreeNode<string>("Monday", Thu, Sat);
    //TreeNode<string>* wd_tree = new TreeNode<string>("Wednesday", Mon, Fri);
    
    testSearchTree(wd_tree, "Sunday");
    testSearchTree(wd_tree, "Monday");
    testSearchTree(wd_tree, "Tuesday");
    testSearchTree(wd_tree, "Wednesday");
    testSearchTree(wd_tree, "Thursday");
    testSearchTree(wd_tree, "Friday");
    testSearchTree(wd_tree, "Saturday");
    testSearchTree(wd_tree, "Sundey");
    testSearchTree(wd_tree, "");
    testSearchTree(wd_tree, "monday");
    testSearchTree(wd_tree, "January");
    
    // Part 2
    // 1)
    cout << "Fibonacci(8) = " << Fib(8) << endl;
    // 2)
    cout << "Depth of tree is " << depth(wd_tree) << endl;
    // 3)
    TreeNode<int>* i_tree = new TreeNode<int>(5,
                                              new TreeNode<int>(3, new TreeNode<int>(2), new TreeNode<int>(4)),
                                              new TreeNode<int>(7, new TreeNode<int>(6), new TreeNode<int>(8)));
    cout << "Sum of tree is " << sigma(i_tree) << endl;
    
    delete i_tree;
    delete wd_tree;
    return 0;
}

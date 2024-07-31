//*****************************************************************************************************
//
//		File:					bst.cpp
//
//		This program will impliment and test a array list  class.
//	
//		Other files required: 
//          1. bts.h
//          2. stock.h
//          
//			
//*****************************************************************************************************

#include"bst.h"
#include"stock.h"
#include <cstdlib>
#include<fstream>
#include <iostream>

//*****************************************************************************************************

using namespace std;

//*****************************************************************************************************

int main()
{
    BinarySearchTree<int> bst;

    for (int i = 0; i < 10; ++i) {
        int value = rand() % 5000 + 1;
        bst.insert(value);
    }

    cout << "Inorder traversal: ";
    bst.inorder();
    cout << std::endl;

    cout << "Preorder traversal: ";
    bst.preorder();
    cout << std::endl;

    cout << "Postorder traversal: ";
    bst.postorder();
    cout << std::endl;

    cout << "Height of the tree: " << bst.height() << std::endl;

    bst.destroy();


    BinarySearchTree<Stock> stockTree;

  
    ifstream inputFile("Stock.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file Stock.txt" << endl;
        return 1;
    }

    string name, symbol;
    double price;

    while (inputFile >> name >> symbol >> price) {
        Stock stock(name, symbol, price);
        stockTree.insert(stock);
    }

    inputFile.close();

    char choice;
    while (true) {
        cout << "Options:\n";
        cout << "a) Display a stock's name given its symbol\n";
        cout << "b) Display a stock's price given its symbol\n";
        cout << "c) Insert a new stock\n";
        cout << "d) Display all stocks\n";
        cout << "e) Quit\n";
        cout << "Enter your option: ";
        cin >> choice;

        switch (choice) {
        case 'a': {
            string searchSymbol;
            cout << "Enter stock symbol: ";
            cin >> searchSymbol;
            Stock searchStock("", searchSymbol, 0.0);
            Stock* foundStock = stockTree.search(searchStock);
            if (foundStock != nullptr) {
                cout << "Stock name: " << foundStock->getName() << endl;
            }
            else {
                cout << "Stock not found." << endl;
            }
            break;
        }
        case 'b': {
            string searchSymbol;
            cout << "Enter stock symbol: ";
            cin >> searchSymbol;
            Stock searchStock("", searchSymbol, 0.0);
            Stock* foundStock = stockTree.search(searchStock);
            if (foundStock != nullptr) {
                cout << "Stock price: " << foundStock->getPrice() << endl;
            }
            else {
                cout << "Stock not found." << endl;
            }
            break;
        }
        case 'c': {
            string newName, newSymbol;
            double newPrice;
            cout << "Enter new stock details:\n";
            cout << "Name: ";
            cin >> newName;
            cout << "Symbol: ";
            cin >> newSymbol;
            cout << "Price: ";
            cin >> newPrice;
            Stock newStock(newName, newSymbol, newPrice);
            stockTree.insert(newStock);
            break;
        }
        case 'd': {
            cout << "All stocks:\n";
            stockTree.inorder();
            break;
        }
        case 'e': {
           
            ofstream outputFile("Stock.txt");
            if (!outputFile.is_open()) {
                cerr << "Error: Unable to open file Stock.txt for writing." << endl;
            }
            else
            {
               
                outputFile.close();
            }
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

}

//*****************************************************************************************************

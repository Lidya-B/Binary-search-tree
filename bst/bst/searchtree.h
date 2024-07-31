//*****************************************************************************************************
//
//		File:					searchtree.h
//
//		Student:				Lidya Belew
//
//		Assignment:				assigment 6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					03/04/2024
//
//
//		This program will impliment and test a array list  class.
//	
//		Other files required: 
//         1. none 
//			
//*****************************************************************************************************

#ifndef SEARCHTREE_H
#define SEARCHTREE_H

template<typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;

};

#endif // !SEARCHTREE_H
// ������ �������������� ������ � ��������� ��������� � ���������.
// ����������� ���� ���������� �������� �������� �������� ��, ��� � ������ ���� ������ ����������� ��������� �� ��� ������������ ����.

#include "BinaryTrees.h"

#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

int main(int argc, char **argv)
{
	NodeOfTree *myTree, *currentNode, *myBalancedTree, *myAVL_Tree;

	setlocale( LC_ALL, "Russian" ); // � ������� ����� �������� ������� �����.

	// ���������� ������ �������������� � ������������ � �������� �� �������� �����: https://prog-cpp.ru/data-tree/
	myTree = new NodeOfTree( 1 );
	currentNode = myTree;										/*					1					*/
	AddNodeInLeft( currentNode, new NodeOfTree( 2 ) );			/*				   / \					*/
	AddNodeInRight( currentNode, new NodeOfTree( 3 ) );			/*				  2   3					*/
																/*				 / \   \				*/
	// ��������� � ������ ������� ���� '1', �.�. � ���� '2':	/*				4   5   6				*/
	currentNode = currentNode->leftNode;						/*				   /   / \				*/
	assert( currentNode->key == 2 );							/*				  7   8   9				*/
	AddNodeInLeft( currentNode, new NodeOfTree( 4 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 5 ) );

	// ��������� � ������� ������� ���� '2', �.�. � ���� '5':
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	AddNodeInLeft( currentNode, new NodeOfTree( 7 ) );
	assert( currentNode->rightNode == NULL );

	// ��������� � ������� ������� ���� '1', �.�. � ���� '3':
	currentNode = ( *myTree ).rightNode;						// ������	currentNode = myTree->rightNode;
	assert( ( *currentNode ).key == 3 );						// ������	assert( currentNode->key == 3 );
	AddNodeInRight( currentNode, new NodeOfTree( 6 ) );

	// ��������� � ������� ������� ���� '3', �.�. � ���� '6':
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 6 );
	AddNodeInLeft( currentNode, new NodeOfTree( 8 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 9 ) );
	/*	
	myTree = new NodeOfTree;
	currentNode = myTree;
	currentNode->key = 1;
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 2;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 3;

	// ��������� � ������ ������� ���� '1', �.�. � ���� '2':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 2 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 4;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 5;

	// ��������� � ������� ������� ���� '2', �.�. � ���� '5':
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 7;
	assert( currentNode->rightNode == NULL );

	// ��������� � ������� ������� ���� '1', �.�. � ���� '3':
	currentNode = ( *myTree ).rightNode;
	assert( ( *currentNode ).key == 3 );						// ������	assert( currentNode->key == 3 );
	( *currentNode ).rightNode = new NodeOfTree;				// ������	currentNode->rightNode = new NodeOfTree;
	( *( *currentNode ).rightNode ).parentNode = currentNode;	// ������	currentNode->rightNode->parentNode = currentNode;
	( *( *currentNode ).rightNode ).key = 6;					// ������	currentNode->rightNode->key = 6;
	assert( ( *currentNode ).leftNode == NULL );				// ������	assert( currentNode->leftNode == NULL );

	// ��������� � ������� ������� ���� '3', �.�. � ���� '6':
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 6 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 8;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 9;
	*/
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	assert( !CheckParentalLinks( myTree ) );
	
	cout << "������������ ������ ������ ������������ ������������ ������. ��� ���� ������������ �������������� �����:" << endl;
	TreePrint( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "������������ ������ ������ ������������ ������������ ������. ��� ���� ������������ ������������ ������ �����:" << endl;
	TreePrint_2( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "������������ ������ ������ ������������ ������������ ������. ��� ���� ������������ ������������ �������� �����:" << endl;
	TreePrint_3( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "������������ ������ ������ ������������ ����������� ������ � ���������� �����:" << endl;
	TreePrint_4( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "������������ ������ ������ ������������ ����������� ������ � ��������� �����:" << endl;
	TreePrint_5( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "������������ ������ ������ ������������ ����������� ������ � ����������� �����:" << endl;
	TreePrint_6( myTree );
	cout << endl << "------------------------------------------------" << endl;

	int height = CalculatingHeight( myTree ); // ���������� ������ ������ � ���� ��� �����������.
	int numOfNodes = NumOfNodes( myTree );
	cout << endl
		<< "height  =  " << height << endl
		/*
		<< "Height( myTree )  =  " << Height( myTree ) << endl
		<< "Height( myTree->leftNode )  =  " << Height( myTree->leftNode ) << endl
		<< "Height( myTree->leftNode->leftNode )  =  " << Height( myTree->leftNode->leftNode ) << endl
		<< "Height( myTree->leftNode->rightNode )  =  " << Height( myTree->leftNode->rightNode ) << endl
		<< "Height( myTree->leftNode->rightNode->leftNode )  =  " << Height( myTree->leftNode->rightNode->leftNode ) << endl
		<< endl
		<< "Height( myTree->rightNode )  =  " << Height( myTree->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->leftNode )  =  " << Height( myTree->rightNode->rightNode->leftNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode ) << endl
		<< endl
		*/
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myTree )  =  " << IsItAVL_Tree( myTree ) << endl
		<< "IsItIdealBalancedTree( myTree )  =  " << IsItIdealBalancedTree( myTree ) << endl
		<< "IsItBinarySearchTree( myTree )  =  " << IsItBinarySearchTree( myTree ) << endl << endl;

	NodeOfTree* copiedTree;

	cout << "�������� ������ ����� ��������� ��������� ������:" << endl;
	copiedTree = CopyFrom( myTree->leftNode );
	assert( !CheckParentalLinks( copiedTree ) );
	cout << "===Dump2( copiedTree )===" << endl;
    Dump2( copiedTree );
	cout << endl;
	FreeMem( copiedTree );										// �������� ������ � ������������, ���������� ��� ���� ������.

	cout << "�������� ������ ������ ��������� ��������� ������:" << endl;
	copiedTree = CopyFrom( myTree->rightNode );
	assert( !CheckParentalLinks( copiedTree ) );
	cout << "===Dump2( copiedTree )===" << endl;
    Dump2( copiedTree );
	cout << endl;
	FreeMem( copiedTree );										// �������� ������ � ������������, ���������� ��� ���� ������.

	cout << "�������� �� ������ �������:" << endl;
	copiedTree = CopyFrom( myTree );
	assert( !CheckParentalLinks( copiedTree ) );
	cout << "===Dump2( copiedTree )===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "�������� ������ ����� (������ ������):" << endl;
	for( currentNode = copiedTree; currentNode->leftNode != currentNode->rightNode && currentNode->leftNode != nullptr; currentNode = ( currentNode->leftNode != nullptr? currentNode->leftNode: currentNode->rightNode ) );
	copiedTree = DeleteNode( currentNode );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;
	
	cout << "�������� �������� ���������:" << endl;
	copiedTree = DeleteNode( copiedTree->leftNode );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "�������� ������� ���������:" << endl;
	copiedTree = DeleteNode( copiedTree->rightNode );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "�������� ������������� ���� - �����:" << endl;
	copiedTree = DeleteNode( copiedTree );
	assert( copiedTree == nullptr );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "������������ ������������ ��� ������ ��������� ������ �� ���������, ��������� �� ���� � ������ 3, ��������� ��������� ������:" << endl;
	assert( myTree->rightNode != NULL );
	myAVL_Tree = BuildAVL_BinarySearchTreeFrom( myTree->rightNode );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << endl;
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myAVL_Tree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myAVL_Tree );
	numOfNodes = NumOfNodes( myAVL_Tree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItIdealBalancedTree( myAVL_Tree )  =  " << IsItIdealBalancedTree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl
	
//		<< "Address of myTree:  " << myTree << endl				// ����� ������ ����� ��������� ������.
		<< "Address of copiedTree:  " << copiedTree << endl		// ����� ������ ����� �������������� ������.
		<< "Address of myAVL_Tree:  " << myAVL_Tree << endl;	// ����� ������ ����� ������ myAVL_Tree.
//	FreeMem( myTree );											// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( copiedTree );										// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( myAVL_Tree );										// �������� ������ � ������������, ���������� ��� ���� ������.
//	cout << "Address of myTree:  " << myTree << endl;			// ����� ������ ����� ������ ����� ��� ��������.
	cout << "Address of copiedTree:  " << copiedTree << endl	// ����� ������ ����� ������ ����� ��� ��������.
		<< "Address of myAVL_Tree:  " << myAVL_Tree << endl;	// ����� ������ ����� ������ myAVL_Tree ����� ��� ��������.
//	assert( myTree == NULL );
	assert( !copiedTree );	// assert( copiedTree == nullptr );
	assert( nullptr == NULL );

	cout << endl << "============================================================================" << endl;
	cout << "������������ ��������� �������:" << endl;
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	NodeOfTree* searchedNode;
	int wantedKey;
	cout << endl << "���� ������� FindKey(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << endl << "���� ������� FindKey_2(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey_2( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << endl << "���� ������� FindKey_3(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey_3( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << endl << "���� ������� FindKey_4(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey_4( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << "��� ������������ ����� �� ������ ������� ����� ���������� ���������!" << endl;
	FreeMem( myTree );

	cout << endl << "============================================================================" << endl;
	cout << "���������� ������ �������������� �.�., ��� �� ��� ���� ��� �������, �� �� ���� �� �������� ����������������:" << endl;
	myTree = new NodeOfTree( 1 );
	currentNode = myTree;										/*					1					*/
	AddNodeInLeft( currentNode, new NodeOfTree( 2 ) );			/*				  /   \					*/
	AddNodeInRight( currentNode, new NodeOfTree( 3 ) );			/*				 2     3				*/
																/*				/ \   / \				*/
	// ��������� � ������ ������� ���� '1', �.�. � ���� '2':	/*			   4   5 8   11				*/
	currentNode = currentNode->leftNode;						/*			      / / \   \				*/
	assert( currentNode->key == 2 );							/*				 7 9  10  12			*/
	AddNodeInLeft( currentNode, new NodeOfTree( 4 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 5 ) );

	// ��������� � ������� ������� ���� '2', �.�. � ���� 5:
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	AddNodeInLeft( currentNode, new NodeOfTree( 7 ) );

	// ��������� � ������� ������� ���� '1', �.�. � ���� '3':
	currentNode = myTree->rightNode;
	assert( currentNode->key == 3 );
	AddNodeInLeft( currentNode, new NodeOfTree( 8 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 11 ) );

	// ��������� � ������ ������� ���� '3', �.�. � ���� '8':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 8 );
	AddNodeInLeft( currentNode, new NodeOfTree( 9 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 10 ) );

	// ��������� �� ���� '8' � ������� ������� ���� '3', �.�. � ���� '11':
	currentNode = currentNode->parentNode->rightNode;
	assert( currentNode->key == 11 );
	AddNodeInRight( currentNode, new NodeOfTree( 12 ) );
	/*
	myTree = new NodeOfTree;
	currentNode = myTree;
	currentNode->key = 1;
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 2;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 3;

	// ��������� � ������ ������� ���� '1', �.�. � ���� '2':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 2 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 4;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 5;

	// ��������� � ������� ������� ���� '2', �.�. � ���� 5:
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 7;

	// ��������� � ������� ������� ���� '1', �.�. � ���� '3':
	currentNode = myTree->rightNode;
	assert( currentNode->key == 3 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 8;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 11;
	
	// ��������� � ������ ������� ���� '3', �.�. � ���� '8':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 8 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 9;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 10;
	
	// ��������� �� ���� '8' � ������� ������� ���� '3', �.�. � ���� '11':
	currentNode = currentNode->parentNode->rightNode;
	assert( currentNode->key == 11 );
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 12;
	*/
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	assert( !CheckParentalLinks( myTree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myTree );
	numOfNodes = NumOfNodes( myTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myTree )  =  " << IsItAVL_Tree( myTree ) << endl
		<< "IsItIdealBalancedTree( myTree )  =  " << IsItIdealBalancedTree( myTree ) << endl
		<< "IsItBinarySearchTree( myTree )  =  " << IsItBinarySearchTree( myTree ) << endl << endl;

	cout << "������������ ������������ �������� ����������������� ������ �� ������������ ��������� ������ � ������� ������� " << endl 
		<< "BuildIdealBalancedTreeFrom(...):" << endl;
	assert( myTree != NULL );
	myBalancedTree = BuildIdealBalancedTreeFrom( myTree );
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myBalancedTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myBalancedTree );
	numOfNodes = NumOfNodes( myBalancedTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myBalancedTree )  =  " << IsItAVL_Tree( myBalancedTree ) << endl
		<< "IsItIdealBalancedTree( myBalancedTree )  =  " << IsItIdealBalancedTree( myBalancedTree ) << endl
		<< "IsItBinarySearchTree( myBalancedTree )  =  " << IsItBinarySearchTree( myBalancedTree ) << endl << endl

		<< "Address of myTree:  " << myTree << endl						// ����� ������ ����� ������ myTree.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;	// ����� ������ ����� ������ myBalancedTree.
	FreeMem( myTree );													// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( myBalancedTree );											// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of myTree:  " << myTree << endl;					// ����� ������ ����� ������ ����� ��� ��������.
	cout << "Address of myBalancedTree:  " << myBalancedTree << endl;	// ����� ������ ����� ������ ����� ��� ��������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������������ ������ � ������� ������� AddNode(...):" << endl;
	int arrayOfInt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int arrayOfInt[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9};
	int len = sizeof( arrayOfInt ) / sizeof( arrayOfInt[0] );
	cout << "arrayOfInt: ";
	for( int i = 0; i < len; i++ )
	{
		cout << arrayOfInt[i] << " ";
		// ���� �� ��������� ���� ����� ���� ������ ���� ����������� ����������������!
		myTree = AddNode( arrayOfInt[i], myTree );
		//AddNode_2( arrayOfInt[i], myTree );
	}
	cout << endl << "len  =  " << len << endl;
	assert( myTree != NULL );
	cout << endl << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	assert( !CheckParentalLinks( myTree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myTree );
	numOfNodes = NumOfNodes( myTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		/*
		<< "Height( myTree )  =  " << Height( myTree ) << endl
		<< "Height( myTree->rightNode )  =  " << Height( myTree->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode ) << endl
		<< "Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode )  =  " << Height( myTree->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode->rightNode ) << endl
		<< endl
		*/
		<< "IsItAVL_Tree( myTree )  =  " << IsItAVL_Tree( myTree ) << endl
		<< "IsItBinarySearchTree( myTree )  =  " << IsItBinarySearchTree( myTree ) << endl
		<< "�����, ��� �������������� ������ ��������� �����������, �.�. ����������� ������������������, �.�. ��� ���� �� ������ ��������� ���� �� ������." << endl << endl

		<< "Address of myTree:  " << myTree << endl;	// ����� ������ ����� ������.
	FreeMem( myTree );									// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of myTree:  " << myTree << endl;	// ����� ������ ����� ������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������������ ������ � ������� ������� AddNode_2(...):" << endl;
	len = sizeof( arrayOfInt ) / sizeof( arrayOfInt[0] );
	SortArrayDescending<int>( arrayOfInt, len );
	//SortArrayDescending( arrayOfInt, len );		// ����� ��������� ������� ����� ������� � ���, � ���� ������ ���������� ��� �������, �.�. ��������� ��� Type ������������ ����������.
	cout << "������ arrayOfInt ����� ������ ������� SortArrayDescending(...): " << endl;
	for( int i = 0; i < len; i++ ) 
	{
		cout << arrayOfInt[i] << " ";
		// ���� �� ��������� ���� ����� ���� ������ ���� ����������� ����������������!
		//myTree = AddNode( arrayOfInt[i], myTree );
		AddNode_2( arrayOfInt[i], myTree );
	}
	cout << endl << "len  =  " << len << endl;
	assert( myTree != NULL );
	cout << endl << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	assert( !CheckParentalLinks( myTree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myTree );
	numOfNodes = NumOfNodes( myTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myTree )  =  " << IsItAVL_Tree( myTree ) << endl
		<< "IsItBinarySearchTree( myTree )  =  " << IsItBinarySearchTree( myTree ) << endl
		<< "�����, ��� �������������� ������ ��������� �����������, �.�. ����������� ������������������, �.�. ��� ���� �� ������ ��������� ���� �� ������." << endl;
	/*
	������ ��������� 2 ������:
	1) ���������� �������� ����������������� ������, �.�. ������ � �������� � ����� ��� ��������� 
	����� ����� � ��� ����� � ������ ����������� ���������� �� ����� ��� �� 1;
	2) ���������� ��� ������ ��������� ������, �.�. ������ ������ � �������� ��� ������ ���� ������ ������� ����� ���� ��� ����������� �� ����� ��������� 1, �
	���� ������ ���� ������ ������ ������ ����� � ����� ��������� ������� ���� � �� ������ ������ ����� � ������ ��������� ����� ����.
	*/
	
	cout << endl << "============================================================================" << endl;
	cout << "������������ ������������ ��� ������ ��������� ������ �� ������� � ������� ������� BuildAVL_BinarySearchTreeFrom(...):" << endl;
	len = sizeof( arrayOfInt ) / sizeof( arrayOfInt[0] );
	//SortArrayDescending<int>( arrayOfInt, len );
	SortArrayAscending( arrayOfInt, len );		// ����� ��������� ������� ����� ������� � ���, � ���� ������ ���������� ��� �������, �.�. ��������� ��� Type ������������ ����������.
	cout << "������ arrayOfInt ����� ������ ������� SortArrayAscending(...): " << endl;
	for( int i = 0; i < len; i++ ) cout << arrayOfInt[i] << " ";
	cout << endl << "len  =  " << len << endl;
	myAVL_Tree = BuildAVL_BinarySearchTreeFrom( arrayOfInt, len );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << endl;
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myAVL_Tree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myAVL_Tree );
	numOfNodes = NumOfNodes( myAVL_Tree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItIdealBalancedTree( myAVL_Tree )  =  " << IsItIdealBalancedTree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	cout << "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// ����� ������ ����� ������ myAVL_Tree.
	FreeMem( myAVL_Tree );											// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// ����� ������ ����� ������ ����� ��� ��������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������������ ��� ������ ��������� ������ �� ������������ ��������� ������ � ������� ������� BuildAVL_BinarySearchTreeFrom(...):" << endl;
	assert( myTree != NULL );
	myAVL_Tree = BuildAVL_BinarySearchTreeFrom( myTree );
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << endl;
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myAVL_Tree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myAVL_Tree );
	numOfNodes = NumOfNodes( myAVL_Tree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItIdealBalancedTree( myAVL_Tree )  =  " << IsItIdealBalancedTree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl;

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������ ����������� ������� ��������������� ��� ��� ������ ��������� ������." << endl;
	cout << "���� ������� FindKeyInBinarySearchTree(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKeyInBinarySearchTree( myAVL_Tree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << "��� ������������ ����� �� ������ �������!" << endl << endl;

	int k = 5;
    myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
    cout << "����� ������ ����� �������� ���� � ������ " << k << ": \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;
	
	k = 12;
	myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );	// ����� � ��� ��������� ������������, �.�. ������ DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
	//DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
    cout << "����� ������ ����� �������� ���� � ������ " << k << ", �������� ��� �� ������ (������ �� ����������): \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << endl;
	
	myAVL_Tree = InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 12 );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	myAVL_Tree = InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 14 );	// ����� � ��� ��������� ������������, �.�. ������ InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 14 );
	//InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 14 );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "����� ������ ����� ���������� ���� ����� � ������� 12 � 14: \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	k = 8;
	myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
    cout << "����� ������ ����� �������� ���� � ������ " << k << ": \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	k = 4;
	myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );	// ������ ��������� ������ ��� ������� ������� ������ ��� ������ ��������� ������. � ������ ����� ���� parentNode ����������� �� ������ nullptr, � ������ ����.
    cout << "����� ������ ����� �������� ���� � ������ " << k << ": \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );	// ������ ��������� ��������� �� �� ����, ��� � ����� ������ myAVL_Tree ���� parentNode ����������� �� ������ nullptr. � ���������� �� ����� ������� � �������� �����, ��������� �������� �� ������� ������.
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	cout << endl
		<< "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// ����� ������ ����� ������ myAVL_Tree.
	FreeMem( myAVL_Tree );											// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// ����� ������ ����� ������ ����� ��� ��������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������������ �������� ����������������� ������ �� ������� � ������� ������� BuildIdealBalancedTreeFrom(...):" << endl;
	//SortArrayAscending<int>( arrayOfInt, len );
	SortArrayAscending( arrayOfInt, len );		// ����� ��������� ������� ����� ������� � ���, � ���� ������ ���������� ��� �������, �.�. ��������� ��� Type ������������ ����������.
	myBalancedTree = BuildIdealBalancedTreeFrom( arrayOfInt, len );
	cout << "===Dump2===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myBalancedTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myBalancedTree );
	numOfNodes = NumOfNodes( myBalancedTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myBalancedTree )  =  " << IsItAVL_Tree( myBalancedTree ) << endl
		<< "IsItIdealBalancedTree( myBalancedTree )  =  " << IsItIdealBalancedTree( myBalancedTree ) << endl
		<< "IsItBinarySearchTree( myBalancedTree )  =  " << IsItBinarySearchTree( myBalancedTree ) << endl
		<< "�����, ��� �������������� ������ ��������� �������� ����������������." << endl;
	FreeMem( myBalancedTree );	// �������� ������ � ������������, ���������� ��� ���� ������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������������ �������� ����������������� ������ �� ������������ ��������� ������ � ������� ������� BuildIdealBalancedTreeFrom(...):" << endl;
	assert( myTree != NULL );
	myBalancedTree = BuildIdealBalancedTreeFrom( myTree );
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "����� ������ � ���������� �����:" << endl;
	TreePrint_4( myBalancedTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myBalancedTree );
	numOfNodes = NumOfNodes( myBalancedTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myBalancedTree )  =  " << IsItAVL_Tree( myBalancedTree ) << endl
		<< "IsItIdealBalancedTree( myBalancedTree )  =  " << IsItIdealBalancedTree( myBalancedTree ) << endl
		<< "IsItBinarySearchTree( myBalancedTree )  =  " << IsItBinarySearchTree( myBalancedTree ) << endl;
	/*
	cout << "Address of myTree:  " << myTree << endl					// ����� ������ ����� ������ myTree.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;	// ����� ������ ����� ������ myBalancedTree.
	FreeMem( myTree );													// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( myBalancedTree );											// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of myTree:  " << myTree << endl;					// ����� ������ ����� ������ ����� ��� ��������.
	cout << "Address of myBalancedTree:  " << myBalancedTree << endl;	// ����� ������ ����� ������ ����� ��� ��������.
	*/

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������������� ������� �������� - RotateLeft( NodeOfTree* ) � RotateRight( NodeOfTree* )." << endl;
	NodeOfTree *testTree;
	testTree = NULL;
	AddNode_2( 1, testTree );
	AddNode_2( 2, testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl;
	cout << "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateLeft( testTree );
	cout << "After RotateLeft( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl;
	assert( !CheckParentalLinks( testTree ) );
	cout << "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateRight( testTree );
	cout << "After RotateRight( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl;
	assert( !CheckParentalLinks( testTree ) );

	currentNode = testTree;
	if ( testTree->leftNode != nullptr ) currentNode = testTree->leftNode;
	else currentNode = testTree->rightNode;
	// currentNode ��������� �� ��������� �������� 1.
	CalculatingHeight( testTree );
	cout << "Height( testTree )  =  " << Height( testTree ) << endl
		<< "Height( currentNode )  =  " << Height( currentNode ) << endl
		<< "Height( nullptr )  =  " << Height( nullptr ) << endl
		<< "NumOfNodes( testTree )  =  " << NumOfNodes( testTree ) << endl
		<< "NumOfNodes( currentNode )  =  " << NumOfNodes( currentNode ) << endl
		<< "NumOfNodes( nullptr )  =  " << NumOfNodes( NULL ) << endl
		<< "IsItAVLTree( testTree )  =  " << IsItAVL_Tree( testTree ) << endl
		<< "IsItAVLTree( currentNode )  =  " << IsItAVL_Tree( currentNode ) << endl
		<< "IsItAVLTree( NULL )  =  " << IsItAVL_Tree( NULL ) << endl
		<< "IsItIdealBalancedTree( testTree )  =  " << IsItIdealBalancedTree( testTree ) << endl
		<< "IsItIdealBalancedTree( currentNode )  =  " << IsItIdealBalancedTree( currentNode ) << endl
		<< "IsItIdealBalancedTree( NULL )  =  " << IsItIdealBalancedTree( NULL ) << endl
		<< "IsItBinarySearchTree( testTree )  =  " << IsItIdealBalancedTree( testTree ) << endl
		<< "IsItBinarySearchTree( currentNode )  =  " << IsItIdealBalancedTree( currentNode ) << endl
		<< "IsItBinarySearchTree( NULL )  =  " << IsItIdealBalancedTree( NULL ) << endl
		<< endl << "===Dump2===" << endl;

	AddNode_2( 3, testTree );
	assert( !CheckParentalLinks( testTree ) );
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateLeft( testTree );
	cout << "After RotateLeft( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateLeft( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "After RotateLeft( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	cout << "������� � �������� ���� ��� ���� ���� ������:" << endl;
	AddNodeInRight( testTree->leftNode, new NodeOfTree( 7 ) );
	cout << endl;
	Dump2( testTree );
	cout << endl;

	testTree = RotateRight( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "After RotateRight( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateRight( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "After RotateRight( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;
	
	testTree = RotateRight( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "After RotateRight( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateLeft( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "After RotateLeft( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateLeft( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "After RotateLeft( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;

	testTree = RotateLeft( testTree );
	assert( !CheckParentalLinks( testTree ) );
	cout << "After RotateLeft( testTree ):" << endl
		<< "===Dump2===" << endl;
	Dump2( testTree );
	cout << endl
		<< "Height( testTree )  =  " << Height( testTree ) << endl
		<< endl << "------------------------------------------------" << endl;
	
	FreeMem( testTree );	// �������� ��������� ������ � ������������, ���������� ��� ���� ������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������ ������� SwapTrees( NodeOfTree* &t1, NodeOfTree* &t2 ):" << endl;
	assert( myTree != NULL );
	assert( myBalancedTree != NULL );
	NodeOfTree *t1, *t2, *copiedDegenerateTree, *copiedBalancedTree;
	copiedDegenerateTree = CopyFrom( myTree );								// ������ 1-� ����� ������������ ������, ������� ��� ����������� � ����������.
	copiedBalancedTree = CopyFrom( myBalancedTree );						// ������ 1-� ����� �������� ����������������� ������, ������� ��� ����������� � ����������.
	t1 = myTree;
	t2 = myBalancedTree;
	//assert( !CheckParentalLinks( t1 ) );
	//assert( !CheckParentalLinks( t2 ) );

	cout << "===Dump2( t1 )===" << endl;
    Dump2( t1 );
	cout << endl;
	cout << "===Dump2( t2 )===" << endl;
    Dump2( t2 );
	cout << endl;

	SwapTrees( t2->leftNode, t2->rightNode );
	cout << "SwapTrees( t2->leftNode, t2->rightNode );" << endl;
	cout << "===Dump2( t2 )===" << endl;
    Dump2( t2 );
	cout << endl;
	assert( !CheckParentalLinks( t2 ) );
	
	SwapTrees( t1, t2 );
	cout << "SwapTrees( t1, t2 );" << endl;

	cout << "===Dump2( t1 )===" << endl;
    Dump2( t1 );
	cout << endl;
	cout << "===Dump2( t2 )===" << endl;
    Dump2( t2 );
	cout << endl;

//	cout << "SwapTrees( t1, t2->leftNode );" << endl;
//	SwapTrees( t1, t2->leftNode );
//	cout << "SwapTrees( t1->rightNode, t2 );" << endl;
//	SwapTrees( t1->rightNode, t2 );
	cout << "SwapTrees( t1->rightNode, t2->leftNode->leftNode );" << endl;
	SwapTrees( t1->rightNode, t2->leftNode->leftNode );

	cout << "===Dump2( t1 )===" << endl;
    Dump2( t1 );
	cout << endl;
	cout << "===Dump2( t2 )===" << endl;
    Dump2( t2 );
	cout << endl;
	assert( !CheckParentalLinks( t1 ) );
	assert( !CheckParentalLinks( t2 ) );

	FreeMem( t1 );															// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( t2 );															// �������� ������ � ������������, ���������� ��� ���� ������.
	NodeOfTree *copiedDegenerateTree_2, *copiedBalancedTree_2;
	copiedDegenerateTree_2 = CopyFrom( copiedDegenerateTree );				// ������ 2-� ����� ������������ ������, ������� ��� ����������� � ����������.
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// ������ 2-� ����� �������� ����������������� ������, ������� ��� ����������� � ����������.
	
	//��������������� ������� t1 � t2 � ������� �������� ������ t1 ��� ���������� �����:
	t1 = copiedBalancedTree;
	t2 = copiedDegenerateTree;
	wantedKey = 3;
	currentNode = FindKey( t1, wantedKey );
	AddNodeInRight( currentNode, new NodeOfTree( 2 ) );
	DeleteNode( currentNode->leftNode );

	cout << "��������������� ������� t1 � t2 � ������� �������� ������ t1 ��� ���������� �����:" << endl;
	cout << "===Dump2( t1 )===" << endl;
    Dump2( t1 );
	cout << endl;
	cout << "===Dump2( t2 )===" << endl;
    Dump2( t2 );
	cout << endl;

	cout << "SwapTrees( t1->rightNode->leftNode, t2->leftNode->leftNode );" << endl;
	SwapTrees( t1->rightNode->leftNode, t2->leftNode->leftNode );

	cout << "===Dump2( t1 )===" << endl;
    Dump2( t1 );
	cout << endl;
	cout << "===Dump2( t2 )===" << endl;
    Dump2( t2 );
	cout << endl;
	assert( !CheckParentalLinks( t1 ) );
	assert( !CheckParentalLinks( t2 ) );

	cout << "------------------------------------------------" << endl;
	height = CalculatingHeight( t1 );
	numOfNodes = NumOfNodes( t1 );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( t1 )  =  " << IsItAVL_Tree( t1 ) << endl
		<< "IsItIdealBalancedTree( t1 )  =  " << IsItIdealBalancedTree( t1 ) << endl
		<< "IsItBinarySearchTree( t1 )  =  " << IsItBinarySearchTree( t1 ) << endl << endl
	
		<< "Address of t1:  " << t1 << endl						// ����� ������ ����� ������.
		<< "Address of t2:  " << t2 << endl;					// ����� ������ ����� ������.
	FreeMem( t1 );												// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( t2 );												// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of t1:  " << t1 << endl					// ����� ������ ����� ������ ����� �������� ������.
		<< "Address of t2:  " << t2 << endl;					// ����� ������ ����� ������ ����� �������� ������.
//	assert( myTree == NULL );			// ���� ���� ����������� �����, ��������� �������� ���������� ������, ��� ��������� myTree ���������� ��������� �� ��� �������� ������!
//	assert( myBalancedTree == NULL );	// ���� ���� ����������� �����, ��������� �������� ���������� ������, ��� ��������� myBalancedTree ���������� ��������� �� ��� �������� ������!

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������ ������� Swap( NodeOfTree* a, NodeOfTree* b )." << endl << endl;

	cout << "������ � ������� �������������� ���� �������� ������� ������ ��������:" << endl << endl;
	assert( copiedDegenerateTree_2 != NULL );
	assert( copiedBalancedTree_2 != NULL );
	copiedDegenerateTree = copiedDegenerateTree_2;
	copiedBalancedTree = copiedBalancedTree_2;
	NodeOfTree *a, *b;
	copiedDegenerateTree_2 = CopyFrom( copiedDegenerateTree );				// ������ 3-� ����� ������������ ������, ������� ��� ����������� � ����������.
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// ������ 3-� ����� �������� ����������������� ������, ������� ��� ����������� � ����������.

	a = copiedDegenerateTree;
	b = copiedBalancedTree;
	b->key = 100;
	wantedKey = 6;
	a = FindKey( a, wantedKey );
	a = DeleteNode( a );

	cout << "===Dump2( a )===" << endl;
    Dump2( a );
	cout << endl;
	cout << "===Dump2( b )===" << endl;
    Dump2( b );
	cout << endl;

	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	cout << "===Dump2( a )===" << endl;
    Dump2( a );
	cout << endl;
	cout << "===Dump2( b )===" << endl;
    Dump2( b );
	cout << endl;
	assert( !CheckParentalLinks( a ) );
	assert( !CheckParentalLinks( b ) );
	cout << "------------------------------------------------" << endl;
	cout << "��� ������, � ������� �������������� ���� �� ������� ������������� �����������." << endl << endl;

	myTree = a;				// ���������� ����� ������ ��� ����������� � ���������� ��� ������������ ������.
	myBalancedTree = b;		// �������� ���������������� ������ ������ ��������� �� ����� ������.

	a = myBalancedTree;
	wantedKey = 3;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "myBalancedTree = b;" << endl
		<< "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� ���� b, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 7;
	a = FindKey( myBalancedTree, wantedKey );
	b = myBalancedTree;

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� �� ������ ������, ����� ��� ������ ��������� �� ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 5;
	a = FindKey( myBalancedTree, wantedKey );
	b = myBalancedTree;

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� �� ������ ������, ����� ��� ������ ��������� �� ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "------------------------------------------------" << endl;
	cout << "��� ������, � ������� �������������� ���� ������� ������������� �����������." << endl << endl;

	a = myBalancedTree;
	wantedKey = 4;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� ���� a, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 5;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 9;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� ���� a, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 5;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 2;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� ���� a, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 8;
	a = FindKey( myBalancedTree, wantedKey );
	b = myBalancedTree;

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� �� ������ ������ ������, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 3;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 4;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� ���� a, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 6;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 4;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� ���� a, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 7;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 3;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� ���� a, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "------------------------------------------------" << endl;

	cout << "������ � ������� �������������� ���� �� �������� ������� � �� ������� ������������� �����������." << endl << endl;

	wantedKey = 7;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 9;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� �� ������ ������, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 9;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 2;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� �� ������ ������, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 1;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 2;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� �� ������ ������, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	wantedKey = 2;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 4;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// ����� ���������� ������ ������� Swap ���������� ��������� ������, ����������� � ��������� myBalancedTree, � ��������� myBalancedTree �������� ��������� �� �� ������ ������, ����� ��� ������ ��������� �� ������ ������.
	myBalancedTree = RootOfTree( myBalancedTree ); // ������� ���������� ������� ������� RootOfTree, ������� ���������� ������ ������.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	cout << "Address of myTree:  " << myTree << endl						// ����� ������ ����� ������.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;		// ����� ������ ����� ������.
	FreeMem( myTree );														// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( myBalancedTree );												// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of myTree:  " << myTree << endl						// ����� ������ ����� ������ ����� ��� ��������.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;		// ����� ������ ����� ������ ����� ��� ��������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������ ������� ReplaceSingleNode( NodeOfTree* &currentNode, NodeOfTree* singleNode ):" << endl;
	assert( copiedBalancedTree_2 );
	copiedBalancedTree = copiedBalancedTree_2;
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// ������ 4-� ����� �������� ����������������� ������, ������� ��� ����������� � ����������.

	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;
	
	NodeOfTree *singleNode = new NodeOfTree( 100 );
//	currentNode = copiedBalancedTree;
//	ReplaceSingleNode( currentNode, singleNode );
//	cout << "currentNode = copiedBalancedTree;" << endl
//		<< "ReplaceSingleNode( currentNode, singleNode );" << endl;
	ReplaceSingleNode( copiedBalancedTree, singleNode );
	cout << "ReplaceSingleNode( copiedBalancedTree, singleNode );" << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( copiedBalancedTree ) );
	
	singleNode = new NodeOfTree( 100 );
	currentNode = copiedBalancedTree->leftNode;
	ReplaceSingleNode( currentNode, singleNode );
	singleNode = new NodeOfTree( 100 );
	currentNode = copiedBalancedTree->rightNode;
	ReplaceSingleNode( currentNode, singleNode );
	cout << "currentNode = copiedBalancedTree->leftNode;" << endl
		<< "ReplaceSingleNode( currentNode, singleNode );" << endl
		<< "currentNode = copiedBalancedTree->rightNode;" << endl
		<< "ReplaceSingleNode( currentNode, singleNode );" << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( copiedBalancedTree ) );
	
	currentNode = copiedBalancedTree->rightNode->rightNode;
	ReplaceSingleNode( currentNode, new NodeOfTree( 100 ) );
	currentNode = copiedBalancedTree->leftNode->leftNode->leftNode;
	ReplaceSingleNode( currentNode, new NodeOfTree( 100 ) );
	cout << "currentNode = copiedBalancedTree->rightNode->rightNode;" << endl
		<< "ReplaceSingleNode( currentNode, new NodeOfTree( 100 ) );" << endl
		<< "currentNode = copiedBalancedTree->leftNode->leftNode->leftNode;" << endl
		<< "ReplaceSingleNode( currentNode, new NodeOfTree( 100 ) );" << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( copiedBalancedTree ) );

	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// ����� ������ ����� ������.
	FreeMem( copiedBalancedTree );													// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// ����� ������ ����� ������ ����� ��� ��������.
	
	cout << endl << "============================================================================" << endl;
	cout << "������������ ������ ������� ReplaceNodeInsteadNode( NodeOfTree* &nodeToBeDeleted, NodeOfTree* replacementNode ):" << endl;
	assert( copiedDegenerateTree_2 );
	assert( copiedBalancedTree_2 );
	copiedDegenerateTree = copiedDegenerateTree_2;
	copiedBalancedTree = copiedBalancedTree_2;
	copiedDegenerateTree_2 = CopyFrom( copiedDegenerateTree );				// ������ 4-� ����� ������������ ������, ������� ��� ����������� � ����������.
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// ������ 5-� ����� �������� ����������������� ������, ������� ��� ����������� � ����������.
	cout << "===Dump2( copiedDegenerateTree )===" << endl;
    Dump2( copiedDegenerateTree );
	cout << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( copiedDegenerateTree ) );
	assert( !CheckParentalLinks( copiedBalancedTree ) );
	
	NodeOfTree* nodeToBeDeleted, *replacementNode;

//	nodeToBeDeleted = copiedDegenerateTree;
//	replacementNode = copiedBalancedTree;
//	ReplaceNodeInsteadNode( nodeToBeDeleted, replacementNode );
//	cout << "nodeToBeDeleted = copiedDegenerateTree;" << endl
//		<< "replacementNode = copiedBalancedTree;" << endl
//		<< "ReplaceNodeInsteadNode( nodeToBeDeleted, replacementNode );" << endl;
	ReplaceNodeInsteadNode( copiedDegenerateTree, copiedBalancedTree );
	cout << "ReplaceNodeInsteadNode( copiedDegenerateTree, copiedBalancedTree );" << endl;
	cout << "===Dump2( copiedDegenerateTree )===" << endl;
	Dump2( copiedDegenerateTree );
	cout << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( copiedDegenerateTree ) );
	assert( !CheckParentalLinks( copiedBalancedTree ) );

	cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl		// ����� ������ ����� ������.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;			// ����� ������ ����� ������.
	if( copiedDegenerateTree != copiedBalancedTree )
	{
		FreeMem( copiedDegenerateTree );												// �������� ������ � ������������, ���������� ��� ���� ������.
		FreeMem( copiedBalancedTree );													// �������� ������ � ������������, ���������� ��� ���� ������.
		cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl	// ����� ������ ����� ������ ����� ��� ��������.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;			// ����� ������ ����� ������ ����� ��� ��������.
	}
	else // if( copiedDegenerateTree == copiedBalancedTree )
	{
		FreeMem( copiedDegenerateTree );												// �������� ������ � ������������, ���������� ��� ���� ������.
		cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl;	// ����� ������ ����� ������ ����� ��� ��������.
	}
	cout << endl << "------------------------------------------------" << endl;

	assert( copiedDegenerateTree_2 );
	assert( copiedBalancedTree_2 );
	copiedBalancedTree = copiedBalancedTree_2;
	copiedDegenerateTree = copiedDegenerateTree_2;
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// ������ 6-� ����� �������� ����������������� ������, ������� ��� ����������� � ����������.
	cout << "===Dump2( copiedDegenerateTree )===" << endl;
    Dump2( copiedDegenerateTree );
	cout << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;

	nodeToBeDeleted = copiedDegenerateTree->leftNode->leftNode->leftNode;
	replacementNode = copiedBalancedTree->rightNode;

	cout << "===Dump2( nodeToBeDeleted )===" << endl;
    Dump2( nodeToBeDeleted );
	cout << endl;
	cout << "===Dump2( replacementNode )===" << endl;
    Dump2( replacementNode );
	cout << endl;

	ReplaceNodeInsteadNode( nodeToBeDeleted, replacementNode );
	cout << "nodeToBeDeleted = copiedDegenerateTree->leftNode->leftNode->leftNode;" << endl
		<< "replacementNode = copiedBalancedTree->rightNode;" << endl
		<< "ReplaceNodeInsteadNode( nodeToBeDeleted, replacementNode );" << endl;
	cout << "===Dump2( copiedDegenerateTree )===" << endl;
	Dump2( copiedDegenerateTree );
	cout << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( copiedDegenerateTree ) );
	assert( !CheckParentalLinks( copiedBalancedTree ) );

	cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl	// ����� ������ ����� ������.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// ����� ������ ����� ������.
	FreeMem( copiedDegenerateTree );												// �������� ������ � ������������, ���������� ��� ���� ������.
	FreeMem( copiedBalancedTree );													// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl	// ����� ������ ����� ������ ����� �������� ������.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// ����� ������ ����� ������ ����� �������� ������.

	cout << endl << "============================================================================" << endl;
	cout << "������������ ������ ������� CheckParentalLinks( NodeOfTree* ):" << endl;
	assert( copiedBalancedTree_2 );
	copiedBalancedTree = copiedBalancedTree_2;
	assert( !CheckParentalLinks( copiedBalancedTree ) ); // � ������ ��� ������������ ����� � ������ �� ��������.
	
	// ����� �������� ��������� ������������ ����� ����� ����� ������:
	/*
	wantedKey = 4;
	a = FindKey( copiedBalancedTree, wantedKey );
	wantedKey = 2;
	b = FindKey( copiedBalancedTree, wantedKey );
	b->parentNode = a;
	*/
	/*
	wantedKey = 6;
	a = FindKey( copiedBalancedTree, wantedKey );
	a->parentNode = copiedBalancedTree;		// �������� ���� � ������ 6 ����� ����� ��������� ��������� �� ������ ������, ��� �������� ��� ������������ ����� � ��� ��������� �������!
	*/
	//copiedBalancedTree->leftNode->parentNode = copiedBalancedTree->rightNode;
	copiedBalancedTree->rightNode->parentNode = copiedBalancedTree->rightNode;	// ���� parentNode ����� ����� ��������� ��������� �� ���� �� ����, ��� �������� ��� ������������ ����� � ������ ������!

	cout << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;

	CheckParentalLinks( copiedBalancedTree );

	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// ����� ������ ����� ������.
	FreeMem( copiedBalancedTree );													// �������� ������ � ������������, ���������� ��� ���� ������.
	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// ����� ������ ����� ������ ����� �������� ������.

	cout << endl << "============================================================================" << endl;
	cout << endl << endl;
	char tempStr[2];
	cout << "Press any key and [Enter] to quite . . . ";
	cin >> tempStr;

	return 0;
}
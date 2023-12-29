// Проект иллюстрирующий работу с бинарными деревьями и шаблонами.
// Особеностью моей реализации бинарных деревьев является то, что в каждом узле дерева сохраняется указатель на его родительский узел.

#include "BinaryTrees.h"

#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

int main(int argc, char **argv)
{
	NodeOfTree *myTree, *currentNode, *myBalancedTree, *myAVL_Tree;

	setlocale( LC_ALL, "Russian" ); // В консоль можно выводить русские буквы.

	// Сформируем дерево самостоятельно в соответствии с рисунком на странице сайта: https://prog-cpp.ru/data-tree/
	myTree = new NodeOfTree( 1 );
	currentNode = myTree;										/*					1					*/
	AddNodeInLeft( currentNode, new NodeOfTree( 2 ) );			/*				   / \					*/
	AddNodeInRight( currentNode, new NodeOfTree( 3 ) );			/*				  2   3					*/
																/*				 / \   \				*/
	// Переходим к левому потомку узла '1', т.е. к узлу '2':	/*				4   5   6				*/
	currentNode = currentNode->leftNode;						/*				   /   / \				*/
	assert( currentNode->key == 2 );							/*				  7   8   9				*/
	AddNodeInLeft( currentNode, new NodeOfTree( 4 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 5 ) );

	// Переходим к правому потомку узла '2', т.е. к узлу '5':
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	AddNodeInLeft( currentNode, new NodeOfTree( 7 ) );
	assert( currentNode->rightNode == NULL );

	// Переходим к правому потомку узла '1', т.е. к узлу '3':
	currentNode = ( *myTree ).rightNode;						// Вместо	currentNode = myTree->rightNode;
	assert( ( *currentNode ).key == 3 );						// Вместо	assert( currentNode->key == 3 );
	AddNodeInRight( currentNode, new NodeOfTree( 6 ) );

	// Переходим к правому потомку узла '3', т.е. к узлу '6':
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

	// Переходим к левому потомку узла '1', т.е. к узлу '2':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 2 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 4;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 5;

	// Переходим к правому потомку узла '2', т.е. к узлу '5':
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 7;
	assert( currentNode->rightNode == NULL );

	// Переходим к правому потомку узла '1', т.е. к узлу '3':
	currentNode = ( *myTree ).rightNode;
	assert( ( *currentNode ).key == 3 );						// Вместо	assert( currentNode->key == 3 );
	( *currentNode ).rightNode = new NodeOfTree;				// Вместо	currentNode->rightNode = new NodeOfTree;
	( *( *currentNode ).rightNode ).parentNode = currentNode;	// Вместо	currentNode->rightNode->parentNode = currentNode;
	( *( *currentNode ).rightNode ).key = 6;					// Вместо	currentNode->rightNode->key = 6;
	assert( ( *currentNode ).leftNode == NULL );				// Вместо	assert( currentNode->leftNode == NULL );

	// Переходим к правому потомку узла '3', т.е. к узлу '6':
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
	
	cout << "Демонстрация обхода дерева реализующего итерационный подход. При этом используется горизонтальный обход:" << endl;
	TreePrint( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "Демонстрация обхода дерева реализующего итерационный подход. При этом используется вертикальный прямой обход:" << endl;
	TreePrint_2( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "Демонстрация Обхода дерева реализующего итерационный подход. При этом используется вертикальный обратный обход:" << endl;
	TreePrint_3( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "Демонстрация обхода дерева реализующего рекурсивный подход в префиксной форме:" << endl;
	TreePrint_4( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "Демонстрация обхода дерева реализующего рекурсивный подход в инфиксной форме:" << endl;
	TreePrint_5( myTree );
	cout << endl << "------------------------------------------------" << endl;
	
	cout << "Демонстрация обхода дерева реализующего рекурсивный подход в постфиксной форме:" << endl;
	TreePrint_6( myTree );
	cout << endl << "------------------------------------------------" << endl;

	int height = CalculatingHeight( myTree ); // Вычисления высоты дерева и всех его поддеревьев.
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

	cout << "Копируем только левое поддерево исходного дерева:" << endl;
	copiedTree = CopyFrom( myTree->leftNode );
	assert( !CheckParentalLinks( copiedTree ) );
	cout << "===Dump2( copiedTree )===" << endl;
    Dump2( copiedTree );
	cout << endl;
	FreeMem( copiedTree );										// Удаление дерева и освобождение, выделенной под него памяти.

	cout << "Копируем только правое поддерево исходного дерева:" << endl;
	copiedTree = CopyFrom( myTree->rightNode );
	assert( !CheckParentalLinks( copiedTree ) );
	cout << "===Dump2( copiedTree )===" << endl;
    Dump2( copiedTree );
	cout << endl;
	FreeMem( copiedTree );										// Удаление дерева и освобождение, выделенной под него памяти.

	cout << "Копируем всё дерево целиком:" << endl;
	copiedTree = CopyFrom( myTree );
	assert( !CheckParentalLinks( copiedTree ) );
	cout << "===Dump2( copiedTree )===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "Удаление одного листа (самого левого):" << endl;
	for( currentNode = copiedTree; currentNode->leftNode != currentNode->rightNode && currentNode->leftNode != nullptr; currentNode = ( currentNode->leftNode != nullptr? currentNode->leftNode: currentNode->rightNode ) );
	copiedTree = DeleteNode( currentNode );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;
	
	cout << "Удаление левового поддерева:" << endl;
	copiedTree = DeleteNode( copiedTree->leftNode );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "Удаление правого поддерева:" << endl;
	copiedTree = DeleteNode( copiedTree->rightNode );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "Удаление единственного узла - корня:" << endl;
	copiedTree = DeleteNode( copiedTree );
	assert( copiedTree == nullptr );
	cout << "===Dump2===" << endl;
    Dump2( copiedTree );
	cout << endl;

	cout << "Демонстрация формирования АВЛ дерева бинарного поиска из поддерева, растущего из узла с ключом 3, исходного бинарного дерева:" << endl;
	assert( myTree->rightNode != NULL );
	myAVL_Tree = BuildAVL_BinarySearchTreeFrom( myTree->rightNode );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << endl;
	cout << "Обход дерева в префиксной форме:" << endl;
	TreePrint_4( myAVL_Tree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myAVL_Tree );
	numOfNodes = NumOfNodes( myAVL_Tree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItIdealBalancedTree( myAVL_Tree )  =  " << IsItIdealBalancedTree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl
	
//		<< "Address of myTree:  " << myTree << endl				// Вывод адреса корня исходного дерева.
		<< "Address of copiedTree:  " << copiedTree << endl		// Вывод адреса корня скопированного дерева.
		<< "Address of myAVL_Tree:  " << myAVL_Tree << endl;	// Вывод адреса корня дерева myAVL_Tree.
//	FreeMem( myTree );											// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( copiedTree );										// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( myAVL_Tree );										// Удаление дерева и освобождение, выделенной под него памяти.
//	cout << "Address of myTree:  " << myTree << endl;			// Вывод адреса корня дерева после его удаления.
	cout << "Address of copiedTree:  " << copiedTree << endl	// Вывод адреса корня дерева после его удаления.
		<< "Address of myAVL_Tree:  " << myAVL_Tree << endl;	// Вывод адреса корня дерева myAVL_Tree после его удаления.
//	assert( myTree == NULL );
	assert( !copiedTree );	// assert( copiedTree == nullptr );
	assert( nullptr == NULL );

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация поисковых функций:" << endl;
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	NodeOfTree* searchedNode;
	int wantedKey;
	cout << endl << "Тест функции FindKey(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << endl << "Тест функции FindKey_2(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey_2( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << endl << "Тест функции FindKey_3(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey_3( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << endl << "Тест функции FindKey_4(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKey_4( myTree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << "Все существующие ключи на дереве найдены всеми поисковыми функциями!" << endl;
	FreeMem( myTree );

	cout << endl << "============================================================================" << endl;
	cout << "Сформируем дерево самостоятельно т.о., что бы оно было АВЛ деревом, но не было бы идеально сбалансированным:" << endl;
	myTree = new NodeOfTree( 1 );
	currentNode = myTree;										/*					1					*/
	AddNodeInLeft( currentNode, new NodeOfTree( 2 ) );			/*				  /   \					*/
	AddNodeInRight( currentNode, new NodeOfTree( 3 ) );			/*				 2     3				*/
																/*				/ \   / \				*/
	// Переходим к левому потомку узла '1', т.е. к узлу '2':	/*			   4   5 8   11				*/
	currentNode = currentNode->leftNode;						/*			      / / \   \				*/
	assert( currentNode->key == 2 );							/*				 7 9  10  12			*/
	AddNodeInLeft( currentNode, new NodeOfTree( 4 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 5 ) );

	// Переходим к правому потомку узла '2', т.е. к узлу 5:
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	AddNodeInLeft( currentNode, new NodeOfTree( 7 ) );

	// Переходим к правому потомку узла '1', т.е. к узлу '3':
	currentNode = myTree->rightNode;
	assert( currentNode->key == 3 );
	AddNodeInLeft( currentNode, new NodeOfTree( 8 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 11 ) );

	// Переходим к левому потомку узла '3', т.е. к узлу '8':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 8 );
	AddNodeInLeft( currentNode, new NodeOfTree( 9 ) );
	AddNodeInRight( currentNode, new NodeOfTree( 10 ) );

	// Переходим от узла '8' к правому потомку узла '3', т.е. к узлу '11':
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

	// Переходим к левому потомку узла '1', т.е. к узлу '2':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 2 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 4;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 5;

	// Переходим к правому потомку узла '2', т.е. к узлу 5:
	currentNode = currentNode->rightNode;
	assert( currentNode->key == 5 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 7;

	// Переходим к правому потомку узла '1', т.е. к узлу '3':
	currentNode = myTree->rightNode;
	assert( currentNode->key == 3 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 8;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 11;
	
	// Переходим к левому потомку узла '3', т.е. к узлу '8':
	currentNode = currentNode->leftNode;
	assert( currentNode->key == 8 );
	currentNode->leftNode = new NodeOfTree;
	currentNode->leftNode->parentNode = currentNode;
	currentNode->leftNode->key = 9;
	currentNode->rightNode = new NodeOfTree;
	currentNode->rightNode->parentNode = currentNode;
	currentNode->rightNode->key = 10;
	
	// Переходим от узла '8' к правому потомку узла '3', т.е. к узлу '11':
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
	cout << "Обход дерева в префиксной форме:" << endl;
	TreePrint_4( myTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myTree );
	numOfNodes = NumOfNodes( myTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myTree )  =  " << IsItAVL_Tree( myTree ) << endl
		<< "IsItIdealBalancedTree( myTree )  =  " << IsItIdealBalancedTree( myTree ) << endl
		<< "IsItBinarySearchTree( myTree )  =  " << IsItBinarySearchTree( myTree ) << endl << endl;

	cout << "Демонстрация формирования идеально сбалансированного дерева из абстрактного бинарного дерева с помощью функции " << endl 
		<< "BuildIdealBalancedTreeFrom(...):" << endl;
	assert( myTree != NULL );
	myBalancedTree = BuildIdealBalancedTreeFrom( myTree );
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "Обход дерева в префиксной форме:" << endl;
	TreePrint_4( myBalancedTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myBalancedTree );
	numOfNodes = NumOfNodes( myBalancedTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myBalancedTree )  =  " << IsItAVL_Tree( myBalancedTree ) << endl
		<< "IsItIdealBalancedTree( myBalancedTree )  =  " << IsItIdealBalancedTree( myBalancedTree ) << endl
		<< "IsItBinarySearchTree( myBalancedTree )  =  " << IsItBinarySearchTree( myBalancedTree ) << endl << endl

		<< "Address of myTree:  " << myTree << endl						// Вывод адреса корня дерева myTree.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;	// Вывод адреса корня дерева myBalancedTree.
	FreeMem( myTree );													// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( myBalancedTree );											// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of myTree:  " << myTree << endl;					// Вывод адреса корня дерева после его удаления.
	cout << "Address of myBalancedTree:  " << myBalancedTree << endl;	// Вывод адреса корня дерева после его удаления.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация формирования дерева с помощью функции AddNode(...):" << endl;
	int arrayOfInt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int arrayOfInt[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9};
	int len = sizeof( arrayOfInt ) / sizeof( arrayOfInt[0] );
	cout << "arrayOfInt: ";
	for( int i = 0; i < len; i++ )
	{
		cout << arrayOfInt[i] << " ";
		// Одна из следующих двух строк кода должна быть обязательно закомментирована!
		myTree = AddNode( arrayOfInt[i], myTree );
		//AddNode_2( arrayOfInt[i], myTree );
	}
	cout << endl << "len  =  " << len << endl;
	assert( myTree != NULL );
	cout << endl << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	assert( !CheckParentalLinks( myTree ) );
	cout << "Обход дерева в префиксной форме:" << endl;
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
		<< "Видим, что сформированное дерево оказалось вырожденным, т.е. максимально разбалансированным, т.к. все узлы на дереве выстроены один за другим." << endl << endl

		<< "Address of myTree:  " << myTree << endl;	// Вывод адреса корня дерева.
	FreeMem( myTree );									// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of myTree:  " << myTree << endl;	// Вывод адреса корня дерева.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация формирования дерева с помощью функции AddNode_2(...):" << endl;
	len = sizeof( arrayOfInt ) / sizeof( arrayOfInt[0] );
	SortArrayDescending<int>( arrayOfInt, len );
	//SortArrayDescending( arrayOfInt, len );		// Вызов шаблонной функции можно сделать и так, в этом случае компилятор сам выведет, т.е. определит тип Type передаваемых аргументов.
	cout << "Массив arrayOfInt после вызова функции SortArrayDescending(...): " << endl;
	for( int i = 0; i < len; i++ ) 
	{
		cout << arrayOfInt[i] << " ";
		// Одна из следующих двух строк кода должна быть обязательно закомментирована!
		//myTree = AddNode( arrayOfInt[i], myTree );
		AddNode_2( arrayOfInt[i], myTree );
	}
	cout << endl << "len  =  " << len << endl;
	assert( myTree != NULL );
	cout << endl << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	assert( !CheckParentalLinks( myTree ) );
	cout << "Обход дерева в префиксной форме:" << endl;
	TreePrint_4( myTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myTree );
	numOfNodes = NumOfNodes( myTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myTree )  =  " << IsItAVL_Tree( myTree ) << endl
		<< "IsItBinarySearchTree( myTree )  =  " << IsItBinarySearchTree( myTree ) << endl
		<< "Видим, что сформированное дерево оказалось вырожденным, т.е. максимально разбалансированным, т.к. все узлы на дереве выстроены один за другим." << endl;
	/*
	Отсюда возникают 2 задачи:
	1) построения идеально сбалансированного дерева, т.е. дерева у которого в любом его поддереве 
	число узлов в его левых и правых поддеревьях отличается не более чем на 1;
	2) построения АВЛ дерева бинарного поиска, т.е. такого дерева у которого для любого узла модуль разницы высот двух его поддеревьев не может превышать 1, и
	ключ любого узла дерева больше любого ключа в левом поддереве данного узла и не больше любого ключа в правом поддереве этого узла.
	*/
	
	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация формирования АВЛ дерева бинарного поиска из массива с помощью функции BuildAVL_BinarySearchTreeFrom(...):" << endl;
	len = sizeof( arrayOfInt ) / sizeof( arrayOfInt[0] );
	//SortArrayDescending<int>( arrayOfInt, len );
	SortArrayAscending( arrayOfInt, len );		// Вызов шаблонной функции можно сделать и так, в этом случае компилятор сам выведет, т.е. определит тип Type передаваемых аргументов.
	cout << "Массив arrayOfInt после вызова функции SortArrayAscending(...): " << endl;
	for( int i = 0; i < len; i++ ) cout << arrayOfInt[i] << " ";
	cout << endl << "len  =  " << len << endl;
	myAVL_Tree = BuildAVL_BinarySearchTreeFrom( arrayOfInt, len );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << endl;
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "Обход дерева в префиксной форме:" << endl;
	TreePrint_4( myAVL_Tree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myAVL_Tree );
	numOfNodes = NumOfNodes( myAVL_Tree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItIdealBalancedTree( myAVL_Tree )  =  " << IsItIdealBalancedTree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	cout << "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// Вывод адреса корня дерева myAVL_Tree.
	FreeMem( myAVL_Tree );											// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// Вывод адреса корня дерева после его удаления.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация формирования АВЛ дерева бинарного поиска из абстрактного бинарного дерева с помощью функции BuildAVL_BinarySearchTreeFrom(...):" << endl;
	assert( myTree != NULL );
	myAVL_Tree = BuildAVL_BinarySearchTreeFrom( myTree );
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << endl;
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "Обход дерева в префиксной форме:" << endl;
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
	cout << "Демонстрация работы специальных функций предназначенных для АВЛ дерева бинарного поиска." << endl;
	cout << "Тест функции FindKeyInBinarySearchTree(...):" << endl;
	for( wantedKey = 0; wantedKey <= 10; wantedKey++ )
	{
		searchedNode = FindKeyInBinarySearchTree( myAVL_Tree, wantedKey );
		assert( searchedNode == nullptr || searchedNode->key == wantedKey );
		if( searchedNode ) cout << "searchedNode->key  =  " << searchedNode->key << endl;
	}
	cout << "Все существующие ключи на дереве найдены!" << endl << endl;

	int k = 5;
    myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
    cout << "Вывод дерева после удаления узла с ключом " << k << ": \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;
	
	k = 12;
	myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );	// Можно и без оператора присваивания, т.е. просто DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
	//DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
    cout << "Вывод дерева после удаления узла с ключом " << k << ", которого нет на дереве (дерево не изменяется): \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << endl;
	
	myAVL_Tree = InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 12 );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	myAVL_Tree = InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 14 );	// Можно и без оператора присваивания, т.е. просто InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 14 );
	//InsertNodeToAVL_BinarySearchTree( myAVL_Tree, 14 );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "Вывод дерева после добавления двух узлов с ключами 12 и 14: \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	k = 8;
	myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );
    cout << "Вывод дерева после удаления узла с ключом " << k << ": \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	k = 4;
	myAVL_Tree = DeleteNodeFromAVL_BinarySearchTree( myAVL_Tree, k );	// Раньше возникала ошибка при попытке удалить корень АВЛ дерева бинарного поиска. У нового корня поле parentNode оказывалось НЕ равным nullptr, а должно было.
    cout << "Вывод дерева после удаления узла с ключом " << k << ": \n";
    cout << endl << "===Dump2===" << endl;
    Dump2( myAVL_Tree );
	assert( !CheckParentalLinks( myAVL_Tree ) );	// Раньше возникало зависание из за того, что у корня дерева myAVL_Tree поле parentNode оказывалось не равным nullptr. В результате во время подъёма к текущему корню, программа выходила за границы дерева.
	cout << "IsItAVL_Tree( myAVL_Tree )  =  " << IsItAVL_Tree( myAVL_Tree ) << endl
		<< "IsItBinarySearchTree( myAVL_Tree )  =  " << IsItBinarySearchTree( myAVL_Tree ) << endl << endl;

	cout << endl
		<< "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// Вывод адреса корня дерева myAVL_Tree.
	FreeMem( myAVL_Tree );											// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of myAVL_Tree:  " << myAVL_Tree << endl;		// Вывод адреса корня дерева после его удаления.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация формирования идеально сбалансированного дерева из массива с помощью функции BuildIdealBalancedTreeFrom(...):" << endl;
	//SortArrayAscending<int>( arrayOfInt, len );
	SortArrayAscending( arrayOfInt, len );		// Вызов шаблонной функции можно сделать и так, в этом случае компилятор сам выведет, т.е. определит тип Type передаваемых аргументов.
	myBalancedTree = BuildIdealBalancedTreeFrom( arrayOfInt, len );
	cout << "===Dump2===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "Обход дерева в префиксной форме:" << endl;
	TreePrint_4( myBalancedTree );
	cout << endl << "------------------------------------------------" << endl;
	height = CalculatingHeight( myBalancedTree );
	numOfNodes = NumOfNodes( myBalancedTree );
	cout << "height  =  " << height << endl
		<< "numOfNodes  =  " << numOfNodes << endl
		<< "IsItAVL_Tree( myBalancedTree )  =  " << IsItAVL_Tree( myBalancedTree ) << endl
		<< "IsItIdealBalancedTree( myBalancedTree )  =  " << IsItIdealBalancedTree( myBalancedTree ) << endl
		<< "IsItBinarySearchTree( myBalancedTree )  =  " << IsItBinarySearchTree( myBalancedTree ) << endl
		<< "Видим, что сформированное дерево оказалось идеально сбалансированным." << endl;
	FreeMem( myBalancedTree );	// Удаление дерева и освобождение, выделенной под него памяти.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация формирования идеально сбалансированного дерева из абстрактного бинарного дерева с помощью функции BuildIdealBalancedTreeFrom(...):" << endl;
	assert( myTree != NULL );
	myBalancedTree = BuildIdealBalancedTreeFrom( myTree );
	cout << "===Dump2===" << endl;
    Dump2( myTree );
	cout << endl;
	cout << "===Dump2===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "Обход дерева в префиксной форме:" << endl;
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
	cout << "Address of myTree:  " << myTree << endl					// Вывод адреса корня дерева myTree.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;	// Вывод адреса корня дерева myBalancedTree.
	FreeMem( myTree );													// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( myBalancedTree );											// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of myTree:  " << myTree << endl;					// Вывод адреса корня дерева после его удаления.
	cout << "Address of myBalancedTree:  " << myBalancedTree << endl;	// Вывод адреса корня дерева после его удаления.
	*/

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация использования функций вращения - RotateLeft( NodeOfTree* ) и RotateRight( NodeOfTree* )." << endl;
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
	// currentNode указывает на поддерево глубиной 1.
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

	cout << "Добавим к среднему узлу ещё один узел справа:" << endl;
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
	
	FreeMem( testTree );	// Удаление тестового дерева и освобождение, выделенной под него памяти.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация работы функции SwapTrees( NodeOfTree* &t1, NodeOfTree* &t2 ):" << endl;
	assert( myTree != NULL );
	assert( myBalancedTree != NULL );
	NodeOfTree *t1, *t2, *copiedDegenerateTree, *copiedBalancedTree;
	copiedDegenerateTree = CopyFrom( myTree );								// Создаём 1-ю копию вырожденного дерева, которая нам понадобится в дальнейшем.
	copiedBalancedTree = CopyFrom( myBalancedTree );						// Создаём 1-ю копию идеально сбалансированного дерева, которая нам понадобится в дальнейшем.
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

	FreeMem( t1 );															// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( t2 );															// Удаление дерева и освобождение, выделенной под него памяти.
	NodeOfTree *copiedDegenerateTree_2, *copiedBalancedTree_2;
	copiedDegenerateTree_2 = CopyFrom( copiedDegenerateTree );				// Создаём 2-ю копию вырожденного дерева, которая нам понадобится в дальнейшем.
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// Создаём 2-ю копию идеально сбалансированного дерева, которая нам понадобится в дальнейшем.
	
	//Восстанавливаем деревья t1 и t2 и немного изменяем дерево t1 для очередного теста:
	t1 = copiedBalancedTree;
	t2 = copiedDegenerateTree;
	wantedKey = 3;
	currentNode = FindKey( t1, wantedKey );
	AddNodeInRight( currentNode, new NodeOfTree( 2 ) );
	DeleteNode( currentNode->leftNode );

	cout << "Восстанавливаем деревья t1 и t2 и немного изменяем дерево t1 для очередного теста:" << endl;
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
	
		<< "Address of t1:  " << t1 << endl						// Вывод адреса корня дерева.
		<< "Address of t2:  " << t2 << endl;					// Вывод адреса корня дерева.
	FreeMem( t1 );												// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( t2 );												// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of t1:  " << t1 << endl					// Вывод адреса корня дерева после удаления дерева.
		<< "Address of t2:  " << t2 << endl;					// Вывод адреса корня дерева после удаления дерева.
//	assert( myTree == NULL );			// Если этот комментарий снять, программа аварийно завершится потому, что указатель myTree продолжает указывать на уже удалённое дерево!
//	assert( myBalancedTree == NULL );	// Если этот комментарий снять, программа аварийно завершится потому, что указатель myBalancedTree продолжает указывать на уже удалённое дерево!

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация работы функции Swap( NodeOfTree* a, NodeOfTree* b )." << endl << endl;

	cout << "Случай в котором переставляемые узлы являются корнями разных деревьев:" << endl << endl;
	assert( copiedDegenerateTree_2 != NULL );
	assert( copiedBalancedTree_2 != NULL );
	copiedDegenerateTree = copiedDegenerateTree_2;
	copiedBalancedTree = copiedBalancedTree_2;
	NodeOfTree *a, *b;
	copiedDegenerateTree_2 = CopyFrom( copiedDegenerateTree );				// Создаём 3-ю копию вырожденного дерева, которая нам понадобится в дальнейшем.
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// Создаём 3-ю копию идеально сбалансированного дерева, которая нам понадобится в дальнейшем.

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
	cout << "Ряд тестов, в которых переставляемые узлы НЕ связаны родительскими отношениями." << endl << endl;

	myTree = a;				// Сохранение этого адреса нам понадобится в дальнейшем для освобождения памяти.
	myBalancedTree = b;		// Идеально сбалансированное дерево теперь находится по этому адресу.

	a = myBalancedTree;
	wantedKey = 3;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "myBalancedTree = b;" << endl
		<< "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать на узел b, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать не на корень дерева, тогда как должен указывать на корень.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать не на корень дерева, тогда как должен указывать на корень.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "------------------------------------------------" << endl;
	cout << "Ряд тестов, в которых переставляемые узлы связаны родительскими отношениями." << endl << endl;

	a = myBalancedTree;
	wantedKey = 4;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать на узел a, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать на узел a, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать на узел a, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать не на корень своего дерева, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать на узел a, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать на узел a, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать на узел a, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );
	cout << "------------------------------------------------" << endl;

	cout << "Случаи в которых переставляемые узлы НЕ являются корнями и НЕ связаны родительскими отношениями." << endl << endl;

	wantedKey = 7;
	a = FindKey( myBalancedTree, wantedKey );
	wantedKey = 9;
	b = FindKey( myBalancedTree, wantedKey );

	cout << "a->key = " << a->key << ",  b->key = " << b->key << endl;
	Swap( a, b );
	cout << "Swap( a, b );" << endl;

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать НЕ на корень дерева, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать НЕ на корень дерева, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать НЕ на корень дерева, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
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

	// После последнего вызова функции Swap происходит изменение адреса, хранящегося в указателе myBalancedTree, и указатель myBalancedTree начинает указывать НЕ на корень дерева, тогда как должен указывать на корень дерева.
	myBalancedTree = RootOfTree( myBalancedTree ); // Поэтому необходимо вызвать функцию RootOfTree, которая возвращает корень дерева.
	cout << "===Dump2( myBalancedTree )===" << endl;
    Dump2( myBalancedTree );
	cout << endl;
	assert( !CheckParentalLinks( myBalancedTree ) );

	cout << "Address of myTree:  " << myTree << endl						// Вывод адреса корня дерева.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;		// Вывод адреса корня дерева.
	FreeMem( myTree );														// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( myBalancedTree );												// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of myTree:  " << myTree << endl						// Вывод адреса корня дерева после его удаления.
		<< "Address of myBalancedTree:  " << myBalancedTree << endl;		// Вывод адреса корня дерева после его удаления.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация работы функции ReplaceSingleNode( NodeOfTree* &currentNode, NodeOfTree* singleNode ):" << endl;
	assert( copiedBalancedTree_2 );
	copiedBalancedTree = copiedBalancedTree_2;
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// Создаём 4-ю копию идеально сбалансированного дерева, которая нам понадобится в дальнейшем.

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

	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// Вывод адреса корня дерева.
	FreeMem( copiedBalancedTree );													// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// Вывод адреса корня дерева после его удаления.
	
	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация работы функции ReplaceNodeInsteadNode( NodeOfTree* &nodeToBeDeleted, NodeOfTree* replacementNode ):" << endl;
	assert( copiedDegenerateTree_2 );
	assert( copiedBalancedTree_2 );
	copiedDegenerateTree = copiedDegenerateTree_2;
	copiedBalancedTree = copiedBalancedTree_2;
	copiedDegenerateTree_2 = CopyFrom( copiedDegenerateTree );				// Создаём 4-ю копию вырожденного дерева, которая нам понадобится в дальнейшем.
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// Создаём 5-ю копию идеально сбалансированного дерева, которая нам понадобится в дальнейшем.
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

	cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl		// Вывод адреса корня дерева.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;			// Вывод адреса корня дерева.
	if( copiedDegenerateTree != copiedBalancedTree )
	{
		FreeMem( copiedDegenerateTree );												// Удаление дерева и освобождение, выделенной под него памяти.
		FreeMem( copiedBalancedTree );													// Удаление дерева и освобождение, выделенной под него памяти.
		cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl	// Вывод адреса корня дерева после его удаления.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;			// Вывод адреса корня дерева после его удаления.
	}
	else // if( copiedDegenerateTree == copiedBalancedTree )
	{
		FreeMem( copiedDegenerateTree );												// Удаление дерева и освобождение, выделенной под него памяти.
		cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl;	// Вывод адреса корня дерева после его удаления.
	}
	cout << endl << "------------------------------------------------" << endl;

	assert( copiedDegenerateTree_2 );
	assert( copiedBalancedTree_2 );
	copiedBalancedTree = copiedBalancedTree_2;
	copiedDegenerateTree = copiedDegenerateTree_2;
	copiedBalancedTree_2 = CopyFrom( copiedBalancedTree );					// Создаём 6-ю копию идеально сбалансированного дерева, которая нам понадобится в дальнейшем.
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

	cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl	// Вывод адреса корня дерева.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// Вывод адреса корня дерева.
	FreeMem( copiedDegenerateTree );												// Удаление дерева и освобождение, выделенной под него памяти.
	FreeMem( copiedBalancedTree );													// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of copiedDegenerateTree:  " << copiedDegenerateTree << endl	// Вывод адреса корня дерева после удаления дерева.
		<< "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// Вывод адреса корня дерева после удаления дерева.

	cout << endl << "============================================================================" << endl;
	cout << "Демонстрация работы функции CheckParentalLinks( NodeOfTree* ):" << endl;
	assert( copiedBalancedTree_2 );
	copiedBalancedTree = copiedBalancedTree_2;
	assert( !CheckParentalLinks( copiedBalancedTree ) ); // В начале все родительские связи в дереве не нарушены.
	
	// Внесём намерено нарушение родительских свзей между двумя узлами:
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
	a->parentNode = copiedBalancedTree;		// Листовой узел с ключом 6 после этого оператора указывает на корень дерева, что нарушает его родительскую связь с его настоящим предком!
	*/
	//copiedBalancedTree->leftNode->parentNode = copiedBalancedTree->rightNode;
	copiedBalancedTree->rightNode->parentNode = copiedBalancedTree->rightNode;	// Поле parentNode после этого оператора указывает на свой же узел, что нарушает его родительскую связь с корнем дерева!

	cout << endl;
	cout << "===Dump2( copiedBalancedTree )===" << endl;
    Dump2( copiedBalancedTree );
	cout << endl;

	CheckParentalLinks( copiedBalancedTree );

	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// Вывод адреса корня дерева.
	FreeMem( copiedBalancedTree );													// Удаление дерева и освобождение, выделенной под него памяти.
	cout << "Address of copiedBalancedTree:  " << copiedBalancedTree << endl;		// Вывод адреса корня дерева после удаления дерева.

	cout << endl << "============================================================================" << endl;
	cout << endl << endl;
	char tempStr[2];
	cout << "Press any key and [Enter] to quite . . . ";
	cin >> tempStr;

	return 0;
}
// ���������� �������� ��������.
// ����������� ���� ���������� �������� �������� �������� ��, ��� � ������ ���� ������ ����������� ��������� �� ��� ������������ ����.

#include "BinaryTrees.h"

#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <assert.h>
using namespace std;

// ����� ������ ����������� ������������ ������. ��� ���� ������������ �������������� �����.
void TreePrint( NodeOfTree *tree )
{
	assert( tree );
	queue<NodeOfTree*> q;
	NodeOfTree* currentNode = tree;
	do{
		cout << currentNode->key << ", ";	// ���������� ������� ����.
		if( currentNode->leftNode ) q.push( currentNode->leftNode );
		if( currentNode->rightNode ) q.push( currentNode->rightNode );
		if( !currentNode->leftNode && !currentNode->rightNode ) currentNode = nullptr;
		if( !q.empty() )
		{
			currentNode = q.front();		// ��������� �� ������� ��������� ����;
			q.pop();						// ������� �� ������� ����������� ����;
		}
	}while( !q.empty() || currentNode );
}

// ����� ������ ����������� ������������ ������. ��� ���� ������������ ������������ ������ �����.
void TreePrint_2( NodeOfTree *tree )
{
	assert( tree );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = tree;
	while( currentNode != nullptr || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// ��������� �� ����� ������� ����;
			s.pop();							// ������� �� ����� ����������� ����;
		}
		while( currentNode )
		{
			cout << currentNode->key << ", ";	// ���������� ������� ����.
			if( currentNode->rightNode ) s.push( currentNode->rightNode );
			currentNode = currentNode->leftNode;
		}
	}
}

// ����� ������ ����������� ������������ ������. ��� ���� ������������ ������������ �������� �����.
void TreePrint_3( NodeOfTree *tree )
{
	assert( tree );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = tree;
	while( currentNode || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// ��������� �� ����� ������� ����;
			s.pop();							// ������� �� ����� ����������� ����;
			cout << currentNode->key << ", ";	// ���������� ������� ����.
			if( currentNode->rightNode ) currentNode = currentNode->rightNode;
			else currentNode = nullptr;
		}
		while( currentNode )
		{
			s.push( currentNode );
			currentNode = currentNode->leftNode;
		}
	}
}

// ����� ������ ����������� ����������� ������ � ���������� �����.
void TreePrint_4( NodeOfTree *tree )
{
	if ( tree != NULL )
	{	//���� �� ���������� ������ ����
		cout << tree->key << ", ";			// ���������� ��������� ����.
		TreePrint_4( tree->leftNode );		// ����������� ����� ������� ��� ������ ���������.
		TreePrint_4( tree->rightNode );		// ����������� ����� ������� ��� ������� ���������.
	}
}

// ����� ������ ����������� ����������� ������ � ��������� �����.
void TreePrint_5( NodeOfTree *tree )
{
	if ( tree != NULL )
	{	//���� �� ���������� ������ ����
		TreePrint_5( tree->leftNode );		// ����������� ����� ������� ��� ������ ���������.
		cout << tree->key << ", ";			// ���������� ��������� ����.
		TreePrint_5( tree->rightNode );		// ����������� ����� ������� ��� ������� ���������.
	}
}

// ����� ������ ����������� ����������� ������ � ����������� �����.
void TreePrint_6( NodeOfTree *tree )
{
	if ( tree != NULL )
	{	//���� �� ���������� ������ ����
		TreePrint_6( tree->leftNode );		// ����������� ����� ������� ��� ������ ���������.
		TreePrint_6( tree->rightNode );		// ����������� ����� ������� ��� ������� ���������.
		cout << tree->key << ", ";			// ���������� ��������� ����.
	}
}

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ������������ ������. ��� ���� ������������ �������������� �����.
NodeOfTree* FindKey( NodeOfTree* root, int key )
{
	assert( root );
	queue<NodeOfTree*> q;
	NodeOfTree *currentNode = root;
	do{
		if( currentNode->key == key ) return currentNode;
		if( currentNode->leftNode ) q.push( currentNode->leftNode );
		if( currentNode->rightNode ) q.push( currentNode->rightNode );
		if( !currentNode->leftNode && !currentNode->rightNode ) currentNode = nullptr;
		if( !q.empty() )
		{
			currentNode = q.front();		// ��������� �� ������� ��������� ����;
			q.pop();						// ������� �� ������� ����������� ����;
		}
	}while( !q.empty() || currentNode );
	return nullptr;
}

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ������������ ������. ��� ���� ������������ ������������ ������ �����.
NodeOfTree* FindKey_2( NodeOfTree* root, int key )
{
	assert( root );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = root;
	while( currentNode != nullptr || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// ��������� �� ����� ������� ����;
			s.pop();							// ������� �� ����� ����������� ����;
		}
		while( currentNode )
		{
			if( currentNode->key == key ) return currentNode;
			if( currentNode->rightNode ) s.push( currentNode->rightNode );
			currentNode = currentNode->leftNode;
		}
	}
	return nullptr;
}

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ������������ ������. ��� ���� ������������ ������������ �������� �����.
NodeOfTree* FindKey_3( NodeOfTree* root, int key )
{
	assert( root );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = root;
	while( currentNode || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// ��������� �� ����� ������� ����;
			s.pop();							// ������� �� ����� ����������� ����;
			if( currentNode->key == key ) return currentNode;
			if( currentNode->rightNode ) currentNode = currentNode->rightNode;
			else currentNode = nullptr;
		}
		while( currentNode )
		{
			s.push( currentNode );
			currentNode = currentNode->leftNode;
		}
	}
	return nullptr;
}

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ����������� ����� ������.
NodeOfTree* FindKey_4( NodeOfTree* root, int key )
{
	NodeOfTree* res;
	if ( root == nullptr )
		return nullptr;
	if ( root->key == key )
		return root;
	else
	{
		res = FindKey_4( root->leftNode, key );			// ����������� ����� ������� ��� ������ ���������.
		if( res != nullptr ) return res;
		return FindKey_4( root->rightNode, key );		// ����������� ����� ������� ��� ������� ���������.
	}
}

// ���������� ��������� �� ���� ������ ��������� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
NodeOfTree* FindKeyInBinarySearchTree( NodeOfTree* root, int key )
{
	if( root == nullptr ) return nullptr;
	// ����� �������������, ��� root != nullptr;
	if( root->key == key ) return root;
	if( key < root->key ) return FindKeyInBinarySearchTree( root->leftNode, key );
	return FindKeyInBinarySearchTree( root->rightNode, key );
}

// ���������� ��������� �� ������ ������.
NodeOfTree* RootOfTree( NodeOfTree* anyNodeOfTree )
{
	assert( anyNodeOfTree );	// assert( anyNodeOfTree != nullptr );
	NodeOfTree *res = anyNodeOfTree;
	while( res->parentNode != nullptr ) res = res->parentNode;
	return res;
}

// �������� � �������� ���� ���� �����. � �������� ������������ ���� ����� ���� ����� ������. � ������ ������������� � ���� currentNode ������� ����� ������ ��������� �������� ���������������.
void AddNodeInLeft( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded )
{
	assert( currentNode );						// assert( currentNode != nullptr );
	assert( nodeToBeAdded );					// assert( nodeToBeAdded != nullptr );
	assert( !currentNode->leftNode );			// assert( currentNode->leftNode == nullptr );
	currentNode->leftNode = nodeToBeAdded;
	nodeToBeAdded->parentNode = currentNode;
}

// �������� � �������� ���� ���� ������. � �������� ������������ ���� ����� ���� ����� ������. � ������ ������������� � ���� currentNode ������� ������ ������ ��������� �������� ���������������.
void AddNodeInRight( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded )
{
	assert( currentNode );						// assert( currentNode != nullptr );
	assert( nodeToBeAdded );					// assert( nodeToBeAdded != nullptr );
	assert( !currentNode->rightNode );			// assert( currentNode->rightNode == nullptr );
	currentNode->rightNode = nodeToBeAdded;
	nodeToBeAdded->parentNode = currentNode;
}

// �������� ������� ���� ��������� �����. ������� ���� ����� ���� ����� ����� ������ � ��� ����� � ��� ������, � ��������� ���� �� ������ ����� �� ������������� ����, �� ����� ��������.
void ReplaceSingleNode( NodeOfTree* &currentNode, NodeOfTree* singleNode )
{
	assert( currentNode );						// assert( currentNode != nullptr );
	assert( singleNode );						// assert( singleNode != nullptr );
	assert( !singleNode->parentNode );			// assert( singleNode->parentNode == nullptr );
	assert( !singleNode->leftNode );			// assert( singleNode->leftNode == nullptr );
	assert( !singleNode->rightNode );			// assert( singleNode->rightNode == nullptr );
	singleNode->leftNode = currentNode->leftNode;
	singleNode->rightNode = currentNode->rightNode;
	if( singleNode->leftNode )					// if( singleNode->leftNode != nullptr )
		singleNode->leftNode->parentNode = singleNode;
	if( singleNode->rightNode )					// if( singleNode->rightNode != nullptr )
		singleNode->rightNode->parentNode = singleNode;
	if( currentNode->parentNode )				// if( currentNode->parentNode != nullptr )
	{
		NodeOfTree *parentNode;
		parentNode = currentNode->parentNode;
		if( parentNode->leftNode == currentNode )
			parentNode->leftNode = singleNode;		// ���� �������� ���������� ���������: currentNode = singleNode;
		else // if( parentNode->rightNode == currentNode )
			parentNode->rightNode = singleNode;		// ���� �������� ���������� ���������: currentNode = singleNode;
		singleNode->parentNode = parentNode;
	}
	else // if( currentNode->parentNode == nullptr )
		currentNode = singleNode;
}

// �������� ��������� ���� ������������ �����. � ��������� � ������������ ���� ����� ���� ������ ��������� ��� ������������.
void ReplaceNodeInsteadNode( NodeOfTree* &nodeToBeDeleted, NodeOfTree* replacementNode )
{
	assert( nodeToBeDeleted );
	assert( replacementNode );
	if( nodeToBeDeleted->leftNode )
		DeleteNode( nodeToBeDeleted->leftNode );
	if( nodeToBeDeleted->rightNode )
		DeleteNode( nodeToBeDeleted->rightNode );
	if( nodeToBeDeleted->parentNode ) // if( nodeToBeDeleted->parentNode != nullptr )
	{
		// ��������� ������������ ��������� �� ��� �������� ������������� ����:
		if( replacementNode->parentNode->leftNode == replacementNode )
			replacementNode->parentNode->leftNode = nullptr;
		else // if( replacementNode->parentNode->rightNode == replacementNode )
			replacementNode->parentNode->rightNode = nullptr;

		// ���������� ������������ ��������� � ��� ������ ������������� ����:
		NodeOfTree* parentNode = nodeToBeDeleted->parentNode;
		if( parentNode->leftNode == nodeToBeDeleted )
			parentNode->leftNode = replacementNode;
		else // if( parentNode->rightNode == nodeToBeDeleted )
			parentNode->rightNode = replacementNode;
		replacementNode->parentNode = parentNode;
	}
	else // if( nodeToBeDeleted->parentNode == nullptr )
		nodeToBeDeleted = replacementNode;
}

int Height( NodeOfTree* p )
{ 
	return int( p? p->height: 0 );
}

int BalanceFactor( NodeOfTree* p )
{
	if( p )
		return Height( p->rightNode ) - Height( p->leftNode );
	else
		return 0;
}

// ���������� ����� � ������ ��������� ������.
struct NodeOfTree* AddNode( int k, NodeOfTree* tree )
{
	if ( tree == NULL )
	{	// ���� ������ ���, �� ��������� ������ ��� ����� ����.
		tree = new NodeOfTree;		// �������� ������ ��� ����.
		tree->key = k;				// �������������� ���� ������.
		/*
		assert( tree->height == 1 );
		assert( tree->parentNode == nullptr );
		assert( tree->leftNode ==  NULL );
		assert( tree->rightNode == NULL );		// ����� ������ ���� ������������������� ��������� NULL ��� nullptr, ��� ���� �����.
		*/
	}
	else if ( k < tree->key )		// ������� ���������� ������ �������
	{
		tree->leftNode = AddNode( k, tree->leftNode );
		tree->leftNode->parentNode = tree;
	}
	else							// ������� ���������� ������� �������
	{
		tree->rightNode = AddNode( k, tree->rightNode );
		tree->rightNode->parentNode = tree;
	}
	// �������� ������ ����-������
	CalculatingHeight( tree );
	return( tree );
}

// ���������� ����� � ������ ��������� ������.
void AddNode_2( int k, NodeOfTree*& tree )
{
	if ( tree == NULL )
	{	// ���� ������ ���, �� ��������� ������ ��� ����� ����.
		tree = new NodeOfTree;		// �������� ������ ��� ����.
		tree->key = k;				// �������������� ���� ������.
		/*
		assert( tree->height == 1 );
		tree->parentNode = NULL;
		tree->leftNode = nullptr;
		tree->rightNode = nullptr;	// ����� �������������� ��������� NULL ��� nullptr, ��� ���� �����.
		*/
	}
	else if ( k < tree->key )		// ������� ���������� ������ �������
	{
		AddNode_2( k, tree->leftNode );
		tree->leftNode->parentNode = tree;
	}
	else							// ������� ���������� ������� �������
	{
		AddNode_2( k, tree->rightNode );
		tree->rightNode->parentNode = tree;
	}
	// �������� ������ ����-������:
	CalculatingHeight( tree );
}

// ����������� ����������� ����� ��������� ������ source.
void Copy( NodeOfTree* source, NodeOfTree* node )
{
	// ��������� source �� ������ ��������� �� ������ ������.
	assert( source ); 	//	assert( source != nullptr );	// ��������� ��������� ������ ��������� � ������, ���� source ��������� �� nullptr!
	node->key = source->key;
	// ���������� ����������� ����� ����� ������ source:
	if ( source->leftNode )			//	if ( source->leftNode != nullptr )
	{
		node->leftNode = new NodeOfTree;
		node->leftNode->parentNode = node;
		Copy( source->leftNode, node->leftNode );
	}
	if ( source->rightNode )		//	if ( source->rightNode != nullptr )
	{
		node->rightNode = new NodeOfTree;
		node->rightNode->parentNode = node;
		Copy( source->rightNode, node->rightNode );
	}
}

// ����������� ����� ��������� ������ ��� ��� ���������.
NodeOfTree* CopyFrom( NodeOfTree* source )
{
	assert( source );	//	assert( source != nullptr );
	NodeOfTree* res;
	res = new NodeOfTree( source->key );
	// �������� ����������� ����� ����� ������ source:
	if ( source->leftNode )			//	if ( source->leftNode != nullptr )
	{
		res->leftNode = new NodeOfTree;
		res->leftNode->parentNode = res;
		Copy( source->leftNode, res->leftNode );
	}
	if ( source->rightNode )		//	if ( source->rightNode != nullptr )
	{
		res->rightNode = new NodeOfTree;
		res->rightNode->parentNode = res;
		Copy( source->rightNode, res->rightNode );
	}
	return res;
}

// ������ ������� ������ p, ��. https://habr.com/ru/articles/150732/
NodeOfTree* RotateRight( NodeOfTree* p )
{
	if ( p->leftNode == nullptr ) return p;
	bool itIsRoot = false, itIsLeftNode;
	NodeOfTree* parentNode = p->parentNode;
	if ( parentNode != nullptr )
	{
		if ( parentNode->leftNode == p ) itIsLeftNode = true;
		else itIsLeftNode = false;
	}
	else itIsRoot = true;
	NodeOfTree* q = p->leftNode;													/*	    p->		7		1			*/
	p->leftNode = q->rightNode;														/*			   /	   /			*/
	if ( p->leftNode ) p->leftNode->parentNode = p;									/*		q->   8		  2				*/
	q->parentNode = p->parentNode;													/*					 /				*/
	p->parentNode = q;																/*					3				*/
	q->rightNode = p;
	if ( !itIsRoot && itIsLeftNode ) parentNode->leftNode = q;
	else if ( !itIsRoot && !itIsLeftNode ) parentNode->rightNode = q;
	CalculatingHeight( q );		// �������� ������ ������������� ����.
	return q;
}

// ����� ������� ������ q, c�. https://habr.com/ru/articles/150732/
NodeOfTree* RotateLeft( NodeOfTree* q )
{	
	if ( q->rightNode == nullptr ) return q;
	bool itIsRoot = false, itIsLeftNode;
	NodeOfTree* parentNode = q->parentNode;
	if ( parentNode != nullptr )
	{
		if ( parentNode->leftNode == q ) itIsLeftNode = true;
		else itIsLeftNode = false;
	}
	else itIsRoot = true;
	NodeOfTree* p = q->rightNode;													/*	    	7		1		<-q		*/
	q->rightNode = p->leftNode;														/*		     \		 \				*/
	if ( q->rightNode ) q->rightNode->parentNode = q;								/*		      8		  2		<-p		*/
	p->parentNode = q->parentNode;													/*					   \			*/
	q->parentNode = p;																/*					    3			*/
	p->leftNode = q;
	if ( !itIsRoot && itIsLeftNode ) parentNode->leftNode = p;
	else if ( !itIsRoot && !itIsLeftNode ) parentNode->rightNode = p;
	CalculatingHeight( p );		// �������� ������ ������������� ����.
	return p;
}

// ������������ ���� p � ��� ������ ��������� ������.
NodeOfTree* BalanceNodeInAVL_BinarySearchTree( NodeOfTree* p )
{
	CalculatingHeight( p );
	if( BalanceFactor( p ) == 2 )
	{
		if( BalanceFactor( p->rightNode ) < 0 )
			//p->rightNode = RotateRight( p->rightNode );
			RotateRight( p->rightNode );
		return RotateLeft( p );
	}
	else if( BalanceFactor( p ) == -2 )
	{
		if( BalanceFactor( p->leftNode ) > 0  )
			//p->leftNode = RotateLeft( p->leftNode );
			RotateLeft( p->leftNode );
		return RotateRight( p );
	}
	return p; // ������������ �� �����
}

// ����� ���� � ����������� ������ � ������ ��������� ������ p.
NodeOfTree* FindMinInBinarySearchTree( NodeOfTree* p )
{
	return p->leftNode? FindMinInBinarySearchTree( p->leftNode ): p;
}

// �������� ���� � ����������� ������ �� ������ ��������� ������ p � ��� ������������.
NodeOfTree* DeleteMinInAVL_BinarySearchTree( NodeOfTree* p )
{
	if( p->leftNode == nullptr )
	{
		if( p->rightNode )
			p->rightNode->parentNode = p->parentNode; // ��� ����� ��������� ������ ��������� ������ - ��������� ������������ ������!
		return p->rightNode;
	}
	p->leftNode = DeleteMinInAVL_BinarySearchTree( p->leftNode );
	return BalanceNodeInAVL_BinarySearchTree( p );
}

// �������� ���� � ������ k �� ��� ������ ��������� ������ p � ��� ������������.
NodeOfTree* DeleteNodeFromAVL_BinarySearchTree( NodeOfTree* p, int k )
{
	if( !p ) return nullptr;	//	if( p == nullptr )
	if( k < p->key )
	{
		p->leftNode = DeleteNodeFromAVL_BinarySearchTree( p->leftNode, k );
		if( p->leftNode != nullptr )
			p->leftNode->parentNode = p;
	}
	else if( k > p->key )
	{
		p->rightNode = DeleteNodeFromAVL_BinarySearchTree( p->rightNode, k );
		if( p->rightNode != nullptr )
			p->rightNode->parentNode = p;
	}
	else	//  if( k == p->key )
	{
		bool deletedNodeWasTheRoot;
		if( p->parentNode == nullptr ) // ���� ��������� ���� �������� ������ ������.
			deletedNodeWasTheRoot = true;
		else
			deletedNodeWasTheRoot = false;

		NodeOfTree* q = p->leftNode;
		NodeOfTree* r = p->rightNode;
		delete p;
		if( !r )	//	if( r == nullptr )
		{
			if( deletedNodeWasTheRoot )
				q->parentNode = nullptr;
			return q;
		}
		NodeOfTree* min = FindMinInBinarySearchTree( r );
		min->rightNode = DeleteMinInAVL_BinarySearchTree( r );
		min->rightNode->parentNode = min;
		min->leftNode = q;
		q->parentNode = min;
		NodeOfTree* res;
		res = BalanceNodeInAVL_BinarySearchTree( min );
		if( deletedNodeWasTheRoot )
			res->parentNode = nullptr;
		return res;
	}
//	CalculatingHeight( p );		// �������� ������ ������������� ����.
	return BalanceNodeInAVL_BinarySearchTree( p );
}

// ������� ����� k � ��� ������ ��������� ������ � ������ p � ��� ������������.
NodeOfTree* InsertNodeToAVL_BinarySearchTree( NodeOfTree* p, int k )
{
	if( !p )	// if ( p == nullptr )
		return new NodeOfTree( k );
	// ����� �������������, ��� p != nullptr
	if( k < p->key )
	{
		p->leftNode = InsertNodeToAVL_BinarySearchTree( p->leftNode, k );
		p->leftNode->parentNode = p;
	}
	else
	{
		p->rightNode = InsertNodeToAVL_BinarySearchTree( p->rightNode, k );
		p->rightNode->parentNode = p;

	}
//	CalculatingHeight( p );
	return BalanceNodeInAVL_BinarySearchTree( p );
}

// ���������� ��� ������ ��������� ������ �� �������.
NodeOfTree* BuildAVL_BinarySearchTreeFrom( int *arr, int size )
{
	NodeOfTree *res = nullptr;
	for( int i = 0; i < size; i++ )
		res = InsertNodeToAVL_BinarySearchTree( res, arr[i] );
	return res;
}

// ���������� ��� ������ ��������� ������ �� ��������� ������.
NodeOfTree* BuildAVL_BinarySearchTreeFrom(  NodeOfTree* source, NodeOfTree* res )
{
	if ( source ) // if ( source != nulptr )
	{
		res = InsertNodeToAVL_BinarySearchTree( res, source->key );
		// ���������� ����������� ����� ����� ������ source:
		res = BuildAVL_BinarySearchTreeFrom( source->leftNode, res );
		res = BuildAVL_BinarySearchTreeFrom( source->rightNode, res );
	}
	return res;
}

// ���������� ��� ������ ��������� ������ �� ��������� ������.
NodeOfTree* BuildAVL_BinarySearchTreeFrom( NodeOfTree* source )
{
	NodeOfTree *res = nullptr;
	if ( source )
	{
		res = InsertNodeToAVL_BinarySearchTree( res, source->key );
		// �������� ����������� ����� ������ � ������� ����������� ������ source:
		res = BuildAVL_BinarySearchTreeFrom( source->leftNode, res );
		res = BuildAVL_BinarySearchTreeFrom( source->rightNode, res );
	}
	return res;
}

// �������� ��������� ��� ����� ������ �������. ������������ ������ ����������� ������.
NodeOfTree* DeleteNode( NodeOfTree*& node )
{
	NodeOfTree *res = node;
	if( node->parentNode != nullptr )
	{
		if( node->parentNode->leftNode == node )
			node->parentNode->leftNode = nullptr;
		else
			node->parentNode->rightNode = nullptr;
		while( res->parentNode != nullptr ) res = res->parentNode;	// ����������� �� ����� ������.
	}
	if( res == node ) res = nullptr;	// �.�. � ������, ����� ��������� ���� ���������� ������������ �� ������.
	FreeMem( node );					// � � ������ �������� ����� ������ � � ������ �������� ���������.
	return res;
}

// ������������ ������, ������� ���� ������� ������� ��� ���������� ������.
void FreeMem( NodeOfTree*& tree )
{
	if( tree != NULL )
	{// ����� ������ � ����������� �����:
		FreeMem( tree->leftNode );
		FreeMem( tree->rightNode );
		delete tree;
	}
	tree = NULL;
}

int NumOfNodes( NodeOfTree* tree )
{
	if ( tree == nullptr ) return 0;
	return NumOfNodes( tree->leftNode ) + 1 + NumOfNodes( tree->rightNode );
}

// ����� ������ � ����������� ��� ������ � ����� ���� ��� �����������:
void CalculatingHeight( NodeOfTree* node, int &height )
{
	if ( node != nullptr )
	{		// ���� �� ���������� ������ ����:
		int heightLeft, heightRight, currentHeight;
		heightLeft = heightRight = 1;
		CalculatingHeight( node->leftNode, heightLeft );		// ����������� ����� ������� ��� ������ ���������.
		CalculatingHeight( node->rightNode, heightRight );		// ����������� ����� ������� ��� ������� ���������.
		currentHeight = max( heightLeft, heightRight );
		node->height = currentHeight;
		height += currentHeight;
	}
}

// ����������� ������ ��������� ������ � ���� ��� �����������.
int CalculatingHeight( NodeOfTree* tree )
{
	int height, heightLeft, heightRight;
	if ( tree == nullptr ) return 0;
	heightLeft = heightRight = 1;
	CalculatingHeight( tree->leftNode, heightLeft );
	CalculatingHeight( tree->rightNode, heightRight );
	height = max( heightLeft, heightRight );
	tree->height = height;
	return height;
}

// �������� �� �������� ������ ������� ��������� ������.
bool IsItBinarySearchTree( NodeOfTree* p, int minKey, int maxKey )
{
	if ( p == nullptr )
		return true;
	if ( minKey < p->key && p->key < maxKey )
		return IsItBinarySearchTree( p->leftNode, minKey, p->key ) && IsItBinarySearchTree( p->rightNode, p->key, maxKey );
	return false;
}

// �������� �� �������� ������ ������� ��������� ������.
bool IsItBinarySearchTree( NodeOfTree* p )
{
	return IsItBinarySearchTree( p, minInt, maxInt );
}

// �������� �� �������� ������ ��� �������.
bool IsItAVL_Tree( NodeOfTree* tree )
{
	bool res = true;
	int heightLeft, heightRight;
	// ���������� ������ �������� ������ � ���� ��� �����������:
	CalculatingHeight ( tree ); // ��������, ��� ����� ���� ������� �������� ���������� � ������ ���� ���������������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	if ( tree != nullptr && res )
	{	// ���� �� ���������� ������ ���� ��� ���� ������ ������� ����� ������ � ������� ����������� �� �������� ������ 1:
		heightLeft = Height( tree->leftNode );
		heightRight = Height( tree->rightNode );
		if( abs( heightLeft - heightRight ) > 1 ) return false;
		res = IsItAVL_Tree( tree->leftNode );		// ����������� ����� ������� ��� ������ ���������.
		if( res )
			res = IsItAVL_Tree( tree->rightNode );	// ����������� ����� ������� ��� ������� ���������.
		else
			return false;
	}
	else	// ���������� ������ ����:
		return res;

	return res;
}

// �������� �� �������� ������ �������� ����������������.
bool IsItIdealBalancedTree( NodeOfTree* tree )
{
	bool res = true;
	if ( tree == nullptr ) return true;
	int numOfLeftNodes, numOfRightNodes;
	if ( tree != nullptr && res )
	{	// ���� �� ���������� ������ ���� ��� ���� ������ ������� ��������� ����� � ����� � ������ ����������� �� �������� ������ 1:
		numOfLeftNodes = NumOfNodes( tree->leftNode );
		numOfRightNodes = NumOfNodes( tree->rightNode );
		if( abs( numOfLeftNodes - numOfRightNodes ) > 1 ) return false;
		res = IsItIdealBalancedTree( tree->leftNode );		// ����������� ����� ������� ��� ������ ���������.
		if( res )
			res = IsItIdealBalancedTree( tree->rightNode );	// ����������� ����� ������� ��� ������� ���������.
		else
			return false;
	}
	else	// ���������� ������ ����:
		return res;

	return res;
}

// ���������� �������� ����������������� ��������� ������ �� �������.
NodeOfTree* BuildIdealBalancedTreeFrom( int *arr, int size, int &index )
{
	if ( size == 0 ) return NULL;
	NodeOfTree* res;
	int nl, nr;
	nl = size / 2;
	nr = size - nl - 1;
	res = new NodeOfTree( arr[index] );
//	res->key = arr[index];
	index++;
	res->leftNode = BuildIdealBalancedTreeFrom( arr, nl, index );
	res->rightNode = BuildIdealBalancedTreeFrom( arr, nr, index );
	if( nl > 0 ) res->leftNode->parentNode = res;
	if( nr > 0 ) res->rightNode->parentNode = res;
	return res;
}

// ���������� �������� ����������������� ��������� ������ �� �������.
NodeOfTree* BuildIdealBalancedTreeFrom( int *arr, int size )
{
	int index = 0;
	return BuildIdealBalancedTreeFrom( arr, size, index );
}

// ���������� �������� ����������������� ������ �� ��������� ������.
NodeOfTree* BuildIdealBalancedTreeFrom( queue<NodeOfTree*> &q, int numOfNodes )
{
	if ( numOfNodes == 0 ) return nullptr;
	assert( !q.empty() );		// ��������� ��������� ������ ���������, ���� ������� q �����!

	NodeOfTree *currentNode = q.front();	// ��������� �� ������� ��������� ����;
	q.pop();								// ������� �� ������� ����������� ����;

	NodeOfTree *res = new NodeOfTree( currentNode->key );
	int nl, nr;
	nl = numOfNodes / 2;
	nr = numOfNodes - nl - 1;
	// ����������� ����� ������:
	if( currentNode->leftNode != nullptr )
		q.push( currentNode->leftNode );
	if( currentNode->rightNode != nullptr )
		q.push( currentNode->rightNode );

	res->leftNode = BuildIdealBalancedTreeFrom( q, nl );
	res->rightNode = BuildIdealBalancedTreeFrom( q, nr );
	if( nl > 0 ) res->leftNode->parentNode = res;
	if( nr > 0 ) res->rightNode->parentNode = res;
	return res;
}

// ���������� �������� ����������������� ������ �� ��������� ������.
NodeOfTree* BuildIdealBalancedTreeFrom( NodeOfTree* source )
{
	if ( !source )  // if ( source == nullptr )
		return nullptr;
	// ����� �������������, ��� source != nullptr
//	assert( source->parentNode == nullptr );		// ��������� ��������� ������ ���������, ���� ��������� source ��������� �� �� ������ ������!
	int numOfNodes = NumOfNodes( source );
	queue<NodeOfTree*> q;
	q.push( source );
	return BuildIdealBalancedTreeFrom( q, numOfNodes );
}

// ����� �����������.
void SwapTrees( NodeOfTree* &a, NodeOfTree* &b )
{
	assert( a );
	assert( b );
	NodeOfTree *oldParent_a, *oldParent_b, *temp, *tempCopyOf_a, *tempCopyOf_b;
	oldParent_a = a->parentNode;
	oldParent_b = b->parentNode;
	if( oldParent_a == nullptr && oldParent_b == nullptr )	//	if( a � b �������� ������� ����� �������� )
	{
		temp = a;
		a = b;
		b = temp;
	}
	else if( oldParent_a == nullptr && oldParent_b != nullptr )
	{
//		temp = CopyFrom( b );	// ��� ����� ������������� �������� � ����� ������������� ������, �.�. ���������� ����������� ����� ��������� 'b'. ������� ����� �������� ���������� ���� ��������.
		// ��� ����� ������ ��������� ����� ������ ������ ���� - ��������� ���� ��������� 'b'.
		tempCopyOf_b = new NodeOfTree( b->key );
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		/*
		if( oldParent_b->leftNode == b )
			oldParent_b->leftNode = a;	//	���� �����, ��� � ��������: b = a;
		else // if( oldParent_b->rightNode == b )
			oldParent_b->rightNode = a;	//	���� �����, ��� � ��������: b = a;
		*/
		b = a;	// ������ ��������� b � a ��������� �� ���� � �� �� ������� ������, �� ������� ���������� �������� a.
		b->parentNode = oldParent_b;

//		a = temp;
		a = tempCopyOf_b;
		a->parentNode = oldParent_a;
		if( a->leftNode )
			a->leftNode->parentNode = a;
		if( a->rightNode )
			a->rightNode->parentNode = a;
	}
	else if( oldParent_a != nullptr && oldParent_b == nullptr )
	{
//		temp = CopyFrom( a );	// ��� ����� ������������� �������� � ����� ������������� ������, �.�. ���������� ����������� ����� ��������� 'a'. ������� ����� �������� ���������� ���� ��������.
		// ��� ����� ������ ��������� ����� ������ ������ ���� - ��������� ���� ��������� 'a'.
		tempCopyOf_a = new NodeOfTree( a->key );
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		/*
		if( oldParent_a->leftNode == a )
			oldParent_a->leftNode = b;	//	���� �����, ��� � ��������: a = b;
		else // if( oldParent_a->rightNode == a )
			oldParent_a->rightNode = b;	//	���� �����, ��� � ��������: a = b;
		*/
		a = b;	// ������ ��������� a � b ��������� �� ���� � �� �� ������� ������, �� ������� ���������� �������� b.
		a->parentNode = oldParent_a;

//		b = temp;
		b = tempCopyOf_a;
		b->parentNode = oldParent_b;
		if( b->leftNode )
			b->leftNode->parentNode = b;
		if( b->rightNode )
			b->rightNode->parentNode = b;
	}
	else if( oldParent_a == oldParent_b )	// if( oldParent_a == oldParent_b && oldParent_a != nullptr )
	{
		temp = oldParent_a->leftNode;
		oldParent_a->leftNode = oldParent_a->rightNode;
		oldParent_a->rightNode = temp;
	}
	else // if( oldParent_a != nullptr && oldParent_b != nullptr && oldParent_a != oldParent_b )
	{
//		temp = CopyFrom( a );	// ��� ����� ������������� �������� � ����� ������������� ������, �.�. ���������� ����������� ����� ��������� 'a'. ������� ����� �������� ���������� ���� ��������.
		// ��� ����� ������ ��������� ����� ������ ������ ���� - ��������� ���� ��������� 'a'.
		tempCopyOf_a = new NodeOfTree( a->key );
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		/*
		if( oldParent_a->leftNode == a )
			oldParent_a->leftNode = b;	//	���� �����, ��� � ��������: a = b;
		else // if( oldParent_a->rightNode == a )
			oldParent_a->rightNode = b;	//	���� �����, ��� � ��������: a = b;
		*/
		a = b;	// ������ ��������� a � b ��������� �� ���� � �� �� ������� ������, �� ������� ���������� �������� b.
		a->parentNode = oldParent_a;

		if( oldParent_b->leftNode == b )
			oldParent_b->leftNode = tempCopyOf_a;
		else // if( oldParent_b->rightNode == b )
			oldParent_b->rightNode = tempCopyOf_a;

		b = tempCopyOf_a;
		b->parentNode = oldParent_b;
		if( b->leftNode )
			b->leftNode->parentNode = b;
		if( b->rightNode )
			b->rightNode->parentNode = b;
	}
}

// ����� ����� �� ����� ������ ��� �� ������ ��������.
void Swap( NodeOfTree* &a, NodeOfTree* &b )
{
	assert( a );
	assert( b );
	NodeOfTree *oldParent_a, *oldParent_b, *tempCopyOf_a, *tempCopyOf_b, *temp;
	oldParent_a = a->parentNode;
	oldParent_b = b->parentNode;
	if( oldParent_a == nullptr && oldParent_b == nullptr )	//	if( a � b �������� ������� ����� �������� )
	{
		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;
		tempCopyOf_b = new NodeOfTree;
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		temp = a;
		a = b;	// ������ ��������� a � b ��������� �� ���� � �� �� ������� ������, �� ������� ���������� �������� b.
		a->leftNode = tempCopyOf_a->leftNode;
		a->rightNode = tempCopyOf_a->rightNode;
		if( a->leftNode )
			a->leftNode->parentNode = a;
		if( a->rightNode )
			a->rightNode->parentNode = a;

		b = temp;
		b->leftNode = tempCopyOf_b->leftNode;
		b->rightNode = tempCopyOf_b->rightNode;
		if( b->leftNode )
			b->leftNode->parentNode = b;
		if( b->rightNode )
			b->rightNode->parentNode = b;

		delete tempCopyOf_a;
		delete tempCopyOf_b;
	}
	else if( oldParent_b == a )			// ������ ������ ������, ����� �������������� ���� ������� ������������� �����������!
	{
		bool b_wasTheLeftChild;

		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;
		tempCopyOf_b = new NodeOfTree;
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		a->parentNode = b;
		a->leftNode = b->leftNode;
		a->rightNode = b->rightNode;

		if( tempCopyOf_a->leftNode == b )			// if( b ������� ����� �������� ������ ������������� ����, ������� ������� ���� a )
		{
//			oldParent_b->leftNode = a;
			b->leftNode = a;
			b->rightNode = tempCopyOf_a->rightNode;
			b_wasTheLeftChild = true;
		}
		else										// if( b ������� ������ �������� ������ ������������� ����, ������� ������� ���� a )
		{
//			oldParent_b->rightNode = a;					// ��������: ���� oldParent_b = a, �� � ���������� ���������� ����� ��������� ���������� ����������� �����!!!
			b->rightNode = a;
			b->leftNode = tempCopyOf_a->leftNode;
			b_wasTheLeftChild = false;
		}
		if( tempCopyOf_b->leftNode )
			tempCopyOf_b->leftNode->parentNode = a;
		if( tempCopyOf_b->rightNode )
			tempCopyOf_b->rightNode->parentNode = a;
		
		// ���� a "�����������" �� ����� ���� b. ������ ���� ��������� "�����������" ���� b:

		if( oldParent_a )								// if( � ���� a ���� �������� )
		{
			if( oldParent_a->leftNode == a )			// if( ���� a �������� ����� �������� ������ ������������� ���� )
				oldParent_a->leftNode = b;
			else // if( oldParent_a->rightNode == a )	// if( ���� a �������� ������ �������� ������ ������������� ���� )
				oldParent_a->rightNode = b;
		}
		b->parentNode = oldParent_a;

		if( b_wasTheLeftChild )
		{
			b->leftNode = a;
			b->rightNode = tempCopyOf_a->rightNode;
			if( b->rightNode )
				b->rightNode->parentNode = b;
		}
		else
		{
			b->rightNode = a;
			b->leftNode = tempCopyOf_a->leftNode;
			if( b->leftNode )
				b->leftNode->parentNode = b;
		}

		// ���� b "�����������" �� ����� ���� a. ������ ���� ���������� ������ �� ��� ��������� ����� tempCopyOf_a � tempCopyOf_b:
		delete tempCopyOf_a;
		delete tempCopyOf_b;
	}
	else if( oldParent_a == nullptr && oldParent_b != nullptr )	//	if( ���� a �������� ������ ������, � ���� b �� �������� ������ ������ )
	{
		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		a->parentNode = oldParent_b;					// ��������: ���� oldParent_b = a, �� � ���������� ���������� ����� ��������� ������������ ���� ���� a �������� ��������� ��� �� ����!!!
		a->leftNode = b->leftNode;
		a->rightNode = b->rightNode;

		if( oldParent_b->leftNode == b )	// if( b �������� ����� ����� ������ ������������� ���� )
			oldParent_b->leftNode = a;
		else								// if( b �������� ������ ����� ������ ������������� ���� )
			oldParent_b->rightNode = a;					// ��������: ���� oldParent_b = a, �� � ���������� ���������� ����� ��������� ���������� ����������� �����!!!
		if( b->leftNode )
			b->leftNode->parentNode = a;
		if( b->rightNode )
			b->rightNode->parentNode = a;

		b->parentNode = oldParent_a;		// oldParent_a = nullptr;
		b->leftNode = tempCopyOf_a->leftNode;
		b->rightNode = tempCopyOf_a->rightNode;	// ��������: ���� oldParent_b = a, �� � ���������� ���������� ����� ��������� ���������� ����������� �����!!!

		if( b->leftNode )
			b->leftNode->parentNode = b;
		if( b->rightNode )
			b->rightNode->parentNode = b;				// ��������: ���� oldParent_b = a, �� � ���������� ���������� ����� ��������� ���������� ����������� ����� � ������������ ���� ���� b �������� ��������� ��� �� ����!!!

		delete tempCopyOf_a;
	}
	else if( oldParent_a == b )			// ������ ������ ������, ����� �������������� ���� ������� ������������� �����������!
	{
		bool a_wasTheLeftChild;

		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;
		tempCopyOf_b = new NodeOfTree;
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		b->parentNode = a;
		b->leftNode = a->leftNode;
		b->rightNode = a->rightNode;

		if( tempCopyOf_b->leftNode == a )	// if( a ������� ����� �������� ������ ������������� ����, ������� ������� ���� b )
		{
//			oldParent_a->leftNode = b;
			a->leftNode = b;
			a->rightNode = tempCopyOf_b->rightNode;
			a_wasTheLeftChild = true;
		}
		else										// if( a ������� ������ �������� ������ ������������� ����, ������� ������� ���� b )
		{
//			oldParent_a->rightNode = b;					// ��������: ���� oldParent_a = b, �� � ���������� ���������� ����� ��������� ���������� ����������� �����!!!
			a->rightNode = b;
			a->leftNode = tempCopyOf_b->leftNode;
			a_wasTheLeftChild = false;
		}
		if( tempCopyOf_a->leftNode )
			tempCopyOf_a->leftNode->parentNode = b;
		if( tempCopyOf_a->rightNode )
			tempCopyOf_a->rightNode->parentNode = b;
		
		// ���� b "�����������" �� ����� ���� a. ������ ���� ��������� "�����������" ���� a:

		if( oldParent_b )								// if( � ���� b ���� �������� )
		{
			if( oldParent_b->leftNode == b )			// if( ���� b �������� ����� �������� ������ ������������� ���� )
				oldParent_b->leftNode = a;
			else // if( oldParent_b->rightNode == b )	// if( ���� b �������� ������ �������� ������ ������������� ���� )
				oldParent_b->rightNode = a;
		}
		a->parentNode = oldParent_b;

		if( a_wasTheLeftChild )
		{
			a->leftNode = b;
			a->rightNode = tempCopyOf_b->rightNode;
			if( a->rightNode )
				a->rightNode->parentNode = a;
		}
		else
		{
			a->rightNode = b;
			a->leftNode = tempCopyOf_b->leftNode;
			if( a->leftNode )
				a->leftNode->parentNode = a;
		}

		// ���� a "�����������" �� ����� ���� b. ������ ���� ���������� ������ �� ��� ��������� ����� tempCopyOf_a � tempCopyOf_b:
		delete tempCopyOf_a;
		delete tempCopyOf_b;
	}
	else if( oldParent_a != nullptr && oldParent_b == nullptr )		//	if( ���� a �� �������� ������ ������, � ���� b �������� ������ ������ )
	{
		tempCopyOf_b = new NodeOfTree;
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		b->parentNode = oldParent_a;					// ��������: ���� oldParent_a = b, �� � ���������� ���������� ����� ��������� ������������ ���� ���� b �������� ��������� ��� �� ����!!!
		b->leftNode = a->leftNode;
		b->rightNode = a->rightNode;

		if( oldParent_a->leftNode == a )	// if( a �������� ����� ����� ������ ������������� ���� )
			oldParent_a->leftNode = b;
		else								// if( a �������� ������ ����� ������ ������������� ���� )
			oldParent_a->rightNode = b;					// ��������: ���� oldParent_a = b, �� � ���������� ���������� ����� ��������� ���������� ����������� �����!!!
		if( a->leftNode )
			a->leftNode->parentNode = b;
		if( a->rightNode )
			a->rightNode->parentNode = b;

		a->parentNode = oldParent_b;		// oldParent_b = nullptr;
		a->leftNode = tempCopyOf_b->leftNode;
		a->rightNode = tempCopyOf_b->rightNode;	// ��������: ���� oldParent_a = b, �� � ���������� ���������� ����� ��������� ���������� ����������� �����!!!

		if( a->leftNode )
			a->leftNode->parentNode = a;
		if( a->rightNode )
			a->rightNode->parentNode = a;				// ��������: ���� oldParent_a = b, �� � ���������� ���������� ����� ��������� ���������� ����������� ����� � ������������ ���� ���� a �������� ��������� ��� �� ����!!!

		delete tempCopyOf_b;
	}
	else // if( oldParent_a != nullptr && oldParent_b != nullptr )	//	if( ���� a �� �������� ������ ������, � ���� b �� �������� ������ ������, � ��� ���� �� ������� ������������� ����������� )
	{
		// � ���� ����� ���� � ����� a � b �������������� ���� ������������ ����.
		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		// � ������ "������������" ���� a �� ����� ���� b:
		a->parentNode = oldParent_b;
		a->leftNode = b->leftNode;
		a->rightNode = b->rightNode;

		if( oldParent_b->leftNode == b )	// if( b �������� ����� ����� ������ ������������� ���� )
			oldParent_b->leftNode = a;
		else								// if( b �������� ������ ����� ������ ������������� ���� )
			oldParent_b->rightNode = a;

		if( a->leftNode )
			a->leftNode->parentNode = a;
		if( a->rightNode )
			a->rightNode->parentNode = a;

		// ������ "������������" ���� b �� �� �����, ��� ������ ��� ���� a:
		b->parentNode = oldParent_a;
		b->leftNode = tempCopyOf_a->leftNode;
		b->rightNode = tempCopyOf_a->rightNode;

		if( oldParent_a->leftNode == a )
			oldParent_a->leftNode = b;
		else
			oldParent_a->rightNode = b;

		if( tempCopyOf_a->leftNode )
			tempCopyOf_a->leftNode->parentNode = b;
		if( tempCopyOf_a->rightNode )
			tempCopyOf_a->rightNode->parentNode = b;

		delete tempCopyOf_a;
	}
}

// ������� ������������ ����������� ����� ������ � ��������� ������������ ������������ ��������������� ���� ����� �� ������.
// � ������, ���� ��� ������������ ��������������� ���������, ������� ����� nullptr, ����� ����� ����� ������������� ���� � �������� ����� �/��� ������ ������� �� ��������� �� ����.
NodeOfTree* Check( NodeOfTree* current )
{
	NodeOfTree* res;
	if( current == nullptr )
		return nullptr;
	if( current->leftNode && current->leftNode->parentNode != current )
	{
		cout << "current->key = " << current->key << endl
			<< "current->leftNode->key = " << current->leftNode->key << endl
			<< "current->leftNode->parentNode != current" << endl
			<< "address of current node: " << current << endl << endl;
		return current;
	}
	if( current->rightNode && current->rightNode->parentNode != current )
	{
		cout << "current->key = " << current->key << endl
			<< "current->rightNode->key = " << current->rightNode->key << endl
			<< "current->rightNode->parentNode != current" << endl
			<< "address of current node: " << current << endl << endl;
		return current;
	}
	else
	{
		res = Check( current->leftNode );			// ����������� ����� ������� ��� ������ ���������.
		if( res != nullptr ) return res;
		return Check( current->rightNode );			// ����������� ����� ������� ��� ������� ���������.
	}
}

// �������� ������������ ��������������� ���� ����� �� ������, �.�. �������� ����, ��� � ������� ���� ������ ���� parentNode ��������� �� ��� ��������� ��������.
// � ������, ���� ��� ������������ ����������� �� ������ ���������, ������� ����� nullptr, ���� ���, ����� ����� ������������� ���� � �������� ���� �� ���� �� ��� �������� �� ��������� �� ����.
NodeOfTree* CheckParentalLinks( NodeOfTree* node )
{
	NodeOfTree *root;
	if( node->parentNode ) root = RootOfTree( node );
	else root = node;
	return Check( root );
}

// ����� �� ������� ��������� ������ � ����������� ��� ����������� ���������.
void Dump2( NodeOfTree const * node, std::string const & rpref, std::string const & cpref, std::string const & lpref )
{
	if ( !node ) return;
	if ( node->rightNode )
		Dump2( node->rightNode, rpref + "  ", rpref + ch_ddia_hor, rpref + ch_ver_spa );
	//std::cout << cpref << std::to_string( ( _Longlong )node->key ) << std::endl;
	std::cout << cpref << node->key << std::endl;
	if ( node->leftNode )
		Dump2( node->leftNode, lpref + ch_ver_spa, lpref + ch_udia_hor, lpref + "  " );
}
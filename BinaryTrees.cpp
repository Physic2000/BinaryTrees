// Реализация бинарных деревьев.
// Особеностью моей реализации бинарных деревьев является то, что в каждом узле дерева сохраняется указатель на его родительский узел.

#include "BinaryTrees.h"

#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <assert.h>
using namespace std;

// Обход дерева реализующий итерационный подход. При этом используется горизонтальный обход.
void TreePrint( NodeOfTree *tree )
{
	assert( tree );
	queue<NodeOfTree*> q;
	NodeOfTree* currentNode = tree;
	do{
		cout << currentNode->key << ", ";	// Отображаем текущий узел.
		if( currentNode->leftNode ) q.push( currentNode->leftNode );
		if( currentNode->rightNode ) q.push( currentNode->rightNode );
		if( !currentNode->leftNode && !currentNode->rightNode ) currentNode = nullptr;
		if( !q.empty() )
		{
			currentNode = q.front();		// извлекаем из очереди очередной узел;
			q.pop();						// удаляем из очереди извлечённый узел;
		}
	}while( !q.empty() || currentNode );
}

// Обход дерева реализующий итерационный подход. При этом используется вертикальный прямой обход.
void TreePrint_2( NodeOfTree *tree )
{
	assert( tree );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = tree;
	while( currentNode != nullptr || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// извлекаем из стека верхний узел;
			s.pop();							// удаляем из стека извлечённый узел;
		}
		while( currentNode )
		{
			cout << currentNode->key << ", ";	// Отображаем текущий узел.
			if( currentNode->rightNode ) s.push( currentNode->rightNode );
			currentNode = currentNode->leftNode;
		}
	}
}

// Обход дерева реализующий итерационный подход. При этом используется вертикальный обратный обход.
void TreePrint_3( NodeOfTree *tree )
{
	assert( tree );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = tree;
	while( currentNode || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// извлекаем из стека верхний узел;
			s.pop();							// удаляем из стека извлечённый узел;
			cout << currentNode->key << ", ";	// Отображаем текущий узел.
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

// Обход дерева реализующий рекурсивный подход в префиксной форме.
void TreePrint_4( NodeOfTree *tree )
{
	if ( tree != NULL )
	{	//Пока не встретится пустой узел
		cout << tree->key << ", ";			// Отображаем очередной узел.
		TreePrint_4( tree->leftNode );		// Рекурсивный вызов функции для левого поддерева.
		TreePrint_4( tree->rightNode );		// Рекурсивный вызов функции для правого поддерева.
	}
}

// Обход дерева реализующий рекурсивный подход в инфиксной форме.
void TreePrint_5( NodeOfTree *tree )
{
	if ( tree != NULL )
	{	//Пока не встретится пустой узел
		TreePrint_5( tree->leftNode );		// Рекурсивный вызов функции для левого поддерева.
		cout << tree->key << ", ";			// Отображаем очередной узел.
		TreePrint_5( tree->rightNode );		// Рекурсивный вызов функции для правого поддерева.
	}
}

// Обход дерева реализующий рекурсивный подход в постфиксной форме.
void TreePrint_6( NodeOfTree *tree )
{
	if ( tree != NULL )
	{	//Пока не встретится пустой узел
		TreePrint_6( tree->leftNode );		// Рекурсивный вызов функции для левого поддерева.
		TreePrint_6( tree->rightNode );		// Рекурсивный вызов функции для правого поддерева.
		cout << tree->key << ", ";			// Отображаем очередной узел.
	}
}

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует итерационный подход. При этом используется горизонтальный обход.
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
			currentNode = q.front();		// извлекаем из очереди очередной узел;
			q.pop();						// удаляем из очереди извлечённый узел;
		}
	}while( !q.empty() || currentNode );
	return nullptr;
}

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует итерационный подход. При этом используется вертикальный прямой обход.
NodeOfTree* FindKey_2( NodeOfTree* root, int key )
{
	assert( root );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = root;
	while( currentNode != nullptr || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// извлекаем из стека верхний узел;
			s.pop();							// удаляем из стека извлечённый узел;
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

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует итерационный подход. При этом используется вертикальный обратный обход.
NodeOfTree* FindKey_3( NodeOfTree* root, int key )
{
	assert( root );
	stack<NodeOfTree*> s;
	NodeOfTree* currentNode = root;
	while( currentNode || !s.empty() )
	{
		if( !s.empty() )
		{
			currentNode = s.top();				// извлекаем из стека верхний узел;
			s.pop();							// удаляем из стека извлечённый узел;
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

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует рекурсивный обход дерева.
NodeOfTree* FindKey_4( NodeOfTree* root, int key )
{
	NodeOfTree* res;
	if ( root == nullptr )
		return nullptr;
	if ( root->key == key )
		return root;
	else
	{
		res = FindKey_4( root->leftNode, key );			// Рекурсивный вызов функции для левого поддерева.
		if( res != nullptr ) return res;
		return FindKey_4( root->rightNode, key );		// Рекурсивный вызов функции для правого поддерева.
	}
}

// Возвращает указатель на узел дерева бинарного поиска, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
NodeOfTree* FindKeyInBinarySearchTree( NodeOfTree* root, int key )
{
	if( root == nullptr ) return nullptr;
	// Далее гарантировано, что root != nullptr;
	if( root->key == key ) return root;
	if( key < root->key ) return FindKeyInBinarySearchTree( root->leftNode, key );
	return FindKeyInBinarySearchTree( root->rightNode, key );
}

// Возвращает указатель на корень дерева.
NodeOfTree* RootOfTree( NodeOfTree* anyNodeOfTree )
{
	assert( anyNodeOfTree );	// assert( anyNodeOfTree != nullptr );
	NodeOfTree *res = anyNodeOfTree;
	while( res->parentNode != nullptr ) res = res->parentNode;
	return res;
}

// Добавить к текущему узлу узел слева. В качестве добавляемого узла может быть целое дерево. В случае существования у узла currentNode потомка слева работа программы аварийно останавливается.
void AddNodeInLeft( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded )
{
	assert( currentNode );						// assert( currentNode != nullptr );
	assert( nodeToBeAdded );					// assert( nodeToBeAdded != nullptr );
	assert( !currentNode->leftNode );			// assert( currentNode->leftNode == nullptr );
	currentNode->leftNode = nodeToBeAdded;
	nodeToBeAdded->parentNode = currentNode;
}

// Добавить к текущему узлу узел справа. В качестве добавляемого узла может быть целое дерево. В случае существования у узла currentNode потомка справа работа программы аварийно останавливается.
void AddNodeInRight( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded )
{
	assert( currentNode );						// assert( currentNode != nullptr );
	assert( nodeToBeAdded );					// assert( nodeToBeAdded != nullptr );
	assert( !currentNode->rightNode );			// assert( currentNode->rightNode == nullptr );
	currentNode->rightNode = nodeToBeAdded;
	nodeToBeAdded->parentNode = currentNode;
}

// Заменить текущий узел одиночным узлом. Текущий узел может быть любым узлом дерева в том числе и его корнем, а одиночный узел не должен иметь ни родительского узла, ни своих потомков.
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
			parentNode->leftNode = singleNode;		// Этот оператор равносилен оператору: currentNode = singleNode;
		else // if( parentNode->rightNode == currentNode )
			parentNode->rightNode = singleNode;		// Этот оператор равносилен оператору: currentNode = singleNode;
		singleNode->parentNode = parentNode;
	}
	else // if( currentNode->parentNode == nullptr )
		currentNode = singleNode;
}

// Заменить удаляемый узел перемещаемым узлом. И удаляемый и перемещаемый узлы могут быть целыми деревьями или поддеревьями.
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
		// Отцепляем перемещаемое поддерево от его прежнего родительского узла:
		if( replacementNode->parentNode->leftNode == replacementNode )
			replacementNode->parentNode->leftNode = nullptr;
		else // if( replacementNode->parentNode->rightNode == replacementNode )
			replacementNode->parentNode->rightNode = nullptr;

		// Прицепляем перемещаемое поддерево к его новому родительскому узлу:
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

// Добавление узлов в дерево бинарного поиска.
struct NodeOfTree* AddNode( int k, NodeOfTree* tree )
{
	if ( tree == NULL )
	{	// Если дерева нет, то формируем корень или новый лист.
		tree = new NodeOfTree;		// Выделяем память под узел.
		tree->key = k;				// Инициализируем ключ данных.
		/*
		assert( tree->height == 1 );
		assert( tree->parentNode == nullptr );
		assert( tree->leftNode ==  NULL );
		assert( tree->rightNode == NULL );		// Ветви должны быть проинициализированы значением NULL или nullptr, что тоже самое.
		*/
	}
	else if ( k < tree->key )		// условие добавление левого потомка
	{
		tree->leftNode = AddNode( k, tree->leftNode );
		tree->leftNode->parentNode = tree;
	}
	else							// условие добавление правого потомка
	{
		tree->rightNode = AddNode( k, tree->rightNode );
		tree->rightNode->parentNode = tree;
	}
	// обновить высоту узла-предка
	CalculatingHeight( tree );
	return( tree );
}

// Добавление узлов в дерево бинарного поиска.
void AddNode_2( int k, NodeOfTree*& tree )
{
	if ( tree == NULL )
	{	// Если дерева нет, то формируем корень или новый лист.
		tree = new NodeOfTree;		// Выделяем память под узел.
		tree->key = k;				// Инициализируем ключ данных.
		/*
		assert( tree->height == 1 );
		tree->parentNode = NULL;
		tree->leftNode = nullptr;
		tree->rightNode = nullptr;	// Ветви инициализируем значением NULL или nullptr, что тоже самое.
		*/
	}
	else if ( k < tree->key )		// условие добавление левого потомка
	{
		AddNode_2( k, tree->leftNode );
		tree->leftNode->parentNode = tree;
	}
	else							// условие добавление правого потомка
	{
		AddNode_2( k, tree->rightNode );
		tree->rightNode->parentNode = tree;
	}
	// обновить высоту узла-предка:
	CalculatingHeight( tree );
}

// Рекурсивное копирование всего бинарного дерева source.
void Copy( NodeOfTree* source, NodeOfTree* node )
{
	// Указатель source не обязан указывать на корень дерева.
	assert( source ); 	//	assert( source != nullptr );	// Аварийная остановка работы программы в случае, если source указывает на nullptr!
	node->key = source->key;
	// Продолжаем рекурсивный обход всего дерева source:
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

// Копирование всего бинарного дерева или его поддерева.
NodeOfTree* CopyFrom( NodeOfTree* source )
{
	assert( source );	//	assert( source != nullptr );
	NodeOfTree* res;
	res = new NodeOfTree( source->key );
	// Начинаем рекурсивный обход всего дерева source:
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

// Правый поворот вокруг p, см. https://habr.com/ru/articles/150732/
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
	CalculatingHeight( q );		// Обновить высоту возвращаемого узла.
	return q;
}

// Левый поворот вокруг q, cм. https://habr.com/ru/articles/150732/
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
	CalculatingHeight( p );		// Обновить высоту возвращаемого узла.
	return p;
}

// Балансировка узла p в АВЛ дереве бинарного поиска.
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
	return p; // балансировка не нужна
}

// Поиск узла с минимальным ключом в дереве двоичного поиска p.
NodeOfTree* FindMinInBinarySearchTree( NodeOfTree* p )
{
	return p->leftNode? FindMinInBinarySearchTree( p->leftNode ): p;
}

// Удаление узла с минимальным ключом из дерева двоичного поиска p и его балансировка.
NodeOfTree* DeleteMinInAVL_BinarySearchTree( NodeOfTree* p )
{
	if( p->leftNode == nullptr )
	{
		if( p->rightNode )
			p->rightNode->parentNode = p->parentNode; // Без этого оператора иногда возникала ошибка - нарушение родительских связей!
		return p->rightNode;
	}
	p->leftNode = DeleteMinInAVL_BinarySearchTree( p->leftNode );
	return BalanceNodeInAVL_BinarySearchTree( p );
}

// Удаление узла с ключом k из АВЛ дерева двоичного поиска p и его балансировка.
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
		if( p->parentNode == nullptr ) // Если удаляемый узел является корнем дерева.
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
//	CalculatingHeight( p );		// Обновить высоту возвращаемого узла.
	return BalanceNodeInAVL_BinarySearchTree( p );
}

// Вставка ключа k в АВЛ дерево двоичного поиска с корнем p и его балансировка.
NodeOfTree* InsertNodeToAVL_BinarySearchTree( NodeOfTree* p, int k )
{
	if( !p )	// if ( p == nullptr )
		return new NodeOfTree( k );
	// Далее гарантировано, что p != nullptr
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

// Построение АВЛ дерева бинарного поиска из массива.
NodeOfTree* BuildAVL_BinarySearchTreeFrom( int *arr, int size )
{
	NodeOfTree *res = nullptr;
	for( int i = 0; i < size; i++ )
		res = InsertNodeToAVL_BinarySearchTree( res, arr[i] );
	return res;
}

// Построение АВЛ дерева бинарного поиска из бинарного дерева.
NodeOfTree* BuildAVL_BinarySearchTreeFrom(  NodeOfTree* source, NodeOfTree* res )
{
	if ( source ) // if ( source != nulptr )
	{
		res = InsertNodeToAVL_BinarySearchTree( res, source->key );
		// Продолжаем рекурсивный обход всего дерева source:
		res = BuildAVL_BinarySearchTreeFrom( source->leftNode, res );
		res = BuildAVL_BinarySearchTreeFrom( source->rightNode, res );
	}
	return res;
}

// Построение АВЛ дерева бинарного поиска из бинарного дерева.
NodeOfTree* BuildAVL_BinarySearchTreeFrom( NodeOfTree* source )
{
	NodeOfTree *res = nullptr;
	if ( source )
	{
		res = InsertNodeToAVL_BinarySearchTree( res, source->key );
		// Начинаем рекурсивный обход левого и правого поддеревьев дерева source:
		res = BuildAVL_BinarySearchTreeFrom( source->leftNode, res );
		res = BuildAVL_BinarySearchTreeFrom( source->rightNode, res );
	}
	return res;
}

// Удаление поддерева или всего дерева целиком. Возвращается корень полученного дерева.
NodeOfTree* DeleteNode( NodeOfTree*& node )
{
	NodeOfTree *res = node;
	if( node->parentNode != nullptr )
	{
		if( node->parentNode->leftNode == node )
			node->parentNode->leftNode = nullptr;
		else
			node->parentNode->rightNode = nullptr;
		while( res->parentNode != nullptr ) res = res->parentNode;	// Поднимаемся до корня дерева.
	}
	if( res == node ) res = nullptr;	// Т.е. в случае, когда удаляется узел являющийся единственным на дереве.
	FreeMem( node );					// И в случае удаления всего дерева и в случае удаления поддерева.
	return res;
}

// Освобождение памяти, занятой всем деревом целиком или поддеревом дерева.
void FreeMem( NodeOfTree*& tree )
{
	if( tree != NULL )
	{// Обход дерева в постфиксной форме:
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

// Обход дерева и определение его высоты и высот всех его поддеревьев:
void CalculatingHeight( NodeOfTree* node, int &height )
{
	if ( node != nullptr )
	{		// Пока не встретится пустой узел:
		int heightLeft, heightRight, currentHeight;
		heightLeft = heightRight = 1;
		CalculatingHeight( node->leftNode, heightLeft );		// Рекурсивный вызов функции для левого поддерева.
		CalculatingHeight( node->rightNode, heightRight );		// Рекурсивный вызов функции для правого поддерева.
		currentHeight = max( heightLeft, heightRight );
		node->height = currentHeight;
		height += currentHeight;
	}
}

// Определение высоты бинарного дерева и всех его поддеревьев.
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

// Является ли бинарное дерево деревом двоичного поиска.
bool IsItBinarySearchTree( NodeOfTree* p, int minKey, int maxKey )
{
	if ( p == nullptr )
		return true;
	if ( minKey < p->key && p->key < maxKey )
		return IsItBinarySearchTree( p->leftNode, minKey, p->key ) && IsItBinarySearchTree( p->rightNode, p->key, maxKey );
	return false;
}

// Является ли бинарное дерево деревом двоичного поиска.
bool IsItBinarySearchTree( NodeOfTree* p )
{
	return IsItBinarySearchTree( p, minInt, maxInt );
}

// Является ли бинарное дерево АВЛ деревом.
bool IsItAVL_Tree( NodeOfTree* tree )
{
	bool res = true;
	int heightLeft, heightRight;
	// Вычисление высоты текущего дерева и всех его поддеревьев:
	CalculatingHeight ( tree ); // Возможно, что вызов этой функции является избыточным и должен быть закомментирован!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	if ( tree != nullptr && res )
	{	// Пока не встретится пустой узел или пока модуль разницы высот левого и правого поддеревьев не окажется больше 1:
		heightLeft = Height( tree->leftNode );
		heightRight = Height( tree->rightNode );
		if( abs( heightLeft - heightRight ) > 1 ) return false;
		res = IsItAVL_Tree( tree->leftNode );		// Рекурсивный вызов функции для левого поддерева.
		if( res )
			res = IsItAVL_Tree( tree->rightNode );	// Рекурсивный вызов функции для правого поддерева.
		else
			return false;
	}
	else	// Встретился пустой узел:
		return res;

	return res;
}

// Является ли бинарное дерево идеально сбалансированным.
bool IsItIdealBalancedTree( NodeOfTree* tree )
{
	bool res = true;
	if ( tree == nullptr ) return true;
	int numOfLeftNodes, numOfRightNodes;
	if ( tree != nullptr && res )
	{	// Пока не встретится пустой узел или пока модуль разницы количеств узлов в левом и правом поддеревьях не окажется больше 1:
		numOfLeftNodes = NumOfNodes( tree->leftNode );
		numOfRightNodes = NumOfNodes( tree->rightNode );
		if( abs( numOfLeftNodes - numOfRightNodes ) > 1 ) return false;
		res = IsItIdealBalancedTree( tree->leftNode );		// Рекурсивный вызов функции для левого поддерева.
		if( res )
			res = IsItIdealBalancedTree( tree->rightNode );	// Рекурсивный вызов функции для правого поддерева.
		else
			return false;
	}
	else	// Встретился пустой узел:
		return res;

	return res;
}

// Построение идеально сбалансированного бинарного дерева из массива.
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

// Построение идеально сбалансированного бинарного дерева из массива.
NodeOfTree* BuildIdealBalancedTreeFrom( int *arr, int size )
{
	int index = 0;
	return BuildIdealBalancedTreeFrom( arr, size, index );
}

// Построение идеально сбалансированного дерева из бинарного дерева.
NodeOfTree* BuildIdealBalancedTreeFrom( queue<NodeOfTree*> &q, int numOfNodes )
{
	if ( numOfNodes == 0 ) return nullptr;
	assert( !q.empty() );		// Аварийная остановка работы программы, если очередь q пуста!

	NodeOfTree *currentNode = q.front();	// извлекаем из очереди очередной узел;
	q.pop();								// удаляем из очереди извлечённый узел;

	NodeOfTree *res = new NodeOfTree( currentNode->key );
	int nl, nr;
	nl = numOfNodes / 2;
	nr = numOfNodes - nl - 1;
	// Рекурсивный обход дерева:
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

// Построение идеально сбалансированного дерева из бинарного дерева.
NodeOfTree* BuildIdealBalancedTreeFrom( NodeOfTree* source )
{
	if ( !source )  // if ( source == nullptr )
		return nullptr;
	// Далее гарантировано, что source != nullptr
//	assert( source->parentNode == nullptr );		// Аварийная остановка работы программы, если указатель source указывает не на корень дерева!
	int numOfNodes = NumOfNodes( source );
	queue<NodeOfTree*> q;
	q.push( source );
	return BuildIdealBalancedTreeFrom( q, numOfNodes );
}

// Смена поддеревьев.
void SwapTrees( NodeOfTree* &a, NodeOfTree* &b )
{
	assert( a );
	assert( b );
	NodeOfTree *oldParent_a, *oldParent_b, *temp, *tempCopyOf_a, *tempCopyOf_b;
	oldParent_a = a->parentNode;
	oldParent_b = b->parentNode;
	if( oldParent_a == nullptr && oldParent_b == nullptr )	//	if( a и b являются корнями своих деревьев )
	{
		temp = a;
		a = b;
		b = temp;
	}
	else if( oldParent_a == nullptr && oldParent_b != nullptr )
	{
//		temp = CopyFrom( b );	// Это очень дорогостоящая операция в плане использования памяти, т.к. происходит копирование всего поддерева 'b'. Поэтому хотим избежать применения этой операции.
		// Для этого создаём временную копию только одного узла - головного узла поддерева 'b'.
		tempCopyOf_b = new NodeOfTree( b->key );
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		/*
		if( oldParent_b->leftNode == b )
			oldParent_b->leftNode = a;	//	тоже самое, что и оператор: b = a;
		else // if( oldParent_b->rightNode == b )
			oldParent_b->rightNode = a;	//	тоже самое, что и оператор: b = a;
		*/
		b = a;	// Теперь указатели b и a указывают на одну и ту же область памяти, на которую изначально указывал a.
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
//		temp = CopyFrom( a );	// Это очень дорогостоящая операция в плане использования памяти, т.к. происходит копирование всего поддерева 'a'. Поэтому хотим избежать применения этой операции.
		// Для этого создаём временную копию только одного узла - головного узла поддерева 'a'.
		tempCopyOf_a = new NodeOfTree( a->key );
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		/*
		if( oldParent_a->leftNode == a )
			oldParent_a->leftNode = b;	//	тоже самое, что и оператор: a = b;
		else // if( oldParent_a->rightNode == a )
			oldParent_a->rightNode = b;	//	тоже самое, что и оператор: a = b;
		*/
		a = b;	// Теперь указатели a и b указывают на одну и ту же область памяти, на которую изначально указывал b.
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
//		temp = CopyFrom( a );	// Это очень дорогостоящая операция в плане использования памяти, т.к. происходит копирование всего поддерева 'a'. Поэтому хотим избежать применения этой операции.
		// Для этого создаём временную копию только одного узла - головного узла поддерева 'a'.
		tempCopyOf_a = new NodeOfTree( a->key );
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		/*
		if( oldParent_a->leftNode == a )
			oldParent_a->leftNode = b;	//	тоже самое, что и оператор: a = b;
		else // if( oldParent_a->rightNode == a )
			oldParent_a->rightNode = b;	//	тоже самое, что и оператор: a = b;
		*/
		a = b;	// Теперь указатели a и b указывают на одну и ту же область памяти, на которую изначально указывал b.
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

// Смена узлов на одном дереве или на разных деревьях.
void Swap( NodeOfTree* &a, NodeOfTree* &b )
{
	assert( a );
	assert( b );
	NodeOfTree *oldParent_a, *oldParent_b, *tempCopyOf_a, *tempCopyOf_b, *temp;
	oldParent_a = a->parentNode;
	oldParent_b = b->parentNode;
	if( oldParent_a == nullptr && oldParent_b == nullptr )	//	if( a и b являются корнями своих деревьев )
	{
		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;
		tempCopyOf_b = new NodeOfTree;
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		temp = a;
		a = b;	// Теперь указатели a и b указывают на одну и ту же область памяти, на которую изначально указывал b.
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
	else if( oldParent_b == a )			// ВАЖНЫЙ ОСОБЫЙ СЛУЧАЙ, КОГДА ПЕРЕСТАВЛЯЕМЫЕ УЗЛЫ СВЯЗАНЫ РОДИТЕЛЬСКИМИ ОТНОШЕНИЯМИ!
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

		if( tempCopyOf_a->leftNode == b )			// if( b являлся левым потомком своего родительского узла, которым являлся узел a )
		{
//			oldParent_b->leftNode = a;
			b->leftNode = a;
			b->rightNode = tempCopyOf_a->rightNode;
			b_wasTheLeftChild = true;
		}
		else										// if( b являлся правым потомком своего родительского узла, которым являлся узел a )
		{
//			oldParent_b->rightNode = a;					// ВНИМАНИЕ: если oldParent_b = a, то в результате выполнения этого оператора образуется бесконечная петля!!!
			b->rightNode = a;
			b->leftNode = tempCopyOf_a->leftNode;
			b_wasTheLeftChild = false;
		}
		if( tempCopyOf_b->leftNode )
			tempCopyOf_b->leftNode->parentNode = a;
		if( tempCopyOf_b->rightNode )
			tempCopyOf_b->rightNode->parentNode = a;
		
		// Узел a "переместили" на место узла b. Теперь надо аккуратно "переместить" узел b:

		if( oldParent_a )								// if( у узла a есть родитель )
		{
			if( oldParent_a->leftNode == a )			// if( узел a является левым потомком своего родительского узла )
				oldParent_a->leftNode = b;
			else // if( oldParent_a->rightNode == a )	// if( узел a является правым потомком своего родительского узла )
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

		// Узел b "переместили" на место узла a. Теперь надо освободить память из под временных узлов tempCopyOf_a и tempCopyOf_b:
		delete tempCopyOf_a;
		delete tempCopyOf_b;
	}
	else if( oldParent_a == nullptr && oldParent_b != nullptr )	//	if( узел a является корнем дерева, а узел b не является корнем дерева )
	{
		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		a->parentNode = oldParent_b;					// ВНИМАНИЕ: если oldParent_b = a, то в результате выполнения этого оператора родительский узел узла a начинает указывать сам на себя!!!
		a->leftNode = b->leftNode;
		a->rightNode = b->rightNode;

		if( oldParent_b->leftNode == b )	// if( b является левым узлом своего родительского узла )
			oldParent_b->leftNode = a;
		else								// if( b является правым узлом своего родительского узла )
			oldParent_b->rightNode = a;					// ВНИМАНИЕ: если oldParent_b = a, то в результате выполнения этого оператора образуется бесконечная петля!!!
		if( b->leftNode )
			b->leftNode->parentNode = a;
		if( b->rightNode )
			b->rightNode->parentNode = a;

		b->parentNode = oldParent_a;		// oldParent_a = nullptr;
		b->leftNode = tempCopyOf_a->leftNode;
		b->rightNode = tempCopyOf_a->rightNode;	// ВНИМАНИЕ: если oldParent_b = a, то в результате выполнения этого оператора образуется бесконечная петля!!!

		if( b->leftNode )
			b->leftNode->parentNode = b;
		if( b->rightNode )
			b->rightNode->parentNode = b;				// ВНИМАНИЕ: если oldParent_b = a, то в результате выполнения этого оператора образуется бесконечная петля И родительский узел узла b начинает указывать сам на себя!!!

		delete tempCopyOf_a;
	}
	else if( oldParent_a == b )			// ВАЖНЫЙ ОСОБЫЙ СЛУЧАЙ, КОГДА ПЕРЕСТАВЛЯЕМЫЕ УЗЛЫ СВЯЗАНЫ РОДИТЕЛЬСКИМИ ОТНОШЕНИЯМИ!
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

		if( tempCopyOf_b->leftNode == a )	// if( a являлся левым потомком своего родительского узла, которым являлся узел b )
		{
//			oldParent_a->leftNode = b;
			a->leftNode = b;
			a->rightNode = tempCopyOf_b->rightNode;
			a_wasTheLeftChild = true;
		}
		else										// if( a являлся правым потомком своего родительского узла, которым являлся узел b )
		{
//			oldParent_a->rightNode = b;					// ВНИМАНИЕ: если oldParent_a = b, то в результате выполнения этого оператора образуется бесконечная петля!!!
			a->rightNode = b;
			a->leftNode = tempCopyOf_b->leftNode;
			a_wasTheLeftChild = false;
		}
		if( tempCopyOf_a->leftNode )
			tempCopyOf_a->leftNode->parentNode = b;
		if( tempCopyOf_a->rightNode )
			tempCopyOf_a->rightNode->parentNode = b;
		
		// Узел b "переместили" на место узла a. Теперь надо аккуратно "переместить" узел a:

		if( oldParent_b )								// if( у узла b есть родитель )
		{
			if( oldParent_b->leftNode == b )			// if( узел b является левым потомком своего родительского узла )
				oldParent_b->leftNode = a;
			else // if( oldParent_b->rightNode == b )	// if( узел b является правым потомком своего родительского узла )
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

		// Узел a "переместили" на место узла b. Теперь надо освободить память из под временных узлов tempCopyOf_a и tempCopyOf_b:
		delete tempCopyOf_a;
		delete tempCopyOf_b;
	}
	else if( oldParent_a != nullptr && oldParent_b == nullptr )		//	if( узел a НЕ является корнем дерева, а узел b является корнем дерева )
	{
		tempCopyOf_b = new NodeOfTree;
		tempCopyOf_b->leftNode = b->leftNode;
		tempCopyOf_b->rightNode = b->rightNode;

		b->parentNode = oldParent_a;					// ВНИМАНИЕ: если oldParent_a = b, то в результате выполнения этого оператора родительский узел узла b начинает указывать сам на себя!!!
		b->leftNode = a->leftNode;
		b->rightNode = a->rightNode;

		if( oldParent_a->leftNode == a )	// if( a является левым узлом своего родительского узла )
			oldParent_a->leftNode = b;
		else								// if( a является правым узлом своего родительского узла )
			oldParent_a->rightNode = b;					// ВНИМАНИЕ: если oldParent_a = b, то в результате выполнения этого оператора образуется бесконечная петля!!!
		if( a->leftNode )
			a->leftNode->parentNode = b;
		if( a->rightNode )
			a->rightNode->parentNode = b;

		a->parentNode = oldParent_b;		// oldParent_b = nullptr;
		a->leftNode = tempCopyOf_b->leftNode;
		a->rightNode = tempCopyOf_b->rightNode;	// ВНИМАНИЕ: если oldParent_a = b, то в результате выполнения этого оператора образуется бесконечная петля!!!

		if( a->leftNode )
			a->leftNode->parentNode = a;
		if( a->rightNode )
			a->rightNode->parentNode = a;				// ВНИМАНИЕ: если oldParent_a = b, то в результате выполнения этого оператора образуется бесконечная петля И родительский узел узла a начинает указывать сам на себя!!!

		delete tempCopyOf_b;
	}
	else // if( oldParent_a != nullptr && oldParent_b != nullptr )	//	if( узел a НЕ является корнем дерева, И узел b НЕ является корнем дерева, И эти узлы НЕ связаны родительскими отношениями )
	{
		// В этом блоке кода у узлов a и b гарантированно есть родительские узлы.
		tempCopyOf_a = new NodeOfTree;
		tempCopyOf_a->leftNode = a->leftNode;
		tempCopyOf_a->rightNode = a->rightNode;

		// В начале "переставляем" узел a на место узла b:
		a->parentNode = oldParent_b;
		a->leftNode = b->leftNode;
		a->rightNode = b->rightNode;

		if( oldParent_b->leftNode == b )	// if( b является левым узлом своего родительского узла )
			oldParent_b->leftNode = a;
		else								// if( b является правым узлом своего родительского узла )
			oldParent_b->rightNode = a;

		if( a->leftNode )
			a->leftNode->parentNode = a;
		if( a->rightNode )
			a->rightNode->parentNode = a;

		// Теперь "переставляем" узел b на то место, где раньше был узел a:
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

// Функция осуществляет рекурсивный обход дерева и проверяет корректность родительских взаимоотношений всех узлов на дереве.
// В случае, если все родительские взаимоотношения корректны, функция вернёт nullptr, иначе вернёт адрес родительского узла у которого левый И/ИЛИ правый потомок не указывает на него.
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
		res = Check( current->leftNode );			// Рекурсивный вызов функции для левого поддерева.
		if( res != nullptr ) return res;
		return Check( current->rightNode );			// Рекурсивный вызов функции для правого поддерева.
	}
}

// Проверка родительских взаимоотношений всех узлов на дереве, т.е. проверка того, что у каждого узла дерева поле parentNode указывает на его реального родителя.
// В случае, если все родительские взаимосвязи на дереве корректны, функция вернёт nullptr, если нет, вернёт адрес родительского узла у которого хотя бы один из его потомков не указывает на него.
NodeOfTree* CheckParentalLinks( NodeOfTree* node )
{
	NodeOfTree *root;
	if( node->parentNode ) root = RootOfTree( node );
	else root = node;
	return Check( root );
}

// Вывод на консоль бинарного дерева с сохранением его древовидной структуры.
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
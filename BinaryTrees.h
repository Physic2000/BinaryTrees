// Заголовочный файл обьявлений бинарных деревьев.
// Особеностью моей реализации бинарных деревьев является то, что в каждом узле дерева сохраняется указатель на его родительский узел.

#include <string>

const int minInt = ( 1 << 30 ) * 2;
const int maxInt = minInt - 1;

struct NodeOfTree
{
	int key;						// ключ данных;
	unsigned char height;			// высота поддерева с корнем в данном узле;
//	int height;						// высота поддерева с корнем в данном узле;
	struct NodeOfTree *parentNode;	// родительский узел;
	struct NodeOfTree *leftNode;	// левый потомок;
	struct NodeOfTree *rightNode;	// правый потомок;
	NodeOfTree(): parentNode(NULL), leftNode(NULL), rightNode(NULL), height(1) {};
	NodeOfTree( int k ): parentNode(NULL), leftNode(NULL), rightNode(NULL), key(k), height(1) {};
};

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
// Функция выводит на консоль дамп дерева. При этом используется инфиксная форма обхода дерева.
void Dump2( NodeOfTree const * node, std::string const & rpref = "", std::string const & cpref = "", std::string const & lpref = "" );

// Обход дерева реализующий итерационный подход. При этом используется горизонтальный обход.
void TreePrint( NodeOfTree *tree );

// Обход дерева реализующий итерационный подход. При этом используется вертикальный прямой обход.
void TreePrint_2( NodeOfTree *tree );

// Обход дерева реализующий итерационный подход. При этом используется вертикальный обратный обход.
void TreePrint_3( NodeOfTree *tree );

// Обход дерева реализующий рекурсивный подход в префиксной форме.
void TreePrint_4( NodeOfTree *tree );

// Обход дерева реализующий рекурсивный подход в инфиксной форме.
void TreePrint_5( NodeOfTree *tree );

// Обход дерева реализующий рекурсивный подход в постфиксной форме.
void TreePrint_6( NodeOfTree *tree );

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует итерационный подход. При этом используется горизонтальный обход.
NodeOfTree* FindKey( NodeOfTree* root, int key );

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует итерационный подход. При этом используется вертикальный прямой обход.
NodeOfTree* FindKey_2( NodeOfTree* root, int key );

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует итерационный подход. При этом используется вертикальный обратный обход.
NodeOfTree* FindKey_3( NodeOfTree* root, int key );

// Возвращает указатель на узел дерева, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
// Функция реализует рекурсивный подход.
NodeOfTree* FindKey_4( NodeOfTree* root, int key );

// Возвращает указатель на узел дерева бинарного поиска, хранящий разыскиваемое значение ключа, в случае его наличия в дереве, иначе nullptr.
NodeOfTree* FindKeyInBinarySearchTree( NodeOfTree* root, int key );

// Возвращает указатель на корень дерева.
NodeOfTree* RootOfTree( NodeOfTree* anyNodeOfTree );

// Добавить к текущему узлу узел слева. В качестве добавляемого узла может быть целое дерево. В случае существования у узла currentNode потомка слева работа программы аварийно останавливается.
void AddNodeInLeft( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded );

// Добавить к текущему узлу узел справа. В качестве добавляемого узла может быть целое дерево. В случае существования у узла currentNode потомка справа работа программы аварийно останавливается.
void AddNodeInRight( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded );

// Заменить текущий узел одиночным узлом. Текущий узел может быть любым узлом дерева в том числе и его корнем, а одиночный узел не должен иметь ни родительского узла, ни своих потомков.
void ReplaceSingleNode( NodeOfTree* &currentNode, NodeOfTree* singleNode );

// Заменить удаляемый узел перемещаемым узлом. И удаляемый и перемещаемый узлы могут быть целыми деревьями или поддеревьями.
void ReplaceNodeInsteadNode( NodeOfTree* &nodeToBeDeleted, NodeOfTree* replacementNode );

// Смена узлов на одном дереве или на разных деревьях.
void Swap( NodeOfTree* &a, NodeOfTree* &b );

// Смена поддеревьев.
void SwapTrees( NodeOfTree* &a, NodeOfTree* &b );

// Проверка родительских взаимоотношений всех узлов на дереве, т.е. проверка того, что у каждого узла дерева поле parentNode указывает на его реального родителя.
// В случае, если все родительские взаимосвязи на дереве корректны, функция вернёт nullptr, если нет, вернёт адрес родительского узла у которого хотя бы один из его потомков не указывает на него.
NodeOfTree* CheckParentalLinks( NodeOfTree* node );

// Копирование всего бинарного дерева или его поддерева.
NodeOfTree* CopyFrom( NodeOfTree* source );

// Удаление поддерева или всего дерева целиком. Возвращается корень полученного дерева.
NodeOfTree* DeleteNode( NodeOfTree*& tree );

// Освобождение памяти, занятой всем деревом целиком или поддеревом дерева.
void FreeMem( NodeOfTree*& tree );

// Определение количества узлов на бинарном дереве.
int NumOfNodes( NodeOfTree* tree );

// Вычисление высоты бинарного дерева и всех его поддеревьев.
int CalculatingHeight( NodeOfTree* tree );

// Возвращает высоту текущего дерева или заданного узла.
int Height( NodeOfTree* p );

// Вычисляет balance factor текущего дерева или заданного узла.
int BalanceFactor( NodeOfTree* p );

// Правый поворот вокруг p, см. https://habr.com/ru/articles/150732/
NodeOfTree* RotateRight( NodeOfTree* p );

// Левый поворот вокруг q, cм. https://habr.com/ru/articles/150732/
NodeOfTree* RotateLeft( NodeOfTree* q );

// Балансировка узла p в АВЛ дереве двоичного поиска.
NodeOfTree* BalanceNodeInAVL_BinarySearchTree( NodeOfTree* p );

// Вставка ключа key в АВЛ дерево двоичного поиска с корнем p и его балансировка.
NodeOfTree* InsertNodeToAVL_BinarySearchTree( NodeOfTree* p, int key );

// Удаление узла с ключом key из АВЛ дерева двоичного поиска с корнем p и его балансировка.
NodeOfTree* DeleteNodeFromAVL_BinarySearchTree( NodeOfTree* p, int key );

// Является ли бинарное дерево АВЛ деревом.
bool IsItAVL_Tree( NodeOfTree* tree );

// Является ли бинарное дерево идеально сбалансированным.
bool IsItIdealBalancedTree( NodeOfTree* tree );

// Является ли бинарное дерево деревом двоичного поиска.
bool IsItBinarySearchTree( NodeOfTree* tree );

// Добавление узла в дерево двоичного поиска.
struct NodeOfTree* AddNode( int key, NodeOfTree* tree );

// Добавление узла в дерево двоичного поиска.
void AddNode_2( int key, NodeOfTree*& tree );

// Построение идеально сбалансированного дерева из массива.
NodeOfTree* BuildIdealBalancedTreeFrom( int *arr, int size );

// Построение идеально сбалансированного дерева из бинарного дерева.
NodeOfTree* BuildIdealBalancedTreeFrom( NodeOfTree* tree );

// Построение АВЛ дерева бинарного поиска из массива.
NodeOfTree* BuildAVL_BinarySearchTreeFrom( int *arr, int size );

// Построение АВЛ дерева бинарного поиска из бинарного дерева.
NodeOfTree* BuildAVL_BinarySearchTreeFrom( NodeOfTree* tree );

template<typename Type>
void Swap( Type &a, Type &b )
{
	Type tmp = a;
	a = b;
	b = tmp;
}

template<typename Type>
void SortArrayDescending( Type *arr, int size )
{
	int numOfSwaps;
	do{
		numOfSwaps = 0;
		for( int i = 0; i < size - 1; i++ )
			if( arr[i] < arr[i + 1] )
			{
				Swap<Type>( arr[i], arr[i + 1] );
				//Swap( arr[i], arr[i + 1] );			// Вызов шаблонной функции можно сделать и так, в этом случае компилятор сам выведет, т.е. определит тип Type передаваемых аргументов.
				numOfSwaps++;
			}
	}while( numOfSwaps > 0 );
}

template<typename Type>
void SortArrayAscending( Type *arr, int size )
{
	int numOfSwaps;
	do{
		numOfSwaps = 0;
		for( int i = 0; i < size - 1; i++ )
			if( arr[i] > arr[i + 1] )
			{
				//Swap<Type>( arr[i], arr[i + 1] );
				Swap( arr[i], arr[i + 1] );				// Вызов шаблонной функции можно сделать и так, в этом случае компилятор сам выведет, т.е. определит тип Type передаваемых аргументов.
				numOfSwaps++;
			}
	}while( numOfSwaps > 0 );
}

template<typename Type>
Type Abs( Type x )
{
	return ( x > 0? x: -x );
}
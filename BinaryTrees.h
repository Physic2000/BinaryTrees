// ������������ ���� ���������� �������� ��������.
// ����������� ���� ���������� �������� �������� �������� ��, ��� � ������ ���� ������ ����������� ��������� �� ��� ������������ ����.

#include <string>

const int minInt = ( 1 << 30 ) * 2;
const int maxInt = minInt - 1;

struct NodeOfTree
{
	int key;						// ���� ������;
	unsigned char height;			// ������ ��������� � ������ � ������ ����;
//	int height;						// ������ ��������� � ������ � ������ ����;
	struct NodeOfTree *parentNode;	// ������������ ����;
	struct NodeOfTree *leftNode;	// ����� �������;
	struct NodeOfTree *rightNode;	// ������ �������;
	NodeOfTree(): parentNode(NULL), leftNode(NULL), rightNode(NULL), height(1) {};
	NodeOfTree( int k ): parentNode(NULL), leftNode(NULL), rightNode(NULL), key(k), height(1) {};
};

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
// ������� ������� �� ������� ���� ������. ��� ���� ������������ ��������� ����� ������ ������.
void Dump2( NodeOfTree const * node, std::string const & rpref = "", std::string const & cpref = "", std::string const & lpref = "" );

// ����� ������ ����������� ������������ ������. ��� ���� ������������ �������������� �����.
void TreePrint( NodeOfTree *tree );

// ����� ������ ����������� ������������ ������. ��� ���� ������������ ������������ ������ �����.
void TreePrint_2( NodeOfTree *tree );

// ����� ������ ����������� ������������ ������. ��� ���� ������������ ������������ �������� �����.
void TreePrint_3( NodeOfTree *tree );

// ����� ������ ����������� ����������� ������ � ���������� �����.
void TreePrint_4( NodeOfTree *tree );

// ����� ������ ����������� ����������� ������ � ��������� �����.
void TreePrint_5( NodeOfTree *tree );

// ����� ������ ����������� ����������� ������ � ����������� �����.
void TreePrint_6( NodeOfTree *tree );

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ������������ ������. ��� ���� ������������ �������������� �����.
NodeOfTree* FindKey( NodeOfTree* root, int key );

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ������������ ������. ��� ���� ������������ ������������ ������ �����.
NodeOfTree* FindKey_2( NodeOfTree* root, int key );

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ������������ ������. ��� ���� ������������ ������������ �������� �����.
NodeOfTree* FindKey_3( NodeOfTree* root, int key );

// ���������� ��������� �� ���� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
// ������� ��������� ����������� ������.
NodeOfTree* FindKey_4( NodeOfTree* root, int key );

// ���������� ��������� �� ���� ������ ��������� ������, �������� ������������� �������� �����, � ������ ��� ������� � ������, ����� nullptr.
NodeOfTree* FindKeyInBinarySearchTree( NodeOfTree* root, int key );

// ���������� ��������� �� ������ ������.
NodeOfTree* RootOfTree( NodeOfTree* anyNodeOfTree );

// �������� � �������� ���� ���� �����. � �������� ������������ ���� ����� ���� ����� ������. � ������ ������������� � ���� currentNode ������� ����� ������ ��������� �������� ���������������.
void AddNodeInLeft( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded );

// �������� � �������� ���� ���� ������. � �������� ������������ ���� ����� ���� ����� ������. � ������ ������������� � ���� currentNode ������� ������ ������ ��������� �������� ���������������.
void AddNodeInRight( NodeOfTree* currentNode, NodeOfTree* nodeToBeAdded );

// �������� ������� ���� ��������� �����. ������� ���� ����� ���� ����� ����� ������ � ��� ����� � ��� ������, � ��������� ���� �� ������ ����� �� ������������� ����, �� ����� ��������.
void ReplaceSingleNode( NodeOfTree* &currentNode, NodeOfTree* singleNode );

// �������� ��������� ���� ������������ �����. � ��������� � ������������ ���� ����� ���� ������ ��������� ��� ������������.
void ReplaceNodeInsteadNode( NodeOfTree* &nodeToBeDeleted, NodeOfTree* replacementNode );

// ����� ����� �� ����� ������ ��� �� ������ ��������.
void Swap( NodeOfTree* &a, NodeOfTree* &b );

// ����� �����������.
void SwapTrees( NodeOfTree* &a, NodeOfTree* &b );

// �������� ������������ ��������������� ���� ����� �� ������, �.�. �������� ����, ��� � ������� ���� ������ ���� parentNode ��������� �� ��� ��������� ��������.
// � ������, ���� ��� ������������ ����������� �� ������ ���������, ������� ����� nullptr, ���� ���, ����� ����� ������������� ���� � �������� ���� �� ���� �� ��� �������� �� ��������� �� ����.
NodeOfTree* CheckParentalLinks( NodeOfTree* node );

// ����������� ����� ��������� ������ ��� ��� ���������.
NodeOfTree* CopyFrom( NodeOfTree* source );

// �������� ��������� ��� ����� ������ �������. ������������ ������ ����������� ������.
NodeOfTree* DeleteNode( NodeOfTree*& tree );

// ������������ ������, ������� ���� ������� ������� ��� ���������� ������.
void FreeMem( NodeOfTree*& tree );

// ����������� ���������� ����� �� �������� ������.
int NumOfNodes( NodeOfTree* tree );

// ���������� ������ ��������� ������ � ���� ��� �����������.
int CalculatingHeight( NodeOfTree* tree );

// ���������� ������ �������� ������ ��� ��������� ����.
int Height( NodeOfTree* p );

// ��������� balance factor �������� ������ ��� ��������� ����.
int BalanceFactor( NodeOfTree* p );

// ������ ������� ������ p, ��. https://habr.com/ru/articles/150732/
NodeOfTree* RotateRight( NodeOfTree* p );

// ����� ������� ������ q, c�. https://habr.com/ru/articles/150732/
NodeOfTree* RotateLeft( NodeOfTree* q );

// ������������ ���� p � ��� ������ ��������� ������.
NodeOfTree* BalanceNodeInAVL_BinarySearchTree( NodeOfTree* p );

// ������� ����� key � ��� ������ ��������� ������ � ������ p � ��� ������������.
NodeOfTree* InsertNodeToAVL_BinarySearchTree( NodeOfTree* p, int key );

// �������� ���� � ������ key �� ��� ������ ��������� ������ � ������ p � ��� ������������.
NodeOfTree* DeleteNodeFromAVL_BinarySearchTree( NodeOfTree* p, int key );

// �������� �� �������� ������ ��� �������.
bool IsItAVL_Tree( NodeOfTree* tree );

// �������� �� �������� ������ �������� ����������������.
bool IsItIdealBalancedTree( NodeOfTree* tree );

// �������� �� �������� ������ ������� ��������� ������.
bool IsItBinarySearchTree( NodeOfTree* tree );

// ���������� ���� � ������ ��������� ������.
struct NodeOfTree* AddNode( int key, NodeOfTree* tree );

// ���������� ���� � ������ ��������� ������.
void AddNode_2( int key, NodeOfTree*& tree );

// ���������� �������� ����������������� ������ �� �������.
NodeOfTree* BuildIdealBalancedTreeFrom( int *arr, int size );

// ���������� �������� ����������������� ������ �� ��������� ������.
NodeOfTree* BuildIdealBalancedTreeFrom( NodeOfTree* tree );

// ���������� ��� ������ ��������� ������ �� �������.
NodeOfTree* BuildAVL_BinarySearchTreeFrom( int *arr, int size );

// ���������� ��� ������ ��������� ������ �� ��������� ������.
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
				//Swap( arr[i], arr[i + 1] );			// ����� ��������� ������� ����� ������� � ���, � ���� ������ ���������� ��� �������, �.�. ��������� ��� Type ������������ ����������.
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
				Swap( arr[i], arr[i + 1] );				// ����� ��������� ������� ����� ������� � ���, � ���� ������ ���������� ��� �������, �.�. ��������� ��� Type ������������ ����������.
				numOfSwaps++;
			}
	}while( numOfSwaps > 0 );
}

template<typename Type>
Type Abs( Type x )
{
	return ( x > 0? x: -x );
}
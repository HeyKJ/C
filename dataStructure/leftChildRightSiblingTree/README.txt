Left-Child Right-SIbling Tree

트리는 3가지 요소로 이루어져 있다.
- 뿌리(Root)
- 가지(Branch)
- 잎(Leaf)

Root는 최상위 노드를 말함
Branch는 Root와 Leaf사이에 있는 모든 노드를 말함
Leaf는 Branch에 매달려있는 노드를 말함
							[depth]
		[Root]				- 0
	|			|
[Branch]	[Branch]		- 1
				|
			 [Leaf]			- 2


같은 1 depth에 있는 노드는 sibling(형제)이다.
2depth에 있는 노드는 1 death의 childern(자식)이다.

Left-Child Right-SIbling Tree의 노드 구조는 아래와 같다.

[data][leftChild Pointer][rightSibling Pointer]

비효율적으로 모든 자식 노드의 포인터를 저장하는게 아니라
해당 노드는 자식 노드에서 가장 왼쪽에 존재하는 노드 포인터, 그리고 자신의 오른쪽 형제 포인터만 가르킨다면 모든 트리안에 노드로 탐색이 가능하다.
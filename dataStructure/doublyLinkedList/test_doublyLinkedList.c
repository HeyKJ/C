#include "doublyLinkedList.h"

void printfNodeList(Node* list); //노드 리스트 출력

int main()
{
	Node* list = NULL;
	Node* currentNode = NULL;
	Node* newNode = NULL;
	
	/*노드 5개 추가*/
	for (int i = 0; i < 5; i++)
	{
		newNode = createNode(i); //i값을 갖는 새로운 노드를 생성
		appendNode(&list, newNode); //생성된 노드를 list에 추가
	}

	/*새로운 헤드 노드 2개 추가*/
	newNode = createNode(-1);
	insertNewHead(&list, newNode); //list에 -1값을 갖는 노드를 헤드 노드로 추가
	
	newNode = createNode(-2);
	insertNewHead(&list, newNode); //list에 -2값을 갖는 노드를 헤드 노드로 추가

	/*리스트 출력*/
	printfNodeList(list);

	//리스트 세번째 노드에 새로운 노드를 삽입
	printf("\ninsert newNode after thrid node...\n\n");
	currentNode = getNodeAt(list, 2); //세번째에 있는 노드 반환
	newNode = createNode(3000); //3000값을 갖는 새로운 노드를 생성
	insertAfter(currentNode, newNode); //세번째 노드 뒤에 newNode를 삽입
	
	/*리스트 출력*/
	printfNodeList(list);

	/*리스트 네번째 노드를 제거*/
	printf("\nafter remove forth node...\n\n");
	currentNode = getNodeAt(list, 3);
	removeNode(&list, currentNode);
	destoryNode(currentNode);

	/*리스트 출력*/
	printfNodeList(list);

	/*모든 노드 제거*/
	printf("\ndestroy all nodes..\n");
	int count = getNodeCount(list); //list에 담긴 노드 개수
	for (int i = 0; i < count; i++)
	{
		currentNode = getNodeAt(list, i); //list에 담긴 노드중 i번째에 위치한 노드를 가져온다
		
		if (currentNode != NULL)
		{
			removeNode(&list, currentNode); //list에서 삭제
			destoryNode(currentNode); //해당 노드 메모리 해제
		}
	}

	return 0;
}

void printfNodeList(Node* list)
{
	Node* currentNode = NULL;
	int count = getNodeCount(list); //list에 담긴 노드 개수

	for (int i = 0; i < count; i++)
	{
		currentNode = getNodeAt(list, i); //list에 담긴 노드중 i번째에 위치한 노드를 가져온다
		printf("list[%d][%u] : %d\n", i, currentNode, currentNode->data);
	}
}
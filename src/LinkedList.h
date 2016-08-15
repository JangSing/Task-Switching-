#ifndef LinkedList_H
#define LinkedList_H

typedef struct ListElement_t{
  struct ListElement_t *next;
  void *value;
}ListElement;

typedef struct {
  ListElement *head;
  ListElement *tail;
  int length;
}LinkedList;


void linkedListInit(LinkedList *list);

//*** Adding Element function start here ***

void AddLast(ListElement *NewEle,LinkedList *List );
void AddFirst(LinkedList *stack,ListElement *NewElem);

//*** Removing Element function start here ***

ListElement *RemoveFirst(LinkedList *stack);
ListElement *RemoveLast(LinkedList *List);

extern LinkedList tcbList;

#endif // LinkedList_H

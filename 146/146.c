#include <stdlib.h>

typedef struct linkNode{
  struct linkNode *prev;
  struct linkNode *next;
  int value;
} LinkNode;

typedef struct {
  int capacity;
  int count;
  LinkNode privot;
  LinkNode *index[10001];
} LRUCache;

LRUCache *lRUCacheCreate(int capacity);
int lRUCacheGet(LRUCache *obj, int key);
void lRUCachePut(LRUCache *obj, int key, int value);
void lRUCacheFree(LRUCache *obj);

LRUCache* lRUCacheCreate(int capacity) {
  int i;
  
  LRUCache *obj = (LRUCache*)malloc(sizeof(LRUCache));
  
  if (obj == NULL) {
	return NULL;
  }

  obj->capacity = 0;
  obj->count = 0;
  obj->privot.next = NULL;
  obj->privot.prev = NULL;
  obj->privot.value = 0;

  for (i = 0; i < 10001; i++) {
	obj->index[i] = NULL;
  }
  
  return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
  if (obj->index[key] != NULL) {
	return obj->index[key]->value;
  }

  return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  LinkNode *node, *out;
  
  if (obj->index[key] == NULL) {
	node = (LinkNode*)malloc(sizeof(LinkNode));
	if (node == NULL) {
	  return;
	}
	if (obj->count < obj->capacity) {
	  obj->index[key] = node;
	  node->value = value;

	  if (obj->privot.next == NULL) {
		obj->privot.next = node;
		obj->privot.prev = node;
		node->next = &obj->privot;
		node->prev = &obj->privot;
	  } else {
		obj->privot.next->prev = node;
		node->next = obj->privot.next;
		node->prev = &obj->privot;
		obj->privot.next = node;
	  }
	  obj->count++;

	  return;
	} else {
	  out = obj->privot.prev;
	  
	  out->prev->next = &obj->privot;
	  obj->privot.prev = out->prev;
	  node->next = obj->privot.next;
	  node->prev = &obj->privot;
	  obj->privot.next->prev = node;
	  obj->privot.next = node;

	  obj->index[key] = NULL;
	  free(out);
	}
  } else {
	node = obj->index[key];
	
	obj->index[key]->value = value;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	node->next = obj->privot.next;
	node->prev = &obj->privot;
	obj->privot.next = node;
	node->next->prev = node;
  }
}

void lRUCacheFree(LRUCache* obj) {
  int i;

  for (i = 0; i < 10001; i++) {
	if (obj->index[i] != NULL) {
	  free(obj->index[i]);
	}
  }

  free(obj);
}

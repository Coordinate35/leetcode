#include <cstddef>
struct linkNode {
  struct linkNode *prev;
  struct linkNode *post;
  int val;
};

typedef struct {
  void *index[10001];
  struct linkNode *value;
  struct linkNode *last;
  int capacity;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
  LRUCache *obj;
  int i;

  obj = (LRUCache*)malloc(sizeof(LRUCache));
  if (obj == NULL) {
	return NULL;
  }
  obj->capacity = capacity;
  if (capacity < 1) {
	return obj
  }
  for (i = 0; i < 10001; i++) {
	obj->index[i] = NULL;
  }

  obj->value = (struct linkNode*)malloc(capacity * sizeof(struct linkNode));
  if (obj->value == NULL) {
	return NULL;
  }

  obj->value->prev == NULL;
  obj->value->val = -1;  
  if (capacity == 1) {
	obj->value->post = NULL;
  } else {
	obj->value->post = &obj->value[1];
	for (i = 1; i < capacity - 1; i++) {
	  obj->value[i].prev = &obj->value[i-1];
	  obj->value[i].post = &obj->value[i+1];
	  obj->value[i].val = -1;
	}
	obj->value[capacity-1].prev = &obj->value[capacity-2];
	obj->value[capacity-1].post = NULL;
	obj->value[capacity-1].val = -1;
  }

  obj->last = NULL;
  
  return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
  
}

void lRUCacheEliminate(LRUCache *obj) {
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  struct linkNode *target;
  
  if (obj == NULL) {
	return;
  }

  if (obj->index[key] == NULL) {
	if (obj->value[obj->capacity-1].val != -1) {
	  lRUCacheEliminate(obj);
	}
  }
}

void lRUCacheFree(LRUCache *obj) {
  
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    struct TreeNode **queue;
    int last_layer_size = 0;
    int layer_size = 0;
    int queue_size = 0;
    int queue_head = 0;
    int i;
    int number_temp;
    int* list_temp;
    int** result;
    result = (int**)malloc(sizeof(int*));
    *columnSizes = (int*)malloc(sizeof(int));
    *returnSize = 0;  
    if (NULL == root) {
        *returnSize = 0;
        return NULL;
    }
    *columnSizes = (int*)malloc(sizeof(int));
    (*columnSizes)[0] = 1;
    result[0] = (int*)malloc(sizeof(int));
    result[0][0] = root->val;
    *returnSize = 1;
    queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    queue[0] = root;
    layer_size = 1;
    queue_size = 1;
    while (0 != layer_size) {
        last_layer_size = layer_size;
        layer_size = 0;
        *columnSizes = realloc(*columnSizes, (*returnSize + 1) * sizeof(int));
        result = realloc(result, (*returnSize + 1) * sizeof(int*));
        (*columnSizes)[*returnSize] = 0;
        result[*returnSize] = (int*)malloc(sizeof(int));
        for (i = 0; i < last_layer_size; i++) {
            if (NULL != queue[queue_head]->left) {
                queue = realloc(queue, (queue_size + 1) * sizeof(struct TreeNode*));
                queue[queue_size] = queue[queue_head]->left;
                queue_size += 1;
                layer_size += 1;
                (*columnSizes)[*returnSize] +=1;
                result[*returnSize] = realloc(result[*returnSize], (*columnSizes)[*returnSize] * sizeof(int));
                result[*returnSize][(*columnSizes)[*returnSize] - 1] = queue[queue_head]->left->val;
            } 
            if (NULL != queue[queue_head]->right) {
                queue = realloc(queue, (queue_size + 1) * sizeof(struct TreeNode*));
                queue[queue_size] = queue[queue_head]->right;
                queue_size += 1;
                layer_size += 1;
                (*columnSizes)[*returnSize] +=1;
                result[*returnSize] = realloc(result[*returnSize], (*columnSizes)[*returnSize] * sizeof(int));
                result[*returnSize][(*columnSizes)[*returnSize] - 1] = queue[queue_head]->right->val;
            }
            queue_head += 1;
        }
        *returnSize += 1;
    }
    *returnSize -= 1;
    for (i = 0; i < *returnSize / 2; i++) {
        list_temp = result[i];
        result[i] = result[*returnSize - 1 - i];
        result[*returnSize - 1 - i] = list_temp;
        number_temp = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[*returnSize - 1 - i];
        (*columnSizes)[*returnSize - 1 - i] = number_temp;
    }
    return result;
}
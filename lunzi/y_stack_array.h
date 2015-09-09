struct YStackRecord;
typedef struct YStackRecord *YStack;

int y_stack_is_empty(YStack stack);

int y_stack_is_full(YStack stack);

YStack y_stack_create(int max_elements);

void y_stack_dispose(YStack stack);

void y_stack_make_empty(YStack stack);

void y_stack_push(YElementType data, YStack stack);

YElementType y_stack_top(YStack stack);

void y_stack_pop(YStack stack);

YElementType y_stack_top_pop(YStack stack);
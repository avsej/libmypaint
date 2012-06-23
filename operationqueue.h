#ifndef OPERATIONQUEUE_H
#define OPERATIONQUEUE_H

#include <stdint.h>

typedef struct {
    float x;
    float y;
    float radius;
    uint16_t color_r;
    uint16_t color_g;
    uint16_t color_b;
    float color_a;
    float opaque;
    float hardness;
    float aspect_ratio;
    float angle;
    float normal;
    float lock_alpha;
    float colorize;
} OperationDataDrawDab;

typedef struct {
    int x;
    int y;
} TileIndex;

typedef struct _OperationQueue OperationQueue;

OperationQueue *operation_queue_new();
void operation_queue_free(OperationQueue *self);

int operation_queue_get_tiles(OperationQueue *self, TileIndex** tiles_out);

void operation_queue_add(OperationQueue *self, TileIndex index, OperationDataDrawDab *op);
OperationDataDrawDab *operation_queue_pop(OperationQueue *self, TileIndex index);

#endif // OPERATIONQUEUE_H

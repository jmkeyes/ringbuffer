/* ringbuffer.h */
#ifndef RINGBUFFER_H
#define RINGBUFFER_H

struct ringbuffer {
    unsigned long    size;         /**<< Allocated buffer size. */
    unsigned long    read_offset;  /**<< Buffer read index. */
    unsigned long    write_offset; /**<< Buffer write index. */
    unsigned char * storage;       /**<< Data storage area. */
};

int ringbuffer_create(struct ringbuffer **, unsigned long);
int ringbuffer_destroy(struct ringbuffer *);

int ringbuffer_flush(struct ringbuffer *, char);

long ringbuffer_fill_count(struct ringbuffer *);
long ringbuffer_free_count(struct ringbuffer *);

long ringbuffer_write_memory(struct ringbuffer *, void *, unsigned long);
long ringbuffer_read_memory(struct ringbuffer *, void *, unsigned long);

long ringbuffer_write_fd(struct ringbuffer *, int, unsigned long);
long ringbuffer_read_fd(struct ringbuffer *, int, unsigned long);

#endif /* RINGBUFFER_h */
/* EOF */

#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <cstddef>
#include <vector>

class LRUCache
{
public:
  struct line_t
  {
    int key;
    int value;
    struct line_t *next;
    struct line_t *prev;

    line_t(int k, int v):key(k),value(v),next(NULL),prev(NULL) {}
  };

  LRUCache (int capcaity);

  int get(int key);
  void set(int key, int value);
  void update_way_list(line_t *blk);

private:
  /* data */
  line_t * head;
  line_t * tail;
};

#endif /* LRU_CACHE_H */

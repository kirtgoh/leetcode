#include "solution.h"

LRUCache::LRUCache(int capcaity):head(NULL),tail(NULL)
{
  for (size_t i = 0; i < capcaity; i++)
  {
    line_t *blk = new line_t(0,0);
    blk->next = head;
    blk->prev = NULL;
    
    if (!head && !tail) {
      tail = blk;
      head = blk;
    } else {
      head->prev = blk;
      head = blk;
    }
  }
  
}

int LRUCache::get(int key)
{
  line_t *blk = head;
  while(blk)
  {
    if (blk->key == key)
    {
      update_way_list(blk);
      return blk->value;
    }
    blk = blk->next;
  }

  return -1;
}

void LRUCache::set(int key, int value)
{
  line_t *blk = head;
  while(blk)
  {
    if (blk->key == key)
    {
      update_way_list(blk);
      blk->value = value;
      return;
    }
    blk = blk->next;
  }
  tail->key = key;
  tail->value = value;
  update_way_list(tail);
}
void LRUCache::update_way_list(line_t *blk)
{
  if (!blk->prev && !blk->next)
    return;
  else if (!blk->prev)
    return;
  else if (!blk->next)
  {
    tail = blk->prev;
    blk->prev->next = NULL;
  }
  else
  {
    blk->prev->next = blk->next;
    blk->next->prev = blk->prev;
  }
  blk->next = head;
  blk->prev = NULL;
  head->prev = blk;
  head = blk;
}


/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 05, 2014
 *  Problem:     	LRU Cache
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/lru-cache/
 *
 *  Notes:
 *  Design and implement a data structure for Least Recently Used (LRU) cache.
 *  It should support the following operations: get and set. 
 *
 *  get(key) - Get the value (will always be positive) of the key if the key
 *  exists in the cache, otherwise return -1.
 *
 *  set(key, value) - Set or insert the value if the key is not already present.
 *  When the cache reached its capacity, it should invalidate the least recently
 *  used item before inserting a new item. 
 * 	
 *  Solution: 		
*********************************************************************************/

#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <unordered_map>

using namespace std;

struct CacheBlock {
  int key;
  int value;
  CacheBlock(int k, int v): key(k), value(v) {}
};

class LRUCache{
public:
  LRUCache(int capacity);

  int get(int key);
  void set(int key, int value);

private:
  list<CacheBlock> cachelist;
  unordered_map<int, list<CacheBlock>::iterator> hash;
  size_t size;
};

LRUCache::LRUCache(int capacity): size(capacity)
{
}

int LRUCache::get(int key)
{
  if (hash.find(key) != hash.end())
  {
    cachelist.splice(cachelist.begin(), cachelist, hash[key]);
    hash[key] = cachelist.begin();
    return hash[key]->value;
  }
  else
  {
    return -1;
  }
}

void LRUCache::set(int key, int value)
{
  if (hash.find(key) != hash.end())
  {
    cachelist.splice(cachelist.begin(), cachelist, hash[key]);
    hash[key] = cachelist.begin();
    hash[key]->value = value;
  }
  else
  {
    if (size == cachelist.size())
    {
      hash.erase(cachelist.back().key);
      cachelist.pop_back();
    }
    cachelist.push_front(CacheBlock(key,value));
    hash[key] = cachelist.begin();
  }
}

#endif /* LRU_CACHE_H */

#include <singlelist.h>
// #include <string>

void SingleList::buildList(ListNode *&p, std::istream &in)
{
  std::string str;
  in >> str;

  // NOTE: Not first, otherwise extra TreeNode will create
  if (in.eof()) return;

  int i = atoi(str.c_str());
  p = new ListNode(i);
  buildList(p->next,in);
}


void SingleList::printList(ListNode *head)
{
  while(head)
  {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << std::endl;
}

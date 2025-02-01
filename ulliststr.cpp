#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if (!tail_ || tail_->last == ARRSIZE) {
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 0;
    
    if (tail_) {
      tail_->next = newItem;
      newItem->prev = tail_;
    }
    tail_ = newItem;
    if (!head_) {
      head_ = tail_;
    }
  }
  
  tail_->val[tail_->last++] = val;
  ++size_;
}

void ULListStr::pop_back() {
  if (empty()) {
    throw std::runtime_error("List is empty");
  }

  --tail_->last;
  --size_;

  if (tail_->first == tail_->last) {  // If node is empty, delete it
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }
    delete temp;
  }
}

void ULListStr::push_front(const std::string& val) {
  if (!head_ || head_->first == 0) {
    Item* newItem = new Item();
    newItem->first = ARRSIZE;
    newItem->last = ARRSIZE;
    
    if (head_) {
      head_->prev = newItem;
      newItem->next = head_;
    }
    head_ = newItem;
    if (!tail_) {
      tail_ = head_;
    }
  }

  head_->val[--head_->first] = val;
  ++size_;
}

void ULListStr::pop_front() {
  if (empty()) {
    throw std::runtime_error("List is empty");
  }

  ++head_->first;
  --size_;

  if (head_->first == head_->last) {  // If node is empty, delete it
    Item* temp = head_;
    head_ = head_->next;
    if (head_) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const {
  if (empty()) {
    throw std::runtime_error("List is empty");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  if (empty()) {
    throw std::runtime_error("List is empty");
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return nullptr; // Out of bounds
  }

  Item* current = head_;
  size_t index = 0;

  while (current) {
    size_t count = current->last - current->first;
    if (loc < index + count) {
      return &current->val[current->first + (loc - index)];
    }
    index += count;
    current = current->next;
  }

  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

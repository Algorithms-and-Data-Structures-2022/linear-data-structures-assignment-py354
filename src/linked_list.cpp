#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {

    // эквивалентно очистке списка
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    size_ += 1;
    if (front_ == nullptr) {
      front_ = new Node(value);
      back_ = front_;
    } else {
      back_->next = new Node(value);
      back_ = back_->next;
    }
  }

  bool LinkedList::Insert(int index, int value) {
    if (index == size_) {
      Add(value);
      return true;
    }

    if (index == 0) {
      Node* new_node = new Node(value, front_);
      front_ = new_node;
      size_ += 1;
      return true;
    }

    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (i + 1 == index) {
        Node* new_node = new Node(value, node->next);
        node->next = new_node;
        size_ += 1;
        return true;
      }

      node = node->next;
    }

    return false;
  }

  bool LinkedList::Set(int index, int new_value) {
    if (index < 0 || index >= size_) {
      return false;
    }

    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (i == index) {
        node->value = new_value;
        return true;
      }
      node = node->next;
    }

    return false;
  }

  std::optional<int> LinkedList::Remove(int index) {
    if (index < 0 || index >= size_) {
      return std::nullopt;
    }

    if (index == 0) {
      Node deleted = *front_;
      delete front_;
      front_ = deleted.next;
      size_ -= 1;
      return deleted.value;
    }

    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (i + 1 == index) {
        if (index == size_ - 1) {
          back_ = node;
        }

        Node deleted = *node->next;
        delete node->next;
        node->next = deleted.next;
        size_ -= 1;
        return deleted.value;
      }

      node = node->next;
    }
    return std::nullopt;
  }

  void LinkedList::Clear() {
    Node* node = front_;
    while (node != nullptr) {
      Node* next = node->next;
      delete node;
      node = next;
    }
    size_ = 0;
    front_ = nullptr;
    back_ = nullptr;
  }

  std::optional<int> LinkedList::Get(int index) const {
    if (index < 0 || index >= size_) {
      return std::nullopt;
    }

    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (i == index) {
        return node->value;
      }
      node = node->next;
    }

    return std::nullopt;
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    Node* node = front_;
    int index = 0;
    while (node != nullptr) {
      if (node->value == value) {
        return index;
      }
      index += 1;
      node = node->next;
    }

    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    Node* node = front_;
    while (node != nullptr) {
      if (node->value == value) {
        return true;
      }
      node = node->next;
    }

    return false;
  }

  bool LinkedList::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    if (front_ == nullptr) {
      return std::nullopt;
    }

    return front_->value;
  }

  std::optional<int> LinkedList::back() const {
    if (back_ == nullptr) {
      return std::nullopt;
    }

    return back_->value;
  }

  Node* LinkedList::FindNode(int index) const {
    if (index < 0 || index >= size_) {
      return nullptr;
    }

    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (i == index) {
        return node;
      }
      node = node->next;
    }

    return nullptr;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedList::toVector() const {

    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment
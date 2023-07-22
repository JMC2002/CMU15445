//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_k_replacer.cpp
//
// Identification: src/buffer/lru_k_replacer.cpp
//
// Copyright (c) 2015-2022, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "buffer/lru_k_replacer.h"
#include "common/exception.h"

namespace bustub {

LRUKReplacer::LRUKReplacer(size_t num_frames, size_t k) : replacer_size_(num_frames), k_(k) {}

auto LRUKReplacer::Evict(frame_id_t *frame_id) -> bool { 
    std::scoped_lock lock(latch_);
                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    return false; 
}

void LRUKReplacer::RecordAccess(frame_id_t frame_id, [[maybe_unused]] AccessType access_type) {}

void LRUKReplacer::SetEvictable(frame_id_t frame_id, bool set_evictable) {
  std::scoped_lock lock(latch_);
  // 当有修改时才变更evict_size
  if (node_store_.count(frame_id) && set_evictable != node_store_[frame_id]->IsEvictable()) {
      evict_size_ += set_evictable ? 1 : -1;
      node_store_[frame_id]->SetEvictable(set_evictable);
  }
}

void LRUKReplacer::Remove(frame_id_t frame_id) { 
    std::scoped_lock lock(latch_);

}
auto LRUKReplacer::Size() -> size_t { return evict_size_; }
}  // namespace bustub
auto f() {
  int tmp = 1;
  const auto &v1 = tmp;
  auto v2 = v1;
  decltype(v1) v3 = v1;
  decltype((v1)) v4 = v1;
  decltype((v1)) v5 = v1 + v2;
}

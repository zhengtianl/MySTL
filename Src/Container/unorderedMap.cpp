//
// Created by StarkLu on 2023/3/11.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
namespace MySTL {
    template<typename Key, typename Value, typename Hash = std::hash<Key>>
    class unorderedMap {
    public:
        using key_type = Key;
        using mapped_type = Value;
        using value_type = std::pair<const key_type, mapped_type>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using hasher = Hash;

        class iterator {
        public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = unorderedMap::value_type;
            using difference_type = std::ptrdiff_t;
            using pointer = value_type *;
            using reference = value_type &;

            iterator() = default;

            iterator(typename std::vector<std::list<value_type>>::iterator bucket,
                     typename std::list<value_type>::iterator pos)
                    : bucket_(bucket), pos_(pos) {}

            reference operator*() const {
                return *pos_;
            }

            pointer operator->() const {
                return &(*pos_);
            }

            iterator &operator++() {
                ++pos_;
                if (pos_ == bucket_->end()) {
                    ++bucket_;
                    while (bucket_ != map_ptr_->buckets_.end() && bucket_->empty()) {
                        ++bucket_;
                    }
                    if (bucket_ != map_ptr_->buckets_.end()) {
                        pos_ = bucket_->begin();
                    }
                }
                return *this;
            }

            iterator operator++(int) {
                auto copy = *this;
                ++(*this);
                return copy;
            }

            friend bool operator==(const iterator &lhs, const iterator &rhs) {
                return lhs.bucket_ == rhs.bucket_ && lhs.pos_ == rhs.pos_;
            }

            friend bool operator!=(const iterator &lhs, const iterator &rhs) {
                return !(lhs == rhs);
            }

        private:
            unorderedMap *map_ptr_;
            typename std::vector<std::list<value_type>>::iterator bucket_;
            typename std::list<value_type>::iterator pos_;
        };


        // unordered_map的构造
        // Constructor
        unorderedMap() = default;

        explicit unorderedMap(size_type bucket_count) : buckets_(bucket_count) {}

        unorderedMap(std::initializer_list<value_type> init) : unorderedMap() {
            for (const auto &value: init) {
                insert(value);
            }
        }

        unorderedMap(const unorderedMap &other) : unorderedMap() {
            for (const auto &value: other) {
                insert(value);
            }
        }

        unorderedMap(unorderedMap &&other) noexcept:
                buckets_(std::move(other.buckets_)) {}

        // Destructor
        ~unorderedMap() = default;

        // Member functions
        std::pair<iterator, bool> insert(const value_type &value) {
            const auto hash_value = hash_(value.first);
            auto &bucket = buckets_[hash_value % buckets_.size()];
            const auto pos = std::find_if(bucket.begin(), bucket.end(),
                                          [&](const value_type &item) { return item.first == value.first; });
            if (pos != bucket.end()) {
                return {iterator(buckets_.begin(), pos), false};
            }
            bucket.emplace_back(value);
            ++count_;
            return {iterator(buckets_.begin(), bucket.begin()), true};
        }

        iterator find(const key_type &key) {
            const auto hash_value = hash_(key);
            auto &bucket = buckets_[hash_value % buckets_.size()];
            const auto pos = std::find_if(bucket.begin(), bucket.end(),
                                          [&](const value_type &item) { return item.first == key; });
            if (pos != bucket.end()) {
                return iterator(buckets_.begin(), pos);
            }
            return end();
        }

        iterator begin() {
            if (empty()) {
                return end();
            }
            return iterator(buckets_.begin(), buckets_.front().begin());
        }

        iterator end() {
            return iterator(buckets_.end(), buckets_.back().end());
        }

        bool empty() const {
            return count_ == 0;
        }

        size_type size() const {
            return count_;
        }

    private:
        std::vector<std::list<value_type>> buckets_;
        size_type count_{};
        hasher hash_{};
    };
}


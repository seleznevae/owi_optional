#ifndef OWI_OPTIONAL
#define OWI_OPTIONAL

#include <optional>
#include <type_traits>

namespace owi
{
    using nullopt_t = std::nullopt_t;
    inline constexpr nullopt_t nullopt { std::nullopt };

    template <typename Tp>
    class optional : public std::optional<Tp>
    {
    private:
        using base_optional = std::optional<Tp>;

        template <typename it_value_type>
        class iterator_template {
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = it_value_type;
            using pointer           = value_type *;
            using reference         = value_type &;

            constexpr iterator_template() noexcept = default;
            constexpr explicit iterator_template(Tp *ptr) noexcept : ptr_(ptr) { }

            reference operator*() const { return *ptr_; }

            pointer operator->() const { return ptr_; }

            friend bool operator==(const iterator_template & lhs, const iterator_template & rhs)
            {
                return lhs.ptr_ == rhs.ptr_;
            }
            friend bool operator!=(const iterator_template & lhs, const iterator_template & rhs)
            {
                return !(lhs == rhs);
            }

            iterator_template& operator++() {
                ptr_ = nullptr;
                return *this;
            }

            iterator_template operator++(int) {
                iterator_template old{ptr_};
                ptr_ = nullptr;
                return old;
            }

            operator iterator_template<const value_type>() const
            {
                return { ptr_ };
            }

        private:
            Tp *ptr_{nullptr};
        };

    public:
        template <typename ...Ts>
        optional(Ts&& ...args): base_optional(std::forward<Ts>(args)...)
        {
        }

        using iterator = iterator_template<Tp>;
        using const_iterator = iterator_template<const Tp>;

        iterator begin() noexcept 
        {
            return this->has_value() ? iterator{&(**this)} : iterator{nullptr};
        }

        const_iterator cbegin() const noexcept
        {
            return begin();
        }

        iterator end() noexcept
        {
            return iterator{nullptr};
        }

        const_iterator cend() const noexcept
        {
            return end();
        }
    };

    // `make_optional` group of functions.
    template <typename Tp>
    constexpr std::enable_if_t<std::is_constructible_v<std::decay_t<Tp>, Tp>, optional<std::decay_t<Tp>>>
    make_optional(Tp&& t)
    noexcept(std::is_nothrow_constructible_v<optional<std::decay_t<Tp>>, Tp>)
    { 
        return optional<std::decay_t<Tp>>{ std::forward<Tp>(t) }; 
    }

    template <typename Tp, typename... Args>
    constexpr std::enable_if_t<std::is_constructible_v<Tp, Args...>, optional<Tp>>
    make_optional(Args&&... args)
    noexcept(std::is_nothrow_constructible_v<Tp, Args...>)
    { 
        return std::optional<Tp>{ std::in_place, std::forward<Args>(args)... }; 
    }
    
    template <typename Tp, typename Up, typename... Args>
    constexpr std::enable_if_t<std::is_constructible_v<Tp, std::initializer_list<Up>&, Args...>, optional<Tp>>
    make_optional(std::initializer_list<Up> il, Args&&... args)
    noexcept(std::is_nothrow_constructible_v<Tp, std::initializer_list<Up>&, Args...>)
    { 
        return optional<Tp>{ std::in_place, il, std::forward<Args>(args)... }; 
    }
} // namespace owi

#endif // OWI_OPTIONAL
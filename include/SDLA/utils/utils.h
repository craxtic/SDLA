#pragma once

#include <utility>

/// unrolling helper function
template <std::size_t N, typename F>
constexpr void static_loop_unroll(F &&op_func) noexcept {

  [&]<std::size_t... Is>(std::index_sequence<Is...>){
    (std::forward<F>(op_func)(Is), ...);
  }(std::make_index_sequence<N>{});

  return;
}